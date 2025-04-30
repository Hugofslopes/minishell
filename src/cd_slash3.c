/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_slash3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:40:44 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/04/03 10:36:16 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*check_it_has_more2(char **input2, size_t i)
{
	char	*str;
	char	*str2;

	str = ft_strdup("/");
	while (input2[i])
	{
		str2 = ft_strjoin(str, input2[i]);
		free(str);
		str = ft_strjoin(str2, "/");
		free(str2);
		i++;
	}
	return (str);
}

char	*check_it_has_more(char *input)
{
	size_t	i;
	char	**input2;
	char	*str;

	i = 0;
	input2 = ft_split(input, '/');
	while (input2[i])
		i++;
	i--;
	if (ft_strncmp(input2[i], "..", 2) != 0)
	{
		while (ft_strcmp(input2[i], "..") != 0)
			i--;
		if (ft_strcmp(input2[i], "..") == 0)
			i++;
		str = check_it_has_more2(input2, i);
		ft_free(input2);
		return (str);
	}
	ft_free(input2);
	return (ft_strdup("/"));
}
