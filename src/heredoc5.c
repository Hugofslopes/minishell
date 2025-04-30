/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 10:30:41 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/04/09 11:49:02 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	get_i_char(size_t *i, char **str2)
{
	while (str2[1][*i] && str2[1][*i] != ' ')
	{
		if (str2[1][*i] && str2[1][*i] == '\'')
		{
			(*i)++;
			while (str2[1][*i] && str2[1][*i] != '\'')
				(*i)++;
			if (str2[1][*i] && str2[1][*i] == '\'')
				(*i)++;
			if (!str2[1][*i])
				break ;
		}
		if (str2[1][*i] && str2[1][*i] == '"')
		{
			(*i)++;
			while (str2[1][*i] && str2[1][*i] != '"')
				(*i)++;
			if (str2[1][*i] && str2[1][*i] == '"')
				(*i)++;
			if (!str2[1][*i])
				break ;
		}
		if (str2[1][*i] != '\'' && str2[1][*i] == '"')
			(*i)++;
	}
}

char	*get_n_str2_1(char **str2, char *str4, size_t i, size_t j)
{
	str4 = malloc(sizeof(char) * (ft_strlen(str2[1]) + 1));
	while (str2[1][i])
		str4[j++] = str2[1][i++];
	str4[j] = '\0';
	return (str4);
}

char	*get_n_str2_2(char **str2, char **str3, char *str4, char **str5)
{
	size_t	j;

	j = 2;
	free(*str3);
	str4 = ft_strjoin(*str5, str2[j++]);
	free(*str5);
	while (str2[j])
	{
		*str3 = ft_strjoin(str4, str2[j++]);
		free(str4);
		str4 = ft_strdup(*str3);
		free(*str3);
		j++;
	}
	return (str4);
}

void	get_n_str2(char *cmd, t_ms **ms, size_t i, size_t j)
{
	char	**str2;
	char	*str3;
	char	*str4;
	char	*str5;

	str2 = ft_split(cmd, '<');
	str3 = ft_strdup(str2[0]);
	str4 = NULL;
	while (str2[1][i] && str2[1][i] == ' ')
		(i)++;
	get_i_char(&i, str2);
	if (str2[1][i])
		str4 = get_n_str2_1(str2, str4, i, j);
	if (str4)
	{
		str5 = ft_strjoin(str3, str4);
		free(str4);
	}
	else
		str5 = str3;
	if (str2[2])
		(*ms)->h.n_str2 = get_n_str2_2(str2, &str3, str4, &str5);
	else
		(*ms)->h.n_str2 = str3;
	ft_free(str2);
}

void	control_d_command(t_ms **ms)
{
	char	**str;

	str = ft_split((*ms)->cmd, '<');
	(*ms)->h.n_str = ft_strjoin(str[0], (*ms)->h.n_str2);
	ft_free(str);
}
