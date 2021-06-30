/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 01:47:17 by adylewsk          #+#    #+#             */
/*   Updated: 2021/06/29 18:32:27 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

t_map	init_map(void)
{
	t_map	map;

	map.len.x = 0;
	map.len.y = 0;
	map.P.x = -1;
	map.P.y = -1;
	map.C.x = -1;
	map.C.y = -1;
	map.E.x = -1;
	map.E.y = -1;
	map.tab = NULL;
	return (map);
}
