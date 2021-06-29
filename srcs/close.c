/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 16:35:36 by adylewsk          #+#    #+#             */
/*   Updated: 2021/06/29 02:22:14 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	free_tab(void **tab)
{
	int	i;

	i = 0;
	if (tab == NULL)
		return (EXIT_FAILURE);
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (EXIT_SUCCESS);
}

void	free_all(int fd, char *line, void **map)
{
	printf("free all\n");
	if (fd)
		close(fd);
	if (line != NULL)
		free(line);
	free_tab(map);
	exit(EXIT_SUCCESS);
}
