/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_b3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:42:24 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/04/05 14:44:05 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	check_wich_error(char *cmd, size_t i, size_t j, t_ms **ms)
{
	char	*var;

	var = malloc(sizeof(char) * (ft_strlen(cmd) + 1));
	while (cmd[i])
	{
		if (cmd[i] != '$')
			i++;
		else
		{
			while (cmd[i] && cmd[i] != ' ')
				var[j++] = cmd[i++];
			var[j] = '\0';
		}
	}
	if (var[0] == '$' && !var[1])
	{
		ft_put_error(ERROR_CMD_, "%s", var);
		(*ms)->exit_status = 127;
	}
	else
		(*ms)->exit_status = 0;
	free(var);
}
