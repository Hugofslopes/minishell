/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_b2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:42:24 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/04/07 13:37:56 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ck_echo(char *str, t_ms **ms)
{
	char	*str2;

	str2 = ft_strtrim_start(str, "echo");
	if (str2 && str2[0] != '\0')
		return (free(str2), (*ms)->exit_status = 127, \
		ft_put_error(ERROR_CMD_, "%s", str), 1);
	return (free(str2), 0);
}

int	ck_export(char *str, t_ms **ms)
{
	char	*str2;

	str2 = ft_strtrim_start(str, "export");
	if (str2 && str2[0] != '\0')
		return (free(str2), (*ms)->exit_status = 127, \
		ft_put_error(ERROR_CMD_, "%s", str), 1);
	return (free(str2), 0);
}

int	ck_env(char *str, t_ms **ms)
{
	char	*str2;

	str2 = ft_strtrim_start(str, "env");
	if (str2 && str2[0] != '\0')
		return (free(str2), (*ms)->exit_status = 127, \
		ft_put_error(ERROR_CMD_, "%s", str), 1);
	return (free(str2), 0);
}

int	ck_pwd(char *str, t_ms **ms)
{
	char	*str2;

	str2 = ft_strtrim_start(str, "pwd");
	if (str2 && str2[0] != '\0')
		return (free(str2), (*ms)->exit_status = 127, \
		ft_put_error(ERROR_CMD_, "%s", str), 1);
	return (free(str2), 0);
}

int	ck_cd(char *str, t_ms **ms)
{
	char	*str2;

	str2 = ft_strtrim_start(str, "cd");
	if (str2 && str2[0] != '\0')
		return (free(str2), (*ms)->exit_status = 127, \
		ft_put_error(ERROR_CMD_, "%s", str), 1);
	return (free(str2), 0);
}
