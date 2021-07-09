/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 01:47:17 by adylewsk          #+#    #+#             */
/*   Updated: 2021/07/09 16:37:41 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	img_to_bg(t_image *img, t_image *bg, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < img->height)
	{
		j = 0;
		while (j < 50)
		{
			if (img->addr[i * img->line_length / 4 + j] >= 0)
				bg->addr[((i + y) * bg->line_length) / 4 + (j + x)]
					= img->addr[i * img->line_length / 4 + j];
			j++;
		}
		i++;
	}
}

int	set_bg(t_data *data)
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
				img_to_bg(&data->imgs.w, &data->imgs.bg, x * 50, y * 50);
			else
				img_to_bg(&data->imgs.s, &data->imgs.bg, x * 50, y * 50);
			if (data->map.tab[y][x] == 'P')
				img_to_bg(&data->imgs.p, &data->imgs.bg, x * 50, y * 50);
			else if (data->map.tab[y][x] == 'C')
				img_to_bg(&data->imgs.c, &data->imgs.bg, x * 50, y * 50);
			else if (data->map.tab[y][x] == 'E')
				img_to_bg(&data->imgs.e, &data->imgs.bg, x * 50, y * 50);
			x++;
		}
		y++;
	}
	return (1);
}
