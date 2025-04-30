/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atolli.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbranco- <pbranco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 09:43:55 by pbranco-          #+#    #+#             */
/*   Updated: 2025/04/07 10:49:04 by pbranco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atolli(char *str, int i, int signal, unsigned long long count)
{
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			signal *= -1;
		i++;
	}
	while ((str[i] >= 48 && str[i] <= 57) && str[i] != '\0')
	{
		count *= 10;
		count += str[i] - 48;
		i++;
	}
	if (signal == -1)
	{
		if (count > 9223372036854775808ULL)
			return (1);
	}
	else
	{
		if (count > 9223372036854775807ULL)
			return (1);
	}
	return (0);
}
