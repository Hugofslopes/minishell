/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 10:30:41 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/04/07 12:58:00 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	e_o_f_quotes3(char *cmd, char **cmd2, size_t *i, size_t *j)
{
	if (cmd[*i] && cmd[*i] != '\'' && cmd[*i] != '"')
	{
		(*i)++;
		while (cmd[*i] && cmd[*i] != '\'' && cmd[*i] != '"' )
			(*cmd2)[(*j)++] = cmd[(*i)++];
		if (cmd[*i] && cmd[*i] == ' ')
			return (1);
	}
	if (cmd[*i] == '"')
	{
		(*i)++;
		while (cmd[*i] && cmd[*i] != '"')
			(*cmd2)[(*j)++] = cmd[(*i)++];
		if (cmd[*i] && cmd[*i] == '"')
			(*i)++;
		if (cmd[*i] && cmd[*i] == ' ')
			return (1);
	}
	return (0);
}

void	e_o_f_quotes2(char *cmd, char **cmd2, size_t i, size_t j)
{
	while (cmd[i])
	{
		if (cmd[i] == '\'')
		{
			i++;
			while (cmd[i] && cmd[i] != '\'')
			{
				(*cmd2)[j++] = cmd[i++];
			}
			if (cmd[i] && cmd[i] == '\'')
				i++;
			if ((cmd[i] && cmd[i] == ' ') || !cmd[i])
				break ;
		}
		if (e_o_f_quotes3(cmd, cmd2, &i, &j))
			break ;
	}
	(*cmd2)[j] = '\0';
}

void	get_i_heredoc(char *cmd, size_t *i)
{
	while (cmd[*i])
	{
		if (cmd[*i] && cmd[*i] == '"')
		{
			(*i)++;
			while (cmd[*i] && cmd[*i] != '"')
				(*i)++;
			if (cmd[*i] == '"')
				(*i)++;
			if (cmd[*i] && cmd[*i] == ' ')
				break ;
		}
		else if (cmd[*i] && cmd[*i] == '\'')
		{
			(*i)++;
			while (cmd[*i] && cmd[*i] != '\'')
				(*i)++;
			if (cmd[*i] == '\'')
				(*i)++;
			if (cmd[*i] && cmd[*i] == ' ')
				break ;
		}
	}
}

int	e_o_f_quotes(char *command, t_ms **ms)
{
	char	**spt;
	char	*cmd;
	char	*cmd2;
	size_t	i;
	size_t	j;

	spt = ft_split(command, '<');
	cmd = ft_strdup(spt[1]);
	ft_free(spt);
	cmd2 = malloc(sizeof(char) * (ft_strlen(cmd) + 1));
	i = 0;
	j = 0;
	e_o_f_quotes2(cmd, &cmd2, i, j);
	(*ms)->e_o_f = cmd2;
	(*ms)->h_found = 1;
	return (free(cmd), 1);
}
