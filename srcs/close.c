/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 16:35:36 by adylewsk          #+#    #+#             */
/*   Updated: 2021/07/09 16:34:45 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return (FALSE);
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (TRUE);
}

void	close_map(t_map *map, int error, char *str)
{
	free_tab(map->tab);
	exit(my_error(error, str));
}

int	close_mlx(t_data *data, int error)
{
	if (data->imgs.w.img)
		mlx_destroy_image(data->mlx, data->imgs.w.img);
	if (data->imgs.s.img)
		mlx_destroy_image(data->mlx, data->imgs.s.img);
	if (data->imgs.p.img)
		mlx_destroy_image(data->mlx, data->imgs.p.img);
	if (data->imgs.c.img)
		mlx_destroy_image(data->mlx, data->imgs.c.img);
	if (data->imgs.e.img)
		mlx_destroy_image(data->mlx, data->imgs.e.img);
	if (data->imgs.bg.img)
		mlx_destroy_image(data->mlx, data->imgs.bg.img);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	if (data->map.tab)
		free_tab(data->map.tab);
	return (error);
}
