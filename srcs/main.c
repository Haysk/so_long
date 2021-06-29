/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 19:32:33 by adylewsk          #+#    #+#             */
/*   Updated: 2021/06/29 02:22:54 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	start(char *file)
{
	t_map	map;


	map = init_map();
	map_len(file, &map.x, &map.y);
	set_map(map, file);
	print_map(map.tab);
	free_all(0, NULL, (void **)map.tab);
	return (EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		return (start(argv[1]));
	return (my_error(1, NULL));
}
