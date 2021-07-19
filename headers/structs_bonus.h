/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 22:05:32 by adylewsk          #+#    #+#             */
/*   Updated: 2021/07/19 14:04:21 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_image {
	void	*img;
	int		*addr;
	int		anim;
	int		time;
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
	int	p;
	int	c;
	int	e;
	int	en;
}				t_components;

typedef struct s_map
{
	int		lenx;
	int		leny;
	char	**tab;
}				t_map;

typedef struct s_images
{
	t_image	bg;
	t_image	w;
	t_image	s;
	t_image	p;
	t_image	c;
	t_image	e;
	t_image	en; //enemie
}				t_images;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	int				width;
	int				heigth;
	int				moves;
	t_pos			perso;
	t_pos			*en;
	t_map			map;
	t_components	comps;
	t_images		imgs;
}				t_data;

#endif
