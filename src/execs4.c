/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execs4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 10:31:58 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/04/04 14:22:25 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	execute_with_qt2(char *av, t_ms **ms)
{
	char	**cmd;
	char	*path;

	cmd = malloc(sizeof(char *) * 2);
	cmd[0] = ft_strdup(av);
	cmd[1] = 0;
	path = get_path(cmd[0], (*ms)->envp);
	if (!path)
		path = av;
	if (execve(path, cmd, (*ms)->envp) == -1)
	{
		ft_put_error(ERROR_CMD_, "%s", av);
		ft_free(cmd);
		(*ms)->exit_status = 127;
		if (!ft_strcmp(av, path))
			ft_free_gnl(&path);
		else
		{
			ft_free_gnl(&path);
			ft_free_gnl(&av);
		}
		free_ms(ms);
	}
	ft_free_gnl(&av);
	ft_free_gnl(&path);
}

void	execute_with_qt(char *command, t_ms **ms)
{
	pid_t	pid;
	int		status;
	int		i;
	int		j;

	i = 0x7F;
	j = 0xFF;
	status = 0;
	(*ms)->has_quotes = 1;
	pid = fork();
	if (pid == -1)
		perror("fork");
	else if (!pid)
		execute_with_qt2(command, ms);
	else
		waitpid(pid, &status, 0);
	if (status & j)
		(*ms)->exit_status = status & i;
	else
		(*ms)->exit_status = (status >> 8) & j;
}

void	execute_d_quotes(t_ms **ms, char *str)
{
	char	*firstcmd;

	firstcmd = ft_get_d_quotes(str);
	execute_with_qt(firstcmd, ms);
	ft_free_gnl(&firstcmd);
}

void	execute_s_quotes(t_ms **ms, char *str)
{
	char	*firstcmd;

	firstcmd = ft_get_s_quotes(str);
	execute_with_qt(firstcmd, ms);
	ft_free_gnl(&firstcmd);
}
