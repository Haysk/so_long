/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 22:05:32 by adylewsk          #+#    #+#             */
/*   Updated: 2021/06/30 18:02:55 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_pos
{
	int		x;
	int		y;
}				t_pos;

typedef struct	s_data {
	void	*img;
	int		*addr;
	int		with;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_comp
{
	t_pos	pos;
	t_data	img;

}				t_comp;

typedef struct s_map
{
	t_pos	len;
	char	**tab;
}				t_map;

typedef struct s_components
{
	t_comp	P;
	t_comp	C;
	t_comp	E;
}				t_components;

#endif
