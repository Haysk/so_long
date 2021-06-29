/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   settings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 22:43:04 by adylewsk          #+#    #+#             */
/*   Updated: 2021/06/29 02:20:25 by adylewsk         ###   ########.fr       */
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
	while (get_next_line(fd, &line) && (size_t)*x == len)
	{
		len = ft_strlen(line);
		if (*y == 0)
			*x = (int)len;
		*y += 1;
		free(line);
	}
	free(line);
	close(fd);
	if ((size_t)*x != len)
		exit(EXIT_FAILURE);
}

int	set_map(t_map map, char *file)
{
	int		y;
	int		x;
	int		fd;
	char	*line;

	y = 0;
	x = 0;
	fd = open_file(file, ".ber");
	line = NULL;
	map.tab = (char **)malloc(sizeof(map.tab) * map.y + 1);
	while (get_next_line(fd, &line))
	{
		if (empty_line(line))
		{
			printf("empty line\n");
			free_all(fd, line, (void **)map.tab);
		}
		map.tab[y] = ft_strdup(line);
		ft_printf("%s\n", map.tab[y]);
		y++;
		free(line);
	}
	// if (tab_funptr(tab, params) == ERROR)
	// 	printf("ERROR\nset_params : funptr NULL\n\n");
	// // params.colors = set_colors(tab, params.colors);
	// // params.textures = set_textures(tab, params.textures);
	// free_tab(tab);
	// if (errno != 0)
	// {
	// 	free_all(line, params);
	// 	exit(my_error(errno, NULL));
	// }
	return (EXIT_SUCCESS);
}
