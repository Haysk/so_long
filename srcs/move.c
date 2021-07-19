/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/07 22:05:46 by adylewsk          #+#    #+#             */
/*   Updated: 2021/07/19 19:16:40 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	move_perso(t_data *data, int x, int y)
{	
	if (data->map.tab[data->perso.y + y][data->perso.x + x] == '1'
	|| (data->map.tab[data->perso.y + y][data->perso.x + x] == 'E'
	&& data->comps.c != 0))
		return (0);
	if (data->map.tab[data->perso.y + y][data->perso.x + x] == 'E')
		exit(my_error(close_mlx(data, 99), "WIN"));
	if (data->map.tab[data->perso.y + y][data->perso.x + x] == 'C')
		data->comps.c -= 1;
	data->map.tab[data->perso.y + y][data->perso.x + x]
		= data->map.tab[data->perso.y][data->perso.x];
	data->map.tab[data->perso.y][data->perso.x] = '0';
	data->perso.x += x;
	data->perso.y += y;
	return (1);
}
