/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_atol.c										  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: pbranco- <pbranco-@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2024/10/15 09:00:00 by pbranco-		  #+#	#+#			 */
/*   Updated: 2024/12/16 08:38:37 by pbranco-		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "libft.h"

long	ft_atol(const char *str)
{
	int		i;
	int		signal;
	long	count;

	i = 0;
	signal = 1;
	count = 0;
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
	if (str[i] > 57 || str[i] == 43 || str[i] == 45)
		return (-2147483649);
	count *= signal;
	return (count);
}
