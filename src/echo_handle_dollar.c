/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_handle_dollar.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pcruz <pcruz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:41:53 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/04/09 10:50:08 by pcruz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	handle_env_var_echo(char *cmd, t_ms **ms)
{
	char	*env_var;

	env_var = get_env_var_value(ms, cmd);
	if (env_var)
	{
		if (env_var[0] == '\\')
			ft_putstr_fd(env_var + 1, STDOUT_FILENO);
		else
			ft_putstr_fd(env_var, STDOUT_FILENO);
		return (free(env_var), 1);
	}
	return (0);
}
