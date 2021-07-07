/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 16:35:36 by adylewsk          #+#    #+#             */
/*   Updated: 2021/07/07 01:53:19 by adylewsk         ###   ########.fr       */
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

void	close_data(t_data *data, int error, char *str)
{
	free_tab(data->map.tab);
	if (data->mlx.win.ptr)
		mlx_destroy_window(data->mlx.ptr, data->mlx.win.ptr);
	exit(my_error(error, str));
}
