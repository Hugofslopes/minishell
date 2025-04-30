/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execs3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 10:33:53 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/04/03 13:26:49 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	remove_quotes_execute_exp2(char *cmd, size_t *i, size_t *j, char **str)
{
	(*i)++;
	while (cmd[*i] && cmd[*i] != '\'')
		(*str)[(*j)++] = cmd[(*i)++];
	if (cmd[*i] == '\'')
		(*i)++;
}

char	*remove_quotes_execute_exp(char *cmd, size_t i, t_ms **ms)
{
	size_t	j;
	char	*str;

	j = 0;
	str = malloc(sizeof(char) * (ft_strlen(cmd + 1)));
	while (cmd[i])
	{
		if (cmd[i] == '\'')
		{
			(*ms)->has_quotes = 1;
			remove_quotes_execute_exp2(cmd, &i, &j, &str);
		}
		else if (cmd[i] && cmd[i] == '"')
		{
			(*ms)->has_quotes = 1;
			while (cmd[i] && cmd[i] != '"')
				str[j++] = cmd[i++];
			if (cmd[i] == '"')
				i++;
		}
		if ((cmd[i] && cmd[i] != '"') && cmd[i] != '\'')
			str[j++] = cmd[i++];
	}
	str[j] = '\0';
	return (str);
}
