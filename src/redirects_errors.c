/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects_errors.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 08:53:49 by pbranco-          #+#    #+#             */
/*   Updated: 2025/04/04 09:34:10 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_redir(char *cmd, t_ms **ms)
{
	size_t	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '<' && cmd[i + 1] && cmd[i + 1] == '<' && cmd[i + 2] && \
		(cmd[i + 2] == '<' || cmd[i + 2] == '>'))
		{
			ft_put_error(ERROR_SNTAX, "%s", "<");
			return ((*ms)->exit_status = 2, 0);
		}
		if (cmd[i] == '>' && cmd[i + 1] && cmd[i + 1] == '>' && cmd[i + 2] && \
			(cmd[i + 2] == '<' || cmd[i + 2] == '>'))
		{
			ft_put_error(ERROR_SNTAX, "%s", ">");
			return ((*ms)->exit_status = 2, 0);
		}
		if (cmd[i] == '>' && cmd[i + 1] && cmd[i + 1] == '<')
		{
			ft_put_error(ERROR_SNTAX, "%s", "<");
			return ((*ms)->exit_status = 2, 0);
		}
		i++;
	}
	return (1);
}
