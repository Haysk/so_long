/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 19:32:33 by adylewsk          #+#    #+#             */
/*   Updated: 2021/06/30 20:03:26 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	map_put(t_map map, t_components comp)
{
	ft_puttab(map.tab);
	ft_printf("map.len.x : %i\n", map.len.x);
	ft_printf("map.len.y : %i\n", map.len.y);
	ft_printf("comp.P.x : %i\n", comp.P.pos.x);
	ft_printf("comp.P.y : %i\n", comp.P.pos.y);
	ft_printf("comp.C.x : %i\n", comp.C.pos.x);
	ft_printf("comp.C.y : %i\n", comp.C.pos.y);
	ft_printf("comp.E.x : %i\n", comp.E.pos.x);
	ft_printf("comp.E.y : %i\n", comp.E.pos.y);
}

void	get_map( char *file, t_map *map, t_components *comp)
{
	map_len(file, &map->len.x, &map->len.y);
	map_set(map, file);
	map_put(*map, *comp);
	// map_check(map);
}

int	main(int argc, char **argv)
{
	t_map	map;
	t_components comp;

	if (argc == 2)
	{	
		init_map(&map, &comp);
		get_map(argv[1], &map, &comp);
		// map_put(map);
		start();
		free_tab(map.tab);
		return (EXIT_SUCCESS);
	}
	return (my_error(1, NULL));
}
