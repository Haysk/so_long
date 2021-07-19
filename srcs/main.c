/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 19:32:33 by adylewsk          #+#    #+#             */
/*   Updated: 2021/07/19 19:19:32 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	get_map(char *file, t_data *data)
{
	map_len(file, &data->map);
	map_set(&data->map, file);
	map_check(data);
}

int	main(int argc, char **argv)
{
	t_data	data;
	
	if (argc == 2)
	{	
		data_init(&data);
		get_map(argv[1], &data);
		start(&data);
		close_mlx(&data, 0);
		return (EXIT_SUCCESS);
	}
	return (my_error(1, NULL));
}
