/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 21:57:38 by adylewsk          #+#    #+#             */
/*   Updated: 2021/07/09 14:17:13 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long_bonus.h"

int	check_file_extension(char *path, char *str)
{
	ssize_t	path_end;
	ssize_t	str_end;

	path_end = strlen(path) - 1;
	str_end = strlen(str) - 1;
	while (path_end >= 0 && str_end >= 0)
	{
		if (path[path_end] != str[str_end])
			return (FALSE);
		path_end--;
		str_end--;
	}
	return (TRUE);
}

int	open_file(char *path, char	*extension)
{
	int	fd;

	fd = 0;
	if (!check_file_extension(path, extension))
		exit(my_error(2, extension));
	fd = open(path, O_RDWR);
	if (fd == -1)
		exit(my_error(3, path));
	return (fd);
}
