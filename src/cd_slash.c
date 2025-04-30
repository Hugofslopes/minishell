/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_slash.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:41:31 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/04/04 19:52:26 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	cd_slash3(char *new_input, t_ms **ms)
{
	char	*pwd;
	char	*oldpwd;

	free((*ms)->oldpwd);
	(*ms)->oldpwd = ft_strdup((*ms)->pwd);
	if (search_pwd(ms, 0) || (*ms)->cd == 1)
	{
		oldpwd = ft_strjoin("export OLDPWD=", (*ms)->oldpwd);
		handle_export(oldpwd, ms);
		free(oldpwd);
	}
	free((*ms)->pwd);
	(*ms)->pwd = ft_strdup(new_input);
	chdir((*ms)->pwd);
	if (search_pwd(ms, 1))
	{
		pwd = ft_strjoin("export PWD=", new_input);
		handle_export(pwd, ms);
		free(pwd);
	}
}

void	cd_slash2(char *new_input2, t_ms **ms)
{
	DIR		*new_dir;

	new_dir = opendir(new_input2);
	if (new_dir != NULL)
		cd_slash3(new_input2, ms);
	else
	{
		ft_putstr_fd("minishell: cd: ", 2);
		ft_putstr_fd(new_input2, 2);
		perror(" ");
		(*ms)->exit_status = 1;
	}
	closedir(new_dir);
	free(new_input2);
}

char	*cd_slash4(char *input, t_ms **ms)
{
	char	*new_input;
	char	*new_input2;

	if (ft_strstr(input, "..") != NULL)
		new_input2 = cd_slash_dots(input, ms);
	else if (ft_strchr(input, '~') != NULL)
	{
		new_input = ft_strtrim(input, "~");
		new_input2 = ft_strjoin((*ms)->home, new_input);
		free(new_input);
	}
	else
	{
		new_input = ft_strjoin((*ms)->pwd, "/");
		new_input2 = ft_strjoin(new_input, input);
		free(new_input);
	}
	return (new_input2);
}

char	*get_newpwd(char *input, t_ms **ms)
{
	char	*str;
	char	*str2;

	str = ft_strjoin((*ms)->pwd, "/");
	str2 = ft_strjoin(str, input);
	free(str);
	return (str2);
}

void	cd_slash(char *input, t_ms **ms)
{
	char	*oldpwd;
	char	*pwd;

	while (*input == ' ')
		input++;
	chdir(input);
	free((*ms)->oldpwd);
	(*ms)->oldpwd = ft_strdup((*ms)->pwd);
	free((*ms)->pwd);
	(*ms)->pwd = getcwd(NULL, 0);
	if (search_pwd(ms, 0) || (*ms)->cd == 1)
	{
		oldpwd = ft_strjoin("export OLDPWD=", (*ms)->oldpwd);
		handle_export(oldpwd, ms);
		free(oldpwd);
	}
	if (search_pwd(ms, 1))
	{
		pwd = ft_strjoin("export PWD=", (*ms)->pwd);
		handle_export(pwd, ms);
		free(pwd);
	}
}
