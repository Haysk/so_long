/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   component.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 17:42:04 by adylewsk          #+#    #+#             */
/*   Updated: 2021/07/07 01:52:47 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	add_comp(t_pos *pos, int x, int y)
{
	if (pos->x >= 0 || pos->y >= 0)
		return (FALSE);
	pos->x = x;
	pos->y= y;
	return (TRUE);
}
