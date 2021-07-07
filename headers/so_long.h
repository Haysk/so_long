/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 19:31:37 by adylewsk          #+#    #+#             */
/*   Updated: 2021/07/07 01:52:57 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include <mlx.h>
# include "utils.h"
# include "structs.h"

int		open_file(char *path, char *extension);
void	data_init(t_data *data);
void	map_len(char *file, t_map *map);
int		map_set(t_map *map, char *file);
int		map_check(t_map *map, t_components *comps);
int		add_comp(t_pos *pos, int x, int y);

int		start(t_data *data);

int		my_error(int error, char *str);
int		free_tab(char **tab);
void	close_map(t_map *map, int error, char *str);
void	close_data(t_data *data, int error, char *str);


#endif
