/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 01:47:17 by adylewsk          #+#    #+#             */
/*   Updated: 2021/06/30 20:39:17 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	init_map(t_map *map, t_components *components)
{
	map->len.x = 0;
	map->len.y = 0;
	map->tab = NULL;
	components->P.pos.x = -1;
	components->P.pos.y = -1;
	components->C.pos.x = -1;
	components->C.pos.y = -1;
	components->E.pos.x = -1;
	components->E.pos.y = -1;
}

// t_map	init_comp(t_map map, void *mlx)
// {
// 	map.P.img.img = mlx_xpm_file_to_image(mlx, );
// }
