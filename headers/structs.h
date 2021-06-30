/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 22:05:32 by adylewsk          #+#    #+#             */
/*   Updated: 2021/06/30 02:21:04 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_pos
{
	int		x;
	int		y;
}				t_pos;

typedef struct s_map
{
	t_pos	len;
	t_pos	P;
	t_pos	C;
	t_pos	E;
	char **tab;
}				t_map;

typedef struct	s_data {
	void	*img;
	int		*addr;
	int		with;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

#endif
