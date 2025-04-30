/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_errrors2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:43:48 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/04/07 13:38:14 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_dollar_before_eq(char *input, size_t i, size_t j, int found)
{
	char	*input2;

	input2 = malloc(sizeof(char) * (ft_strlen(input) + 1));
	while (input[i] && input[i] != '=')
		input2[j++] = input[i]++;
	input2[j] = '\0';
	i = 0;
	while (input2[i])
	{
		if (input2[i++] == '\'')
		{
			while (input2[i] && input2[i] != '\'')
			{
				if (input2[i] == '$')
					found = 1;
				i++;
			}
		}
	}
	if (found)
		return (ft_put_error(ERROR_EXP_P, "%s", input), free(input2), 1);
	return (free(input2), 0);
}

int	check_dollar_before_eq2(char *input, size_t i, size_t j, int found)
{
	char	*input2;

	input2 = malloc(sizeof(char) * (ft_strlen(input) + 1));
	while (input[i] && input[i] != '=')
		input2[j++] = input[i++];
	input2[j] = '\0';
	i = 0;
	while (input2[i])
	{
		if (input2[i] == '$')
			found = 1;
		i++;
	}
	if (found)
		return (ft_put_error(ERROR_EXP_P, "%s", input), free(input2), 1);
	return (free(input2), 0);
}

int	check_var_content3(char **n_var, t_ms **ms, size_t i, size_t j)
{
	j = 0;
	while ((*ms)->envp[i][j])
	{
		if ((*ms)->envp[i][j++] == '$')
			return (free(*(n_var)), 1);
	}
	return (free(*(n_var)), 0);
}

int	check_var_content2(char *var, t_ms **ms, size_t i)
{
	size_t	j;
	char	*n_var;

	n_var = malloc(sizeof(char) * (ft_strlen(var) + 1));
	j = 0;
	while (var[i] && var[i] != ' ')
		n_var[j++] = var[i++];
	n_var[j] = '\0';
	i = 0;
	j = 0;
	while ((*ms)->envp[i++])
	{
		if (ft_strnstr((*ms)->envp[i], n_var, (ft_strlen(var) - 1)))
		{
			j = 1;
			break ;
		}
	}
	if (j)
		return (check_var_content3(&n_var, ms, i, j));
	return (free(n_var), 0);
}

int	check_var_content(char *var, t_ms **ms, size_t i, size_t j)
{
	(void) j;
	while (var[i] && var[i] != '$')
		i++;
	if (var[i] && var[i] == '$')
		return (check_var_content2(var, ms, i + 1));
	else
		return (0);
	return (0);
}
