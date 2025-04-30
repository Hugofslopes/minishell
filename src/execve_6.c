/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execve_6.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 20:06:05 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/04/05 14:41:30 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*get_exit_code_cmd3(char *str, char *str2, char **str3)
{
	if (str2[0] != '\0')
	{
		str = ft_strjoin(*str3, str2);
		free(*str3);
	}
	else
		str = *str3;
	return (str);
}

char	*get_exit_code_cmd2(char *str, size_t i, char *str4, char *str2)
{
	char	*str3;
	size_t	j;

	if (str2[0] != '\0')
	{
		str3 = ft_strjoin(str2, str4);
		free(str4);
	}
	else
		str3 = str4;
	free(str2);
	if (str[i] == '$' && str[i + 1] && str[i + 1] == '?')
		i += 2;
	str2 = malloc(sizeof(char) * (ft_strlen(str) + 1));
	j = 0;
	while (str[i])
		str2[j++] = str[i++];
	str2[j] = '\0';
	free(str);
	str = NULL;
	str = get_exit_code_cmd3(str, str2, &str3);
	free(str2);
	return (str);
}

char	*get_exit_code_cmd(t_ms **ms, char *str, size_t i, size_t j)
{
	char	*str2;
	char	*str4;

	str2 = malloc(sizeof(char) * (ft_strlen(str) + 1));
	while (str[i])
	{
		if (str[i] == '$' && str[i + 1] && str[i + 1] == '?')
			break ;
		else
			str2[j++] = str[i++];
	}
	str2[j] = '\0';
	str4 = ft_itoa((*ms)->exit_status);
	str = get_exit_code_cmd2(str, i, str4, str2);
	if ((ft_strstr(str, "$?")))
		return (get_exit_code_cmd(ms, str, 0, 0));
	return (str);
}

void	check_dir_and_premissions2(t_ms **ms, char *av)
{
	if (ft_strstr((*ms)->token[0], "./"))
	{
		if (access((*ms)->token[0], F_OK) == 0)
		{
			if (access((*ms)->token[0], X_OK) != 0)
			{
				ft_put_error(ERROR_PERMS, "%s", (*ms)->token[0]);
				(*ms)->exit_status = 126;
				ft_free((*ms)->token);
				free(av);
				free_ms(ms);
			}
		}
	}
}

void	check_dir_and_premissions(t_ms **ms, char *av)
{
	DIR	*dir;

	dir = opendir((*ms)->token[0]);
	if (ft_strstr((*ms)->token[0], "/") && dir)
	{
		closedir(dir);
		ft_put_error(ERROR_IS_DIR, "%s", (*ms)->token[0]);
		(*ms)->exit_status = 126;
		ft_free((*ms)->token);
		free(av);
		free_ms(ms);
	}
	closedir(dir);
	check_dir_and_premissions2(ms, av);
}
