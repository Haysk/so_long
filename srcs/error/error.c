/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 16:33:49 by adylewsk          #+#    #+#             */
/*   Updated: 2021/06/28 20:48:31 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	my_error(int error, char *str)
{
	if (error == 1)
		printf("ERROR\nArgument : ./so_long filename.ber\n");
	if (error == 2)
		printf("ERROR\nopen_file : File must be in %s\n", str);
	if (error == 3)
		printf("ERROR\nopen \"%s\" : %s", str, strerror(errno));
	if (error == 4)
		printf("ERROR\nresolution : min \"800 600\" max \"1920 1080\"\n");
	return (EXIT_FAILURE);
}
