/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 19:39:50 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/04/03 21:30:23 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	token_loop_sq(t_ms **ms, size_t *i)
{
	if ((*ms)->n_cmd[*i] && (*ms)->n_cmd[*i] == '\'')
		(*i)++;
	while ((*ms)->n_cmd[*i] && (*ms)->n_cmd[*i] != '\'')
	{
		if ((*ms)->n_cmd[*i] && (*ms)->n_cmd[*i] == '$')
			(*ms)->not_expand2 = 1;
		(*i)++;
	}
	if ((*ms)->n_cmd[*i] && (*ms)->n_cmd[*i] == '\'')
		(*i)++;
	if ((*ms)->n_cmd[*i] && (*ms)->n_cmd[*i] == ' ')
		return (1);
	else if (!(*ms)->n_cmd[*i])
		return (1);
	return (0);
}

int	token_loop_dq(t_ms **ms, size_t *i)
{
	if ((*ms)->n_cmd[*i] && (*ms)->n_cmd[*i] == '"')
		(*i)++;
	while ((*ms)->n_cmd[*i] && (*ms)->n_cmd[*i] != '"')
		(*i)++;
	if ((*ms)->n_cmd[*i] && (*ms)->n_cmd[*i] == '"')
		(*i)++;
	if ((*ms)->n_cmd[*i] && (*ms)->n_cmd[*i] == ' ')
		return (1);
	else if (!(*ms)->n_cmd[*i])
		return (1);
	return (0);
}

void	token_loop(t_ms **ms, size_t i, size_t j)
{
	j = i;
	(*ms)->not_expand2 = 0;
	while ((*ms)->n_cmd[i] && (*ms)->n_cmd[i] == ' ')
	{
		j++;
		i++;
	}
	while ((*ms)->n_cmd[i])
	{
		if ((*ms)->n_cmd[i] != ' ' && (*ms)->n_cmd[i] != '\'' && \
		(*ms)->n_cmd[i] != '"')
			i++;
		if ((*ms)->n_cmd[i] == ' ')
			break ;
		if ((*ms)->n_cmd[i] == '\'')
			if (token_loop_sq(ms, &i))
				break ;
		if ((*ms)->n_cmd[i] == '"')
			if (token_loop_dq(ms, &i))
				break ;
	}
	add_to_token(i, j, ms);
	if ((*ms)->n_cmd[i])
		token_loop(ms, i, 0);
}

void	get_token(t_ms **ms)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	(*ms)->token = NULL;
	token_loop(ms, i, j);
	free((*ms)->n_cmd);
}
