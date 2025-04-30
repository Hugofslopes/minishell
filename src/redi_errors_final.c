/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redi_errors_final.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 10:10:29 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/04/04 10:18:30 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*ft_ct_st(char **str, char c)
{
	(*str) = malloc(sizeof(char) * 2);
	(*str)[0] = c;
	(*str)[1] = '\0';
	return ((*str));
}
