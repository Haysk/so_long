/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilib.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 20:20:38 by adylewsk          #+#    #+#             */
/*   Updated: 2021/06/30 20:39:56 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

// int	init_components(t_components components)
// {
// 	char	*perso;
// 	char	*collect;
// 	char	*exit;
// 	char	*space;
// 	char	*wall;


// 	return (TRUE);
// }

int	start()
{
	void	*mlx;
	void	*mlx_win;
	char	*relative_path = "/home/adylewsk/Project/WIP/so_long/sprites/perso.xpm";
	// int		img_width;
	// int		img_height;
	t_data	img;
	t_data	perso;
	int		x;
	int		y;

	x = 0;
	y = 0;
	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "so_long");
	perso.img = mlx_xpm_file_to_image(mlx, relative_path, &perso.with, &perso.height);
	if (perso.img)
	{
		perso.addr = (int *)mlx_get_data_addr(perso.img, &perso.bits_per_pixel, &perso.line_length, 
							&perso.endian);
	}
	img.img = mlx_new_image(mlx, 1920, 1080);
	img.addr = (int *)mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, 
							&img.endian);
	ft_printf("%i, %i", perso.height, perso.with);
	while (y < perso.height)
	{
		while (x < perso.with)
		{

			img.addr[y * img.line_length / 4 + x] = perso.addr[y * perso.line_length / 4 + x];
			x++;
		}
		x = 0;
		y++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0,  0);
	mlx_loop(mlx);
	return (TRUE);
}
