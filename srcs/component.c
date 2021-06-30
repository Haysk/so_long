/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   component.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 17:42:04 by adylewsk          #+#    #+#             */
/*   Updated: 2021/06/29 19:21:12 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	add_comp(t_pos *comp, int x, int y)
{
	if (comp->x >= 0 || comp->y >= 0)
		return (FALSE);
	comp->x = x;
	comp->y = y;
	return (TRUE);
}
