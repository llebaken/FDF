/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepdda.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebaken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 15:25:42 by llebaken          #+#    #+#             */
/*   Updated: 2018/08/15 15:08:21 by llebaken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_getfy(t_main *a, int x, int y, int fx)
{
	int		fy;

	fy = a->mapb[y][x] - fx;
	return (fy);
}

void		ft_px(int x, int y, t_draw *p, t_main *a)
{
	p->x1 = a->fx[y][x];
	p->x2 = a->fx[y][x + 1];
	p->y1 = ft_getfy(a, x, y, p->x1);
	p->y2 = ft_getfy(a, x + 1, y, p->x2);
}

void		ft_py(int x, int y, t_draw *p, t_main *a)
{
	p->x1 = a->fx[y][x];
	p->x2 = a->fx[y + 1][x];
	p->y1 = ft_getfy(a, x, y, p->x1);
	p->y2 = ft_getfy(a, x, y + 1, p->x2);
}

void		ft_prepdda(t_main *a)
{
	t_draw	p;
	int		cx;
	int		cy;

	cy = 0;
	while (cy < a->y)
	{
		cx = 0;
		while (cx < a->x)
		{
			if (cx < a->x - 1)
			{
				ft_px(cx, cy, &p, a);
				ft_dda(a, &p, a->mapa[cy][cx]);
			}
			if (cy < a->y - 1)
			{
				ft_py(cx, cy, &p, a);
				ft_dda(a, &p, a->mapa[cy][cx]);
			}
			cx++;
		}
		cy++;
	}
}
