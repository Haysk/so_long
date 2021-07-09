/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 16:33:49 by adylewsk          #+#    #+#             */
/*   Updated: 2021/07/09 14:17:10 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

int	my_error(int error, char *str)
{
	if (error == 0)
		return (EXIT_SUCCESS);
	if (error == 1)
		printf("ERROR\nArgument : ./so_long filename.ber\n");
	if (error == 2)
		printf("ERROR\nopen_file : File must be in %s\n", str);
	if (error == 3)
		printf("ERROR\nopen \"%s\" : %s", str, strerror(errno));
	if (error == 4)
		printf("ERROR\nmap : closed/surrounded by walls\n");
	if (error == 5)
		printf("ERROR\nmap : only walls (1), free space (0), " \
		"one player (P), one exit (E) and one collectible (C)\n");
	if (error == 6)
		ft_printf("ERROR\nmap : rectangular\n");
	if (error == 7)
		printf("ERROR\nmap : to long\n");
	if (error == 99)
		printf("%s\n", str);
	return (EXIT_FAILURE);
}
