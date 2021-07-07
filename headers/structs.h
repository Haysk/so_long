/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 22:05:32 by adylewsk          #+#    #+#             */
/*   Updated: 2021/07/07 01:51:15 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

// typedef struct s_pos
// {
// 	int		x;
// 	int		y;
// }				t_pos;

typedef struct	s_image {
	void	*img;
	int		*addr;
	int		with;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_image;

typedef struct s_pos
{
	int		x;
	int		y;
}				t_pos;

typedef struct s_components
{
	t_pos	p;
	t_pos	c;
	t_pos	e;
}				t_components;

typedef struct s_map
{
	int		lenx;
	int		leny;
	t_image	**imgs;
	char	**tab;
}				t_map;

typedef struct s_window
{
	int		lenx;
	int		leny;
	void	*ptr;
}				t_window;

typedef struct s_mlx
{
	void		*ptr;
	t_window	win;
}				t_mlx;

typedef struct s_images
{
	t_image	bg;
	t_image	w;
	t_image	s;
	t_image	p;
	t_image	c;
	t_image	e;
}				t_images;

typedef struct s_data
{
	t_mlx			mlx;
	t_map			map;
	t_components	comps;
	t_images		imgs;
}				t_data;

#endif
