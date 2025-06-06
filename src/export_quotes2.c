/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_quotes2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:44:45 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/04/06 10:24:31 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	add_with_s_qt2(t_ms **ms, size_t h, char *n_input)
{
	n_input[h] = '\0';
	n_input = putbar(n_input);
	if (check_dollar_before_eq2(n_input, 0, 0, 0))
		return (free(n_input));
	export_1arg(n_input, ms);
	free(n_input);
}

void	add_with_s_qt(t_ms **ms, size_t i, char *input)
{
	char	*n_input;
	size_t	k;
	size_t	h;

	k = (*ms)->exp_start;
	h = 0;
	n_input = malloc(sizeof(char) * (1 + (i - (*ms)->exp_start)));
	if (input[k] == '\'' || input[k] == '"')
		k++;
	while (input[k] == ' ')
		k++;
	while (k < i)
	{
		if (input[k] == '\'')
			k++;
		n_input[h] = input[k];
		h++;
		k++;
		if (input[k] == '\'' && i - k == 0)
		{
			k++;
			break ;
		}
	}
	add_with_s_qt2(ms, h, n_input);
}

size_t	args_no_equa2l(size_t i, char *input, t_ms **ms, size_t h)
{
	char	*str;
	char	*str2;
	size_t	k;

	k = 0;
	str = malloc(sizeof(char) * (h - i + 1));
	while (input[i] == ' ')
		i++;
	while (input[i] && input[i] != ' ')
		str[k++] = input[i++];
	str[k] = '\0';
	str2 = remove_quotes(str);
	export_1arg(str2, ms);
	free(str2);
	(*ms)->exp_start = i;
	return (i);
}

size_t	args_no_equal(size_t i, char *input, t_ms **ms)
{
	size_t	h;

	h = i;
	if (!input)
		return (i);
	if (input[i] == '\0')
		return (i);
	while (input[h] && input[h] == ' ')
		h++;
	while (input[h])
	{
		if (input[h] == ' ')
			break ;
		if (input[h] == '=')
			return (i);
		h++;
	}
	i = args_no_equa2l(i, input, ms, h);
	return (i);
}
