/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 08:53:49 by pbranco-          #+#    #+#             */
/*   Updated: 2025/04/09 11:49:01 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*check_other_redir(char *str)
{
	size_t	i;
	char	*str2;

	str2 = malloc(sizeof(char) * (ft_strlen(str) + 1));
	i = 0;
	while (str[i])
	{
		str2[i] = str[i];
		i++;
		if (str[i] == '<' || str[i] == '>')
			break ;
	}
	str2[i] = '\0';
	free(str);
	return (str2);
}

int	is_redirect_operator(char *str, int i)
{
	if (str[i] == '>' || str[i] == '<')
	{
		if (str[i + 1] == str[i])
			return (2);
		if (i > 0)
		{
			if ((str[i] == '>' && str[i - 1] == '-') \
			|| (str[i] == '>' && str[i - 1] == '='))
				return (0);
		}
		return (1);
	}
	return (0);
}

int	handle_redi(char *command_trim, t_ms **ms, int redirect_type)
{
	if (!redirect_quotes(command_trim))
		return (0);
	redirect_type = redirect_no_quotes(ms, redirect_type);
	return (redirect_type);
}

void	process_redirects(char *command, t_ms **ms)
{
	int		redirect_type;

	redirect_type = 0;
	if (!check_redir(command, ms))
		return ;
	(*ms)->cmd = ft_strtrim(command, " ");
	redirect_type = handle_redi((*ms)->cmd, ms, redirect_type);
	if (redirect_type == 0)
	{
		make_ex_nd((*ms)->cmd, ms, 0);
		ft_free_gnl(&(*ms)->cmd);
		if ((*ms)->cmd_exp_tmp)
		{
			(*ms)->cmd = ft_strdup_free(&(*ms)->cmd_exp_tmp);
			(*ms)->cmd = ft_strtrim_free(&(*ms)->cmd, " ");
			choose_builtin((*ms)->cmd, ms);
		}
	}
	if ((*ms)->cmd)
	{
		ft_free_gnl(&(*ms)->cmd);
	}
}
