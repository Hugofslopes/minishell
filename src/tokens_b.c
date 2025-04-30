/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokens_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:42:24 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/04/07 13:38:37 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ck_unset(char *str, t_ms **ms)
{
	char	*str2;

	str2 = ft_strtrim_start(str, "unset");
	if (str2 && str2[0] != '\0')
		return (free(str2), (*ms)->exit_status = 127, \
		ft_put_error(ERROR_CMD_, "%s", str), 1);
	return (free(str2), 0);
}

int	ck_exit(char *str, t_ms **ms)
{
	char	*str2;

	str2 = ft_strtrim_start(str, "exit");
	if (str2 && str2[0] != '\0')
		return (free(str2), (*ms)->exit_status = 127, \
		ft_put_error(ERROR_CMD_, "%s", str), 1);
	return (free(str2), 0);
}

int	errors_builtins2(t_ms **ms)
{
	if ((*ms)->token[0])
	{
		if (ft_strstr((*ms)->token[0], "echo"))
			return (ck_echo((*ms)->token[0], ms));
		else if (ft_strstr((*ms)->token[0], "cd"))
			return (ck_cd((*ms)->token[0], ms));
		else if (ft_strstr((*ms)->token[0], "exit"))
			return (ck_exit((*ms)->token[0], ms));
		else if (ft_strstr((*ms)->token[0], "pwd"))
			return (ck_pwd((*ms)->token[0], ms));
		else if (ft_strstr((*ms)->token[0], "export"))
			return (ck_export((*ms)->token[0], ms));
		else if (ft_strstr((*ms)->token[0], "unset"))
			return (ck_unset((*ms)->token[0], ms));
		else if (ft_strstr((*ms)->token[0], "env"))
			return (ck_env((*ms)->token[0], ms));
	}
	else
		return (2);
	return (0);
}

void	get_new_command(t_ms **ms)
{
	char	*str;
	char	*str2;
	size_t	i;

	i = 1;
	str = ft_strjoin((*ms)->token[0], " ");
	while ((*ms)->token[i])
	{
		str2 = ft_strjoin(str, (*ms)->token[i]);
		free(str);
		str = ft_strjoin(str2, " ");
		free(str2);
		i++;
	}
	(*ms)->cmd_exp = str;
}

int	errors_builtins(char **command, char***commandsplit, t_ms **ms)
{
	int		i;

	(*ms)->cmd_changed = 0;
	(*ms)->n_cmd = ft_strdup(*command);
	get_token(ms);
	i = errors_builtins2(ms);
	if (i == 1 || i == 2)
		*commandsplit = NULL;
	if (i == 2)
		return (check_wich_error(*command, 0, 0, ms), ft_free((*ms)->token),
			(*ms)->token = NULL, 1);
	if (i == 0 && ft_strchr(*command, '$') && (ft_strstr((*ms)->token[0], \
	"echo") || ft_strstr((*ms)->token[0], "export") || \
	ft_strstr((*ms)->token[0], "env") || ft_strstr((*ms)->token[0], "cd") || \
	ft_strstr((*ms)->token[0], "unset") || ft_strstr((*ms)->token[0], \
	"exit") || ft_strstr((*ms)->token[0], "pwd")) && \
	!ft_strstr(*command, "echo") && !ft_strstr(*command, "exit") && \
	!ft_strstr(*command, "env") && !ft_strstr(*command, "export") && \
	!ft_strstr(*command, "pwd") && !ft_strstr(*command, "cd") && \
	!ft_strstr(*command, "unset"))
	{
		get_new_command(ms);
		(*ms)->cmd_changed = 1;
	}
	return (ft_free((*ms)->token), (*ms)->token = NULL, i);
}
