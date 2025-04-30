/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:43:33 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/04/06 12:03:16 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	realoc_and_export(char **input, size_t i, size_t j, t_ms **ms)
{
	char	**n_var;

	while (input[j])
		j++;
	n_var = malloc(sizeof(char *) * j);
	i++;
	j = 0;
	while (input[i])
		n_var[j++] = input[i++];
	n_var[j] = 0;
	if (n_var[0] != 0)
		handle_export2(n_var, ms);
	else
		free(n_var);
}
