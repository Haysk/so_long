/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 19:32:33 by adylewsk          #+#    #+#             */
/*   Updated: 2021/06/29 20:39:06 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	map_put(t_map map)
{
	ft_puttab(map.tab);
	ft_printf("map.len.x : %i\n", map.len.x);
	ft_printf("map.len.y : %i\n", map.len.y);
	ft_printf("map.P.x : %i\n", map.P.x);
	ft_printf("map.P.y : %i\n", map.P.y);
	ft_printf("map.C.x : %i\n", map.C.x);
	ft_printf("map.C.y : %i\n", map.C.y);
	ft_printf("map.E.x : %i\n", map.E.x);
	ft_printf("map.E.y : %i\n", map.E.y);
}

void	get_map(t_map *map, char *file)
{
	*map = init_map();
	map_len(file, &map->len.x, &map->len.y);
	map_set(map, file);
	map_check(map);
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc == 2)
	{
		get_map(&map, argv[1]);
		map_put(map);
		start();
		free_tab(map.tab);
		return (EXIT_SUCCESS);
	}
	return (my_error(1, NULL));
}
