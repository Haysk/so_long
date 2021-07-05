/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   component.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 17:42:04 by adylewsk          #+#    #+#             */
/*   Updated: 2021/06/30 20:36:12 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	add_comp(t_comp *comp, int x, int y)
{
	if (comp->pos.x >= 0 || comp->pos.y >= 0)
		return (FALSE);
	comp->pos.x = x;
	comp->pos.y= y;
	return (TRUE);
}
