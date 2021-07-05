/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 19:31:37 by adylewsk          #+#    #+#             */
/*   Updated: 2021/06/30 20:38:24 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <mlx.h>
# include "utils.h"
# include "structs.h"

int		open_file(char *path, char *extension);
void	init_map(t_map *map, t_components *components);
void	map_len(char *file, int *x, int *y);
int		map_set(t_map *map, char *file);
int		map_check(t_map *map, t_components *comps);
int		add_comp(t_comp *comp, int x, int y);

int		start();

int		my_error(int error, char *str);
int		free_tab(char **tab);
void	my_close(t_map *map, int error, char *str);

#endif
