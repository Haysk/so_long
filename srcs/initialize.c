/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 01:47:17 by adylewsk          #+#    #+#             */
/*   Updated: 2021/07/09 16:36:20 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	data_init(t_data *data)
{	
	data->mlx = NULL;
	data->win = NULL;
	data->width = 0;
	data->heigth = 0;
	data->moves = 0;
	data->map.lenx = 0;
	data->map.leny = 0;
	data->map.tab = NULL;
	data->comps.p = 0;
	data->comps.c = 0;
	data->comps.e = 0;
	data->imgs.c.img = NULL;
	data->imgs.e.img = NULL;
	data->imgs.p.img = NULL;
	data->imgs.s.img = NULL;
	data->imgs.w.img = NULL;
	data->imgs.bg.img = NULL;
}

void	get_addr(t_images *imgs)
{
	imgs->w.addr = (int *)mlx_get_data_addr(imgs->w.img,
			&imgs->w.bits_per_pixel, &imgs->w.line_length, &imgs->w.endian);
	imgs->s.addr = (int *)mlx_get_data_addr(imgs->s.img,
			&imgs->s.bits_per_pixel, &imgs->s.line_length, &imgs->s.endian);
	imgs->p.addr = (int *)mlx_get_data_addr(imgs->p.img,
			&imgs->p.bits_per_pixel, &imgs->p.line_length, &imgs->p.endian);
	imgs->c.addr = (int *)mlx_get_data_addr(imgs->c.img,
			&imgs->c.bits_per_pixel, &imgs->c.line_length, &imgs->c.endian);
	imgs->e.addr = (int *)mlx_get_data_addr(imgs->e.img,
			&imgs->e.bits_per_pixel, &imgs->e.line_length, &imgs->e.endian);
}

void	images_set(t_data *data, t_images *imgs)
{
	imgs->w.img = mlx_xpm_file_to_image(data->mlx, "sprites/wall.xpm",
			&imgs->w.with, &imgs->w.height);
	imgs->s.img = mlx_xpm_file_to_image(data->mlx, "sprites/space.xpm",
			&imgs->s.with, &imgs->s.height);
	imgs->p.img = mlx_xpm_file_to_image(data->mlx, "sprites/perso anim.xpm",
			&imgs->p.with, &imgs->p.height);
	imgs->c.img = mlx_xpm_file_to_image(data->mlx, "sprites/collect.xpm",
			&imgs->c.with, &imgs->c.height);
	imgs->e.img = mlx_xpm_file_to_image(data->mlx, "sprites/exit.xpm",
			&imgs->e.with, &imgs->e.height);
	if (!data->imgs.w.img || !data->imgs.s.img || !data->imgs.p.img
		|| !data->imgs.c.img || !data->imgs.e.img)
		exit(my_error(close_mlx(data, 0), NULL));
	get_addr(imgs);
}

void	*window_set(t_data *data)
{
	int	screenx;
	int	screeny;

	mlx_get_screen_size(data->mlx, &screenx, &screeny);
	if (screenx < data->map.lenx * 50 || screeny < data->map.leny * 50)
		exit(my_error(close_mlx(data, 7), NULL));
	data->width = data->map.lenx * 50;
	data->heigth = data->map.leny * 50;
	return (mlx_new_window(data->mlx, data->width, data->heigth, "so_long"));
}
