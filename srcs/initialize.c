/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 01:47:17 by adylewsk          #+#    #+#             */
/*   Updated: 2021/06/29 02:10:29 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

t_map	init_map(void)
{
	t_map map;

	map.x = 0;
	map.y = 0;
	map.tab = NULL;
	return (map);
}

int	print_map(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map && map[i])
	{
		while (map[i][j])
		{
			ft_printf("%s", map[i][j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
	return (EXIT_SUCCESS);
}
