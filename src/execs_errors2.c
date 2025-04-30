/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execs_errors2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 11:55:07 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/04/09 11:41:05 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	print_empty(void)
{
	char	*str;

	str = ft_strdup("Command '' not found\n");
	ft_putstr_fd(str, 2);
	free(str);
}

int	check_if_is_bt(char *cmd, t_ms **ms)
{
	char	*str;

	str = remove_quotes_execute(cmd, ms);
	if (!ft_strstr(str, "export") && !ft_strstr(str, "echo") && \
	!ft_strstr(str, "env") && !ft_strstr(str, "exit") && \
	!ft_strstr(str, "pwd") && !ft_strstr(str, "cd"))
		return (free(str), 0);
	return (free(str), 1);
}
