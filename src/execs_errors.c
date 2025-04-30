/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execs_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:42:37 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/04/07 10:03:00 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	isdir(char *input)
{
	DIR		*new_dir;
	int		check;

	check = 0;
	new_dir = opendir(input);
	if (new_dir != NULL)
		check++;
	closedir(new_dir);
	return (check);
}

void	print_error(char *cmd, size_t i)
{
	char	*str;
	size_t	j;

	j = 0;
	str = malloc(sizeof(char) * ft_strlen(cmd));
	while (cmd[i] && (cmd[i] == ' ' || cmd[i] == '\t'))
		i++;
	while (cmd[i])
	{
		if (cmd[i] && cmd[i] == '\'')
		{
			i++;
			while (cmd[i] && (cmd[i] == ' ' || cmd[i] == '\t'))
				str[j++] = cmd[i++];
			break ;
		}
		else if (cmd[i] && cmd[i] == '"')
		{
			i++;
			while (cmd[i] && (cmd[i] == ' ' || cmd[i] == '\t'))
				str[j++] = cmd[i++];
			break ;
		}
	}
	return (str[j] = '\0', ft_put_error(ERROR_CMD_, "%s", str), free(str));
}

int	execs_error3(char *cmd, size_t i)
{
	i++;
	if (cmd[i] && cmd[i] == '"')
		return (print_empty(), 1);
	while (cmd[i] && (cmd[i] == ' ' || cmd[i] == '\t'))
		i++;
	if (cmd[i] != '"')
		return (0);
	if (cmd[i] == '"')
		return (print_error(cmd, 0), 1);
	return (1);
}

int	execs_error2(char *cmd, size_t i)
{
	while (cmd[i])
	{
		while (cmd[i] && (cmd[i] == ' ' || cmd[i] == '\t'))
			i++;
		if (cmd[i] && cmd[i] == '\'')
		{
			i++;
			if (cmd[i] && cmd[i] == '\'')
				return (print_empty(), 1);
			while (cmd[i] && (cmd[i] == ' ' || cmd[i] == '\t'))
				i++;
			if (cmd[i] != '\'')
				return (0);
			if (cmd[i] == '\'')
				return (print_error(cmd, 0), 1);
		}
		else if (cmd[i] && cmd[i] == '"')
			return (execs_error3(cmd, i));
		else
			break ;
	}
	return (0);
}

int	execs_error(char *command, t_ms **ms)
{
	struct stat	sfile_stat;

	if (ft_strchr(command, '/') != NULL)
	{
		if (isdir(command) && ft_strchr(command, '/') != NULL)
		{
			ft_put_error(ERROR_IS_DIR, "%s", command);
			(*ms)->exit_status = 126;
			return (1);
		}
	}
	if (stat(command, &sfile_stat) == 0)
	{
		if (access(command, X_OK) < 0 && access(command, R_OK) < 0)
		{
			ft_put_error(ERROR_PERMS, "%s", command);
			(*ms)->exit_status = 126;
			return (1);
		}
	}
	if (execs_error2(command, 0))
		return ((*ms)->exit_status = 127, 1);
	return (0);
}
