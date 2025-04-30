/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:43:05 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/04/03 13:24:14 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*get_path(char *cmd, char **envp)
{
	char	**full_path;
	char	*half_path;
	char	*path;
	int		i;

	i = 0;
	if (!envp[i])
		return (NULL);
	while (envp[i] && ft_strnstr(envp[i], "PATH=", 5) == 0)
		i++;
	if (!envp[i] || ft_strnstr(envp[i], "PATH=", 5) == 0)
		return (NULL);
	full_path = ft_split(envp[i] + 5, ':');
	i = 0;
	while (full_path[i])
	{
		half_path = ft_strjoin(full_path[i], "/");
		path = ft_strjoin(half_path, cmd);
		free(half_path);
		if (access(path, F_OK | X_OK) == 0)
			return (ft_free(full_path), path);
		free(path);
		i++;
	}
	return (ft_free(full_path), NULL);
}

int	check_space_end(char *f_cmd)
{
	if (f_cmd[ft_strlen(f_cmd) - 1] == ' ')
		return (1);
	return (0);
}

char	**join_path_if_need2(char **cmd, int found, char **n_cmd, size_t i)
{
	char	*str2;
	char	*str;

	n_cmd[0] = ft_strdup(cmd[0]);
	str = ft_strjoin(cmd[1], " ");
	while (cmd[i])
	{
		str2 = ft_strjoin(str, cmd[i]);
		free(str);
		i++;
		if (cmd[i])
			str = ft_strjoin(str2, " ");
	}
	if (found)
	{
		str = ft_strjoin(str2, " ");
		free(str2);
		str2 = str;
	}
	n_cmd[1] = str2;
	n_cmd[2] = 0;
	ft_free(cmd);
	return (n_cmd);
}

char	**join_path_if_need(char **cmd, char *f_cmd, t_ms **ms)
{
	int		found;
	char	**n_cmd;
	size_t	i;

	if ((*ms)->has_quotes)
	{
		i = 0;
		found = check_space_end(f_cmd);
		while (cmd[i])
			i++;
		i = 2;
		if (cmd[1] && cmd[2])
		{
			n_cmd = malloc(sizeof(char *) * (i + 1));
			return (join_path_if_need2(cmd, found, n_cmd, i));
		}
	}
	return (cmd);
}
