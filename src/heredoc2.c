/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 08:53:49 by pbranco-          #+#    #+#             */
/*   Updated: 2025/04/07 14:38:49 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	get_eof2(t_ms **ms, char **e_o_f)
{
	if ((*ms)->h.split_cmd[1] == NULL)
		*(e_o_f) = ft_strtrim((*ms)->h.split_cmd[0], " ");
	else
	{
		(*ms)->h.split2 = ft_split((*ms)->h.split_cmd[1], ' ');
		if ((*ms)->h.split2[1] == NULL)
			*(e_o_f) = ft_strtrim((*ms)->h.split_cmd[1], " ");
		else
			*(e_o_f) = ft_strtrim((*ms)->h.split2[0], " ");
	}
}

void	control_d(t_ms **ms, char *e_o_f, size_t i, size_t j)
{
	char	*str;

	ft_put_error(ERROR_HERE, "%s", e_o_f);
	free(e_o_f);
	if (ft_strchr((*ms)->h.n_str2, '\n'))
	{
		str = malloc(sizeof(char) * ft_strlen((*ms)->h.n_str2 + 1));
		while ((*ms)->h.n_str2[i] && (*ms)->h.n_str2[i] != '\n')
			i++;
		while ((*ms)->h.n_str2[i])
			str[j++] = (*ms)->h.n_str2[i++];
		str[j] = '\0';
		free((*ms)->h.n_str2);
		(*ms)->h.n_str2 = str;
	}
	if ((*ms)->h.split_cmd && (*ms)->h.split_cmd[0])
		(*ms)->h.n_str = ft_strjoin((*ms)->h.split_cmd[0], (*ms)->h.n_str2);
	else
		control_d_command(ms);
	free((*ms)->h.n_str2);
	(*ms)->h.n_str2 = ft_strdup((*ms)->h.n_str);
	free_controld(ms);
	process_redirects2((*ms)->h.n_str2, ms);
}

void	remove_quotes_heredoc3_0(char *cmd, t_ms **ms, size_t *i, char *str)
{
	if (cmd[*i] == '<')
		str[((*ms)->j)++] = cmd[(*i)++];
	while (cmd[*i] == ' ')
		str[((*ms)->j)++] = cmd[(*i)++];
	if (cmd[*i] == '\'')
	{
		(*ms)->h_found = 1;
		(*i)++;
	}
	else if (cmd[*i] == '"')
	{
		(*ms)->h_found = 2;
		(*i)++;
	}
	if ((*ms)->h_found == 1)
		while (cmd[*i] && cmd[*i] != '\'')
			str[((*ms)->j)++] = cmd[(*i)++];
	else if ((*ms)->h_found == 2)
		while (cmd[*i] && cmd[*i] != '"')
			str[((*ms)->j)++] = cmd[(*i)++];
	else
		while (cmd[*i] && cmd[*i] != ' ')
			str[((*ms)->j)++] = cmd[(*i)++];
}

char	*remove_quotes_heredoc2(char *cmd, t_ms **ms, char *str, size_t i)
{
	(*ms)->j = 0;
	while (cmd[i])
	{
		if (cmd[i] == '<')
			remove_quotes_heredoc3_0(cmd, ms, &i, str);
		if (cmd[i])
			str[((*ms)->j)++] = cmd[i++];
	}
	str[((*ms)->j)] = '\0';
	return (str);
}

char	*remove_quotes_heredoc(char *cmd, t_ms **ms)
{
	char	*str;
	size_t	i;

	if (ft_strchr(cmd, '\'') != NULL || ft_strchr(cmd, '"') != NULL)
	{
		str = malloc(sizeof(char) * (ft_strlen(cmd) + 1));
		i = 0;
		str = remove_quotes_heredoc2(cmd, ms, str, i);
	}
	else
		str = ft_strdup(cmd);
	return (str);
}
