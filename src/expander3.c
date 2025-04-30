/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 11:47:31 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/04/14 08:09:18 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	make_ex_nd(char *cmd, t_ms **ms, int type)
{
	int		i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '\'' && count_quotes(cmd + i + 1, '\'') > 0)
			expander_s_quotes(cmd, ms, type, &i);
		else if (cmd[i] == '"' && count_quotes(cmd + i + 1, '"') > 0)
			expander_d_quotes(cmd, ms, &i);
		else if ((cmd[i] == '\'' && count_quotes(cmd + i + 1, '\'') == 0) || \
		(cmd[i] == '"' && count_quotes(cmd + i + 1, '"') > 0))
			(*ms)->cmd_exp_tmp = ft_strcjoin(&(*ms)->cmd_exp_tmp, cmd[i]);
		else if (cmd[i] == '$' && (cmd[i + 1] != '\'' && \
			cmd[i + 1] != '"') && (!ft_isdigit(cmd[i + 1]) || \
			cmd[i + 1] == '0') && cmd[i + 1] > 33)
			handle_dollar_sign_exp(cmd + i, ms, &i);
		else if (!(cmd[i] == '$' && cmd[i + 1] && \
			is_special_character(cmd[i + 1])))
			expander_is_special(cmd, ms, &i);
		else if ((cmd[i] == '$' && cmd[i + 1] && \
			!is_special_character(cmd[i + 1])))
			expander_isnt_special(cmd, ms, &i);
		i++;
	}
}

void	expand_input(t_ms **ms)
{
	make_ex_nd((*ms)->cmd, ms, 0);
	ft_free_gnl(&(*ms)->cmd);
	(*ms)->cmd = ft_strdup_free(&(*ms)->cmd_exp_tmp);
}

void	redirect_type1(t_ms **ms, size_t *i)
{
	if ((*ms)->cmd[*i] == '<')
	{
		expand_input(ms);
		input_redirect(ms, (*ms)->cmd);
	}
	else
	{
		expand_input(ms);
		output_redirect(ms, (*ms)->cmd);
	}
}

int	redirect_no_quotes(t_ms **ms, int redirect_type)
{
	size_t	i;

	i = 0;
	while ((*ms)->cmd)
	{
		redirect_type = is_redirect_operator((*ms)->cmd, i);
		if (redirect_type == 2)
		{
			if ((*ms)->cmd[i] == '<')
				heredoc((*ms)->cmd, ms);
			else
			{
				expand_input(ms);
				output_append(ms, (*ms)->cmd);
			}
			break ;
		}
		else if (redirect_type == 1)
		{
			redirect_type1(ms, &i);
			break ;
		}
		i++;
	}
	return (redirect_type);
}
