/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 22:43:04 by adylewsk          #+#    #+#             */
/*   Updated: 2021/07/19 18:54:17 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

void	map_len(char *file, t_map *map)
{
	char	*line;
	int		fd;
	int		len;

	line = NULL;
	fd = open_file(file, ".ber");
	len = 0;
	while (get_next_line(fd, &line))
	{
		if (map->leny == 0)
			map->lenx = (int)ft_strlen(line);
		if (ft_strlen(line) != (size_t)map->lenx)
			len++;
		map->leny += 1;
		free(line);
	}
	free(line);
	close(fd);
	if (len)
		exit(my_error(6, NULL));
}

int	map_set(t_map *map, char *file)
{
	int		y;
	int		fd;
	char	*line;

	y = 0;
	fd = open_file(file, ".ber");
	line = NULL;
	map->tab = calloc(map->leny + 1, sizeof(map->tab));
	while (get_next_line(fd, &line))
	{
		map->tab[y] = ft_strdup(line);
		y++;
		free(line);
	}
	free(line);
	close(fd);
	return (TRUE);
}

int	map_borders(t_map map, int y)
{
	int	x;

	x = 0;
	if (map.tab[y][x] != '1' || map.tab[y][map.lenx - 1] != '1')
		return (FALSE);
	if (y == 0 || y == map.leny - 1)
	{
		while (map.tab[y][x])
		{
			if (map.tab[y][x] != '1')
				return (FALSE);
			x++;
		}
	}
	return (TRUE);
}

int	map_component(t_data *data, int y)
{
	int	x;

	x = 0;
	while (data->map.tab[y][x])
	{
		if (data->map.tab[y][x] == 'P')
		{
			data->perso.x = x;
			data->perso.y = y;
			data->comps.p++;
		}
		else if (data->map.tab[y][x] == 'N')
			data->comps.en++;
		else if (data->map.tab[y][x] == 'C')
			data->comps.c++;
		else if (data->map.tab[y][x] == 'E')
			data->comps.e++;
		else if (!ft_strrchr("PCEN10", data->map.tab[y][x]))
			return (FALSE);
		x++;
	}
	return (TRUE);
}

int	map_check(t_data *data)
{
	int	y;

	y = 0;
	while (y < data->map.leny)
	{
		if (!map_borders(data->map, y))
			close_map(&data->map, 4);
		if (!map_component(data, y))
			close_map(&data->map, 5);
		y++;
	}
	enemie_pos(data);
	if (data->comps.p != 1 || data->comps.c == 0 || data->comps.e == 0)
		close_map(&data->map, 5);
	return (TRUE);
}
