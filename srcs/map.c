/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 22:43:04 by adylewsk          #+#    #+#             */
/*   Updated: 2021/06/30 20:38:03 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	map_len(char *file, int *x, int *y)
{
	char	*line;
	int		fd;
	size_t	len;

	line = NULL;
	fd = open_file(file, ".ber");
	len = 0;
	while (get_next_line(fd, &line) && (size_t) * x == len)
	{
		len = ft_strlen(line);
		if (*y == 0)
			*x = (int)len;
		*y += 1;
		free(line);
	}
	free(line);
	close(fd);
	if ((size_t) * x != len)
		exit(my_error(99, "ERROR\nmap : rectangular"));
}

int	map_set(t_map *map, char *file)
{
	int		y;
	int		fd;
	char	*line;

	y = 0;
	fd = open_file(file, ".ber");
	line = NULL;
	map->tab = calloc(map->len.y + 1, sizeof(map->tab));
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
	if (map.tab[y][x] != '1' || map.tab[y][map.len.x - 1] != '1')
		return (FALSE);
	if (y == 0 || y == map.len.y - 1)
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

int	map_component(t_components *comps, t_map *map, int y)
{
	int	x;

	x = 0;
	while (map->tab[y][x])
	{
		if ((map->tab[y][x] == 'P' && add_comp(&comps->P, x, y) == FALSE)
			|| (map->tab[y][x] == 'C' && add_comp(&comps->C, x, y) == FALSE)
			|| (map->tab[y][x] == 'E' && add_comp(&comps->E, x, y) == FALSE)
			|| (!ft_strrchr("PCE10", map->tab[y][x])))
			return (FALSE);
		if (ft_strrchr("PCE", map->tab[y][x]))
			map->tab[y][x] = '0';
		x++;
	}
	return (TRUE);
}

int	map_check(t_map *map, t_components *comps)
{
	int	y;

	y = 0;
	while (y < map->len.y)
	{
		if (!map_borders(*map, y))
			my_close(map, 4, 0);
		if (!map_component(comps, map, y))
			my_close(map, 5, 0);
		y++;
	}
	if (comps->P.pos.x < 0 || comps->C.pos.x < 0 || comps->E.pos.x < 0)
		my_close(map, 5, 0);
	return (TRUE);
}
