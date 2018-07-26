/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebaken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 15:11:07 by llebaken          #+#    #+#             */
/*   Updated: 2018/07/19 15:17:41 by llebaken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_printmap(int **map, int mapy, int mapx)
{
	int x;
	int y;

	y = 0;
	while (mapy > y)
	{
		x = 0;
		while (mapx > x)
		{
			ft_putnbr(map[y][x]);
			ft_putchar(' ');
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}
