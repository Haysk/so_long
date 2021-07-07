/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilib.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 20:20:38 by adylewsk          #+#    #+#             */
/*   Updated: 2021/07/07 01:56:46 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	*window_set(t_mlx *mlx, t_map map)
{
	int	screenx;
	int	screeny;

	mlx_get_screen_size(mlx->ptr, &screenx, &screeny);
	if (screenx < map.lenx * 50 || screeny < map.leny * 50)
		return (NULL);
	mlx->win.lenx = map.lenx * 50;
	mlx->win.leny = map.leny * 50;
	return (mlx_new_window(mlx->ptr, mlx->win.lenx, mlx->win.leny, "so_long"));

}

void	images_set(t_data *data, t_images *imgs)
{
	imgs->bg.img = mlx_new_image(data->mlx.ptr, data->mlx.win.lenx,
					data->mlx.win.leny);
	imgs->bg.addr = (int *)mlx_get_data_addr(imgs->bg.img, &imgs->bg.bits_per_pixel,
					&imgs->bg.line_length, &imgs->bg.endian);
	imgs->w.img = mlx_xpm_file_to_image(data->mlx.ptr, "sprites/wall.xpm",
					&imgs->w.with, &imgs->w.height);
	imgs->w.addr = (int *)mlx_get_data_addr(imgs->w.img, &imgs->w.bits_per_pixel,
					&imgs->w.line_length, &imgs->w.endian);
	imgs->s.img = mlx_xpm_file_to_image(data->mlx.ptr, "sprites/space.xpm",
					&imgs->s.with, &imgs->s.height);
	imgs->s.addr = (int *)mlx_get_data_addr(imgs->s.img, &imgs->s.bits_per_pixel,
					&imgs->s.line_length, &imgs->s.endian);
	imgs->p.img = mlx_xpm_file_to_image(data->mlx.ptr, "sprites/perso.xpm",
					&imgs->p.with, &imgs->p.height);
	imgs->p.addr = (int *)mlx_get_data_addr(imgs->p.img, &imgs->p.bits_per_pixel,
					&imgs->p.line_length, &imgs->p.endian);
	imgs->c.img = mlx_xpm_file_to_image(data->mlx.ptr, "sprites/collect.xpm",
					&imgs->c.with, &imgs->c.height);
	imgs->c.addr = (int *)mlx_get_data_addr(imgs->c.img, &imgs->c.bits_per_pixel,
					&imgs->c.line_length, &imgs->c.endian);
	imgs->e.img = mlx_xpm_file_to_image(data->mlx.ptr, "sprites/exit.xpm",
					&imgs->e.with, &imgs->e.height);
	imgs->e.addr = (int *)mlx_get_data_addr(imgs->e.img, &imgs->e.bits_per_pixel,
					&imgs->e.line_length, &imgs->e.endian);
}

void	img_to_bg(t_image *img, t_image *bg, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < img->height)
	{
		j = 0;
		while (j < img->with)
		{
			if (img->addr[i * img->line_length / 4 + j] > 0)
				bg->addr[(i + y) * bg->line_length / 4 + (j + x)] = img->addr[i * img->line_length / 4 + j];
			j++;
		}
		i++;
	}
}

int	map_display(t_data *data, t_images *imgs)
{
	int		y;
	int		x;

	y = 0;
	while (data->map.tab[y])
	{
		x = 0;
		while (data->map.tab[y][x])
		{	
			if (data->map.tab[y][x] == '1')
				img_to_bg(&imgs->w, &imgs->bg, x * 50, y * 50);
			else
				img_to_bg(&imgs->s, &imgs->bg, x * 50, y * 50);
			if (y == data->comps.p.y && x == data->comps.p.x)
				img_to_bg(&imgs->p, &imgs->bg, x * 50, y * 50);
			else if (y == data->comps.c.y && x == data->comps.c.x)
				img_to_bg(&imgs->c, &imgs->bg, x * 50, y * 50);
			else if (y == data->comps.e.y && x == data->comps.e.x)
				img_to_bg(&imgs->e, &imgs->bg, x * 50, y * 50);
			x++;
		}
		y++;
	}
	return (1);
}

int	start(t_data *data)
{
	t_images	imgs;
	
	data->mlx.win.ptr = window_set(&data->mlx, data->map);
	images_set(data, &imgs);
	if (data->mlx.win.ptr == NULL)
		close_data(data, 6, 0);
	map_display(data, &imgs);
	// img_to_bg(&imgs.p, &imgs.bg, 150, 100);
	mlx_put_image_to_window(data->mlx.ptr, data->mlx.win.ptr,
	imgs.bg.img, 0, 0);
	mlx_loop(data->mlx.ptr);
	mlx_destroy_image(data->mlx.ptr, imgs.w.img);
	mlx_destroy_image(data->mlx.ptr, imgs.s.img);
	mlx_destroy_image(data->mlx.ptr, imgs.p.img);
	mlx_destroy_image(data->mlx.ptr, imgs.bg.img);
	mlx_destroy_window(data->mlx.ptr, data->mlx.win.ptr);
	return (TRUE);
}
