/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 16:33:49 by adylewsk          #+#    #+#             */
/*   Updated: 2021/07/19 15:32:20 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

int	my_error(int error, char *str)
{
	if (error == 0)
		return (EXIT_SUCCESS);
	if (error == 1)
		ft_printf("ERROR\nArgument : ./so_long filename.ber\n");
	if (error == 2)
		ft_printf("ERROR\nopen_file : File must be in %s\n", str);
	if (error == 3)
		ft_printf("ERROR\nopen \"%s\" : %s", str, strerror(errno));
	if (error == 4)
		ft_printf("ERROR\nmap : closed/surrounded by walls\n");
	if (error == 5)
		ft_printf("ERROR\nmap : only walls (1), free spaces (0), " \
		"one player (P), exit(s) (E) and collectible(s) (C)\n");
	if (error == 6)
		ft_printf("ERROR\nmap : rectangular\n");
	if (error == 7)
		ft_printf("ERROR\nmap : to long\n");
	if (error == 8)
		ft_printf("ERROR\nimage : not found\n");
	if (error == 99)
		ft_printf("%s\n", str);
	return (EXIT_FAILURE);
}
