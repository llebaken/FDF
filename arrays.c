/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrays.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebaken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 15:27:38 by llebaken          #+#    #+#             */
/*   Updated: 2018/07/19 15:32:28 by llebaken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_fillmapb(t_main *a)
{
	a->n.y = 0;
	while (a->n.y < a->y)
	{
		a->n.x = 0;
		while (a->n.x < a->x)
		{
			a->n.fx = (a->n.x * a->n.scale) - (a->n.y * a->n.scale) + 700;
			a->fx[a->n.y][a->n.x] = a->n.fx;
			a->n.temp = ((a->n.x * a->n.scale) + (a->n.y * a->n.scale));
			a->n.fy = a->n.temp / 2 + 200 - a->mapa[a->n.y][a->n.x];
			a->n.coord = a->n.fx + a->n.fy;
			a->mapb[a->n.y][a->n.x] = a->n.coord;
			a->n.x++;
		}
		a->n.y++;
	}
}

void	ft_fillmapa(t_main *a)
{
	char	*str;
	char	**st;
	int		i;
	int		x;
	int		y;

	y = 0;
	a->fd = open(a->file, O_RDONLY);
	while (get_next_line(a->fd, &str) > 0)
	{
		x = 0;
		i = 0;
		st = ft_strsplit(str, ' ');
		while (st[i])
		{
			a->mapa[y][x] = ft_atoi(st[i]);
			i++;
			x++;
		}
		y++;
	}
}
