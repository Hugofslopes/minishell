/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 20:06:05 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/04/05 14:40:54 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	add_to_array_token2(char *str, t_ms **ms, size_t i)
{
	char	**n_token;

	i = 0;
	while ((*ms)->token[i])
		i++;
	n_token = malloc(sizeof(char *) * (i + 2));
	i = 0;
	while ((*ms)->token[i])
	{
		n_token[i] = ft_strdup((*ms)->token[i]);
		i++;
	}
	n_token[i++] = str;
	n_token[i] = 0;
	ft_free((*ms)->token);
	(*ms)->token = n_token;
}

void	add_to_array_token(char *str, t_ms **ms, size_t i)
{
	char	**n_token;

	if (!(*ms)->token)
	{
		if (ft_strlen(str) == 0)
		{
			free(str);
			n_token = malloc(sizeof(char *) * 1);
			n_token[0] = 0;
			(*ms)->token = n_token;
		}
		else
		{
			n_token = malloc(sizeof(char *) * 2);
			n_token[0] = str;
			n_token[1] = 0;
			(*ms)->token = n_token;
		}
	}
	else
		add_to_array_token2(str, ms, i);
}

void	add_to_token_qt(size_t *h, size_t *j, t_ms **ms, char **str)
{
	if ((*ms)->n_cmd[*j] == '\'')
	{
		(*j)++;
		while ((*ms)->n_cmd[*j] && (*ms)->n_cmd[*j] != '\'')
			(*str)[(*h)++] = (*ms)->n_cmd[(*j)++];
		if ((*ms)->n_cmd[*j] && (*ms)->n_cmd[*j] == '\'')
			(*j)++;
	}
	if ((*ms)->n_cmd[*j] == '"')
	{
		(*j)++;
		while ((*ms)->n_cmd[*j] && (*ms)->n_cmd[*j] != '"')
			(*str)[(*h)++] = (*ms)->n_cmd[(*j)++];
		if ((*ms)->n_cmd[*j] && (*ms)->n_cmd[*j] == '"')
			(*j)++;
	}
}

void	add_to_token(size_t i, size_t j, t_ms **ms)
{
	char	*str;
	size_t	h;

	h = 0;
	str = malloc(sizeof(char) * (i - j + 1));
	while (j < i)
	{
		if ((*ms)->n_cmd[j] != '"' && (*ms)->n_cmd[j] != '\'')
			str[h++] = (*ms)->n_cmd[j++];
		else
			add_to_token_qt(&h, &j, ms, &str);
	}
	str[h] = '\0';
	if (ft_strchr(str, '$'))
	{
		if (!(*ms)->not_expand2 && !ft_strstr(str, "$?"))
			str = expand_heredoc(ms, 1, str);
		else if (!(*ms)->not_expand2 && ft_strstr(str, "$?"))
		{
			str = get_exit_code_cmd(ms, str, 0, 0);
			if (ft_strchr(str, '$'))
				str = expand_heredoc(ms, 1, str);
		}
	}
	add_to_array_token(str, ms, 0);
}

void	execute2(t_ms **ms, char *path, char *av)
{
	if (!(*ms)->token[0] || ((*ms)->token[0] && !ft_strlen((*ms)->token[0])))
	{
		ft_putstr_fd("Command '' not found\n", 2);
		return ((*ms)->exit_status = 127, ft_free((*ms)->token), free_ms(ms));
	}
	check_dir_and_premissions(ms, av);
	if (execve(path, (*ms)->token, (*ms)->envp) == -1)
	{
		ft_put_error(ERROR_CMD_, "%s", (*ms)->token[0]);
		(*ms)->exit_status = 127;
		ft_free((*ms)->token);
		free(av);
		av = NULL;
		free_ms(ms);
	}
}
