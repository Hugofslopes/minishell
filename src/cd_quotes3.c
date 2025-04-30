/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_quotes3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 10:34:30 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/04/03 10:35:12 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	cd_quotes_n2_1(t_ms **ms)
{
	char	*tmp;

	if (search_pwd(ms, 0) || (*ms)->cd == 1)
	{
		tmp = ft_strjoin("export OLDPWD=", (*ms)->oldpwd);
		handle_export(tmp, ms);
		free(tmp);
	}
	if (search_pwd(ms, 1))
	{
		tmp = ft_strjoin("export PWD=", (*ms)->pwd);
		handle_export(tmp, ms);
		free(tmp);
	}
}

void	cd_quotes_n2(char *str, t_ms **ms)
{
	char	*str2;
	int		i;

	str2 = ft_strtrim_start(str, "cd ");
	free(str);
	i = chdir(str2);
	if (i != 0)
		return (ft_put_error(ERROR_CDN, "%s", str2), free(str2));
	free(str2);
	str2 = getcwd(NULL, 0);
	free((*ms)->oldpwd);
	(*ms)->oldpwd = ft_strdup((*ms)->pwd);
	free((*ms)->pwd);
	(*ms)->pwd = str2;
	cd_quotes_n2_1(ms);
}

int	cd_quotes_n1(char *input, size_t *i, char **str, size_t *j)
{
	if (input[*i] == '\'')
	{
		(*i)++;
		while (input[*i] && input[*i] != '\'')
			(*str)[(*j)++] = input[(*i)++];
		if (input[*i] == '\'')
			(*i)++;
		return (1);
	}
	if (input[*i] == '"')
	{
		(*i)++;
		while (input[*i] && input[*i] != '"')
			(*str)[(*j)++] = input[(*i)++];
		if (input[*i] == '"')
			(*i)++;
		return (1);
	}
	return (0);
}

void	cd_quotes_n(char *input, t_ms **ms)
{
	size_t	i;
	size_t	j;
	char	*str;

	str = malloc(sizeof(char) * ft_strlen(input) + 1);
	i = 0;
	j = 0;
	while (input[i])
	{
		cd_quotes_n1(input, &i, &str, &j);
		if (input[i])
			str[j++] = input[i++];
	}
	while (input[i])
		str[j++] = input[i++];
	str[j] = '\0';
	cd_quotes_n2(str, ms);
}
