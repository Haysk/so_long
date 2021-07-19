/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilib_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 20:20:38 by adylewsk          #+#    #+#             */
/*   Updated: 2021/07/19 18:52:14 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

int	display_map(t_data *data)
{	
	char	*str;

	str = ft_itoa(data->moves);
	if (data->imgs.bg.img)
	{
		mlx_destroy_image(data->mlx, data->imgs.bg.img);
		data->imgs.bg.img = NULL;
	}
	data->imgs.bg.img = mlx_new_image(data->mlx, data->width,
			data->heigth);
	data->imgs.bg.addr = (int *)mlx_get_data_addr(data->imgs.bg.img,
			&data->imgs.bg.bits_per_pixel, &data->imgs.bg.line_length,
			&data->imgs.bg.endian);
	set_bg(data);
	mlx_put_image_to_window(data->mlx, data->win,
		data->imgs.bg.img, 0, 0);
	mlx_string_put(data->mlx, data->win, 10, 20, 0xFFFFFF, str);
	if (str)
		free(str);
	return (0);
}

int	keypress(int key, t_data *data)
{
	int	move;

	move = 0;
	if (key == 119)
		move = move_perso(data, 0, -1);
	else if (key == 115)
		move = move_perso(data, 0, 1);
	else if (key == 97)
		move = move_perso(data, -1, 0);
	else if (key == 100)
		move = move_perso(data, 1, 0);
	else if (key == 65307)
		exit(my_error(close_mlx(data, 99), "CLOSE"));
	if (move == 1)
	{
		data->moves += 1;
		ft_printf("%i\n", data->moves);
		move_enemies(data);
		display_map(data);
	}
	return (0);
}

int	close_so_long(t_data *data)
{
	exit(my_error(close_mlx(data, 99), "CLOSE"));
}

int	start(t_data *data)
{
	data->mlx = mlx_init();
	data->win = window_set(data);
	images_set(data, &data->imgs);
	mlx_do_sync(data->mlx);
	mlx_loop_hook(data->mlx, display_map, data);
	mlx_hook(data->win, 33, 1L << 5, close_so_long, data);
	mlx_hook(data->win, 2, 1L << 0, keypress, data);
	mlx_loop(data->mlx);
	return (TRUE);
}
