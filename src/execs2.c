/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execs2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:42:30 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/04/03 14:52:39 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	remove_quotes_execute2(char *cmd, size_t *i, size_t *j, char **str)
{
	(*i)++;
	while (cmd[*i] && cmd[*i] != '"')
		(*str)[(*j)++] = cmd[(*i)++];
	if (cmd[*i] == '"')
		(*i)++;
}

void	remove_quotes_execute1(char *cmd, size_t *i, size_t *j, char **str)
{
	(*i)++;
	while (cmd[*i] && cmd[*i] != '\'')
		(*str)[(*j)++] = cmd[(*i)++];
	if (cmd[*i] == '\'')
		(*i)++;
}

char	*remove_quotes_execute(char *cmd, t_ms **ms)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = malloc(sizeof(char) * (ft_strlen(cmd) + 1));
	i = 0;
	j = 0;
	while (cmd[i])
	{
		if (cmd[i] && cmd[i] == '\'')
		{
			(*ms)->has_quotes = 1;
			remove_quotes_execute1(cmd, &i, &j, &str);
		}
		if (cmd[i] && cmd[i] == '"')
		{
			(*ms)->has_quotes = 1;
			remove_quotes_execute2(cmd, &i, &j, &str);
		}
		if (cmd[i] && cmd[i] != '\'' && cmd[i] != '"')
			str[j++] = cmd[i++];
	}
	str[j] = '\0';
	return (str);
}

void	empty_command(char *command, t_ms **ms)
{
	ft_put_error(ERROR_CMD_, "%s", command);
	(*ms)->exit_status = 127;
}
