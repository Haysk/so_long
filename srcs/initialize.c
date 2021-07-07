/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 01:47:17 by adylewsk          #+#    #+#             */
/*   Updated: 2021/07/07 01:53:14 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	my_mlx_init(t_mlx *mlx)
{
	mlx->win.lenx = 0;
	mlx->win.leny = 0;
	mlx->win.ptr = NULL;
	mlx->ptr = mlx_init();
}

void	map_init(t_map *map)
{
	map->lenx = 0;
	map->leny = 0;
	map->tab = NULL;
	map->imgs = NULL;

}

void	comps_init(t_components *comps)
{
	comps->p.x = -1;
	comps->p.y = -1;
	comps->c.x = -1;
	comps->c.y = -1;
	comps->e.x = -1;
	comps->e.y = -1;
}

void	data_init(t_data *data)
{
	my_mlx_init(&data->mlx);
	map_init(&data->map);
	comps_init(&data->comps);
}
// t_map	init_comp(t_map map, void *mlx)
// {
// 	map.P.img.img = mlx_xpm_file_to_image(mlx, );
// }
