/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 22:05:46 by adylewsk          #+#    #+#             */
/*   Updated: 2021/07/19 15:26:29 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	move_up(t_data *data)
{	
	if (data->map.tab[data->perso.y - 1][data->perso.x] == '1'
	|| (data->map.tab[data->perso.y - 1][data->perso.x] == 'E'
	&& data->comps.c != 0))
		return (0);
	if (data->map.tab[data->perso.y - 1][data->perso.x] == 'E')
		exit(my_error(close_mlx(data, 99), "WIN"));
	if (data->map.tab[data->perso.y - 1][data->perso.x] == 'C')
		data->comps.c -= 1;
	data->map.tab[data->perso.y - 1][data->perso.x]
		= data->map.tab[data->perso.y][data->perso.x];
	data->map.tab[data->perso.y][data->perso.x] = '0';
	data->perso.y -= 1;
	return (1);
}

int	move_down(t_data *data)
{
	if (data->map.tab[data->perso.y + 1][data->perso.x] == '1'
	|| (data->map.tab[data->perso.y + 1][data->perso.x] == 'E'
	&& data->comps.c != 0))
		return (0);
	if (data->map.tab[data->perso.y + 1][data->perso.x] == 'E')
		exit(my_error(close_mlx(data, 99), "WIN"));
	if (data->map.tab[data->perso.y + 1][data->perso.x] == 'C')
		data->comps.c -= 1;
	data->map.tab[data->perso.y + 1][data->perso.x]
		= data->map.tab[data->perso.y][data->perso.x];
	data->map.tab[data->perso.y][data->perso.x] = '0';
	data->perso.y += 1;
	return (1);
}

int	move_left(t_data *data)
{
	if (data->map.tab[data->perso.y][data->perso.x - 1] == '1'
	|| (data->map.tab[data->perso.y][data->perso.x - 1] == 'E'
	&& data->comps.c != 0))
		return (0);
	if (data->map.tab[data->perso.y][data->perso.x - 1] == 'E')
		exit(my_error(close_mlx(data, 99), "WIN"));
	if (data->map.tab[data->perso.y][data->perso.x - 1] == 'C')
		data->comps.c -= 1;
	data->map.tab[data->perso.y][data->perso.x - 1]
		= data->map.tab[data->perso.y][data->perso.x];
	data->map.tab[data->perso.y][data->perso.x] = '0';
	data->perso.x -= 1;
	return (1);
}

int	move_right(t_data *data)
{
	if (data->map.tab[data->perso.y][data->perso.x + 1] == '1'
	|| (data->map.tab[data->perso.y][data->perso.x + 1] == 'E'
	&& data->comps.c != 0))
		return (0);
	if (data->map.tab[data->perso.y][data->perso.x + 1] == 'E')
		exit(my_error(close_mlx(data, 99), "WIN"));
	if (data->map.tab[data->perso.y][data->perso.x + 1] == 'C')
		data->comps.c -= 1;
	data->map.tab[data->perso.y][data->perso.x + 1]
		= data->map.tab[data->perso.y][data->perso.x];
	data->map.tab[data->perso.y][data->perso.x] = '0';
	data->perso.x += 1;
	return (1);
}
