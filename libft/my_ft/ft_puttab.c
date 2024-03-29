/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adylewsk <adylewsk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 18:09:12 by adylewsk          #+#    #+#             */
/*   Updated: 2021/06/29 14:09:11 by adylewsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_puttab(char **tab)
{
	int	i;

	i = 0;
	while (*tab)
	{
		ft_printf("%4i : %s\n", i, *tab);
		tab++;
		i++;
	}
}
