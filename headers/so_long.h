/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/27 19:31:37 by adylewsk          #+#    #+#             */
/*   Updated: 2021/06/29 02:11:16 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "utils.h"
# include "structs.h"

int		open_file(char *path, char *extension);

int		my_error(int error, char *str);
int		free_tab(void **tab);
void	free_all(int fd, char *line, void **map);

// t_params		new_params(void);
// t_resolution	*init_resolution(void);
// t_texture		*init_textures(void);
// t_color			*init_colors(void);
t_map	init_map(void);

// int				set_res(char **tab, t_resolution *res);
// int				set_colors(char **tab, t_color *colors);
// int				set_textures(char **tab, t_texture *texture);
// int				set_params(char *line, t_params *params);
void	map_len(char *file, int *x, int *y);
int		set_map(t_map map, char *file);

int		print_map(char **map);

#endif
