/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 19:31:37 by adylewsk          #+#    #+#             */
/*   Updated: 2021/07/08 03:41:28 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include "utils.h"
# include "structs.h"

int		open_file(char *path, char *extension);
void	data_init(t_data *data);
void	images_set(t_data *data, t_images *imgs);
void	*window_set(t_data *data);
int		set_bg(t_data *data);
void	map_len(char *file, t_map *map);
int		map_set(t_map *map, char *file);
int		map_check(t_data *data);
int		add_comp(t_pos *pos, int x, int y);
void	img_to_bg(t_image *img, t_image *bg, int x, int y);
int		start(t_data *data);
int		move_up(t_data *data);
int		move_down(t_data *data);
int		move_left(t_data *data);
int		move_right(t_data *data);
int		my_error(int error, char *str);
int		free_tab(char **tab);
void	close_map(t_map *map, int error, char *str);
int		close_mlx(t_data *data, int error);

#endif
