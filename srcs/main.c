/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 19:32:33 by adylewsk          #+#    #+#             */
/*   Updated: 2021/07/07 01:55:57 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	map_put(t_map map, t_components comp)
{
	ft_puttab(map.tab);
	ft_printf("map.len.x : %i\n", map.lenx);
	ft_printf("map.len.y : %i\n", map.leny);
	ft_printf("comp.P.x : %i\n", comp.p.x);
	ft_printf("comp.P.y : %i\n", comp.p.y);
	ft_printf("comp.C.x : %i\n", comp.c.x);
	ft_printf("comp.C.y : %i\n", comp.c.y);
	ft_printf("comp.E.x : %i\n", comp.e.x);
	ft_printf("comp.E.y : %i\n", comp.e.y);
}

void	get_map(char *file, t_map *map, t_components *comp)
{
	map_len(file, map);
	map_set(map, file);
	map_check(map, comp);
	map_put(*map, *comp);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 2)
	{	
		data_init(&data);
		get_map(argv[1], &data.map, &data.comps);
		start(&data);
		free_tab(data.map.tab);
		free(data.mlx.ptr);
		return (EXIT_SUCCESS);
	}
	return (my_error(1, NULL));
}
