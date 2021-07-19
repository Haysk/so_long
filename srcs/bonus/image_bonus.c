/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 01:47:17 by adylewsk          #+#    #+#             */
/*   Updated: 2021/07/19 14:50:03 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

void	img_to_bg(t_image *img, t_image *bg, t_pos pos, int fram)
{
	int	i;
	int	j;

	i = 0;
	while (i < img->height)
	{
		j = 0;
		while (j <=	50)
		{
			if (img->addr[i * img->line_length / 4 + (j + fram)] > 0)
				bg->addr[((i + pos.y * 50) * bg->line_length) / 4 + (j + pos.x * 50)]
					= img->addr[i * img->line_length / 4 + (j + fram)];
			j++;
		}
		i++;
	}
}

void	anim(t_image *img, t_image *bg, t_pos pos)
{
	img_to_bg(img, bg, pos, img->anim);
	if (img->time == 0)
	{
		if (img->anim < img->line_length / 4)
			img->anim += 50;
		img->time += 1;
	}
	else if (img->time == 20)
	{
		if (img->anim >= img->line_length / 4)
			img->anim = 0;
		img->time = 0;
	}
	else
		img->time += 1;
}

int	set_bg(t_data *data)
{
	t_pos	pos;

	pos.y = 0;
	while (data->map.tab[pos.y])
	{
		pos.x = 0;
		while (data->map.tab[pos.y][pos.x])
		{	
			if (data->map.tab[pos.y][pos.x] == '1')
				img_to_bg(&data->imgs.w, &data->imgs.bg, pos, 0);
			else
				img_to_bg(&data->imgs.s, &data->imgs.bg, pos, 0);
			if (data->map.tab[pos.y][pos.x] == 'P')
				anim(&data->imgs.p, &data->imgs.bg, pos);
			else if (data->map.tab[pos.y][pos.x] == 'N')
				anim(&data->imgs.en, &data->imgs.bg, pos);
			else if (data->map.tab[pos.y][pos.x] == 'C')
				anim(&data->imgs.c, &data->imgs.bg, pos);
			else if (data->map.tab[pos.y][pos.x] == 'E')
				img_to_bg(&data->imgs.e, &data->imgs.bg, pos, 0);
			pos.x++;
		}
		pos.y++;
	}
	return (1);
}
