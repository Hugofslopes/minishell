/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander_dlc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 08:06:58 by pbranco-          #+#    #+#             */
/*   Updated: 2025/04/14 08:11:29 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	expander_s_quotes(char *cmd, t_ms **ms, int type, int *i)
{
	char	*tmp;

	(*ms)->cmd_exp_tmp = ft_strcjoin(&(*ms)->cmd_exp_tmp, '\'');
	tmp = ft_get_s_quotes(cmd + (*i));
	if (type == 0)
		(*ms)->cmd_exp_tmp = ft_strjoin_gnl(&(*ms)->cmd_exp_tmp, tmp);
	else
		make_ex_nd(tmp, ms, 1);
	(*i) += ft_strlen(tmp);
	ft_free_gnl(&tmp);
	(*ms)->cmd_exp_tmp = ft_strcjoin(&(*ms)->cmd_exp_tmp, '\'');
	if (cmd[(*i) + 1] == '\'')
		(*i)++;
}

void	expander_d_quotes(char *cmd, t_ms **ms, int *i)
{
	char	*tmp;

	(*ms)->cmd_exp_tmp = ft_strcjoin(&(*ms)->cmd_exp_tmp, '"');
	tmp = ft_get_d_quotes(cmd + (*i));
	make_ex_nd(tmp, ms, 1);
	(*i) += ft_strlen(tmp);
	ft_free_gnl(&tmp);
	(*ms)->cmd_exp_tmp = ft_strcjoin(&(*ms)->cmd_exp_tmp, '"');
	if (cmd[(*i) + 1] == '"')
		(*i)++;
}

void	expander_is_special(char *cmd, t_ms **ms, int *i)
{
	if (!is_special_character(cmd[(*i)]))
		(*ms)->cmd_exp_tmp = ft_strcjoin(&(*ms)->cmd_exp_tmp, cmd[(*i)]);
}

void	expander_isnt_special(char *cmd, t_ms **ms, int *i)
{
	if (!is_special_character(cmd[(*i)]))
		(*ms)->cmd_exp_tmp = ft_strcjoin(&(*ms)->cmd_exp_tmp, cmd[(*i)]);
}
