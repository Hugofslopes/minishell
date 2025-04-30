/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_from_execs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hfilipe- <hfilipe-@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 10:42:24 by hfilipe-          #+#    #+#             */
/*   Updated: 2025/04/04 19:55:00 by hfilipe-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_from_exe(t_ms**ms, char ***commandsplit)
{
	if ((*ms)->check_inpt)
		ft_free(*commandsplit);
	if ((*ms)->cmd_changed)
		free((*ms)->cmd_exp);
}
