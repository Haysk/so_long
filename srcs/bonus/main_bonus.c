/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 19:32:33 by adylewsk          #+#    #+#             */
/*   Updated: 2021/07/09 14:17:25 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

void	map_put(t_data *data)
{
	ft_puttab(data->map.tab);
	ft_printf("map.len.x : %i\n", data->map.lenx);
	ft_printf("map.len.y : %i\n", data->map.leny);
	ft_printf("comp.P : %i\n", data->comps.p);
	ft_printf("comp.C : %i\n", data->comps.c);
	ft_printf("comp.E : %i\n", data->comps.e);
}

void	get_map(char *file, t_data *data)
{
	map_len(file, &data->map);
	map_set(&data->map, file);
	map_check(data);
	map_put(data);
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
