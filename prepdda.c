/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepdda.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebaken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 15:25:42 by llebaken          #+#    #+#             */
/*   Updated: 2018/07/19 15:26:20 by llebaken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_getfy(t_main *a, int x, int y, int fx)
{
	int fy;

	fy = a->mapb[y][x] - fx;
	return (fy);
}

void	ft_p1(int x, int y, t_draw *p1, t_main *a)
{
	int phx;
	int phx2;
	int phy;
	int phy2;

	phx = a->fx[y][x];
	phx2 = a->fx[y][x + 1];
	phy = ft_getfy(a, x, y, phx);
	phy2 = ft_getfy(a, x + 1, y, phx2);
	p1->x1 = a->mapb[y][x] - phy;
	p1->y1 = a->mapb[y][x] - phx;
	p1->x2 = a->mapb[y][x + 1] - phy2;
	p1->y2 = a->mapb[y][x + 1] - phx2;
}

void	ft_p2(int x, int y, t_draw *p2, t_main *a)
{
	int phx;
	int phx2;
	int phy;
	int phy2;

	phx = a->fx[y][x];
	phx2 = a->fx[y + 1][x];
	phy = ft_getfy(a, x, y, phx);
	phy2 = ft_getfy(a, x, y + 1, phx2);
	p2->x1 = a->mapb[y][x] - phy;
	p2->y1 = a->mapb[y][x] - phx;
	p2->x2 = a->mapb[y + 1][x] - phy2;
	p2->y2 = a->mapb[y + 1][x] - phx2;
}

void	ft_prepdda(t_main *a)
{
	t_draw	p;
	t_draw	p1;

	p1.y = 0;
	while (p1.y < a->y)
	{
		p1.x = 0;
		while (p1.x < a->x)
		{
			p1.cx = (int)p1.x;
			p1.cy = (int)p1.y;
			if (p1.x < a->x - 1)
			{
				ft_p1(p1.x, p1.y, &p, a);
				ft_dda(a, &p, a->mapa[p1.cy][p1.cx]);
			}
			if (p1.y < a->y - 1)
			{
				ft_p2(p1.x, p1.y, &p, a);
				ft_dda(a, &p, a->mapa[p1.cy][p1.cx]);
			}
			p1.x++;
		}
		p1.y++;
	}
}
