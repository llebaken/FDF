/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebaken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 15:22:15 by llebaken          #+#    #+#             */
/*   Updated: 2018/07/19 15:22:17 by llebaken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		abs(int n)
{
	return ((n > 0) ? n : (n * (-1)));
}

void	ft_dda(t_main *a, t_draw *p, float h)
{
	int	i;

	i = 0;
	p->dx = p->x2 - p->x1;
	p->dy = p->y2 - p->y1;
	p->steps = abs(p->dx) > abs(p->dy) ? abs(p->dx) : abs(p->dy);
	p->xinc = p->dx / (double)p->steps;
	p->yinc = p->dy / (double)p->steps;
	p->x = p->x1;
	p->y = p->y1;
	while (i <= p->steps)
	{
		if (h > 0)
			mlx_pixel_put(a->mlx, a->win, p->x, p->y, 0x8470FF);
		else if (h < 0)
			mlx_pixel_put(a->mlx, a->win, p->x, p->y, 0x0042F45F);
		else
			mlx_pixel_put(a->mlx, a->win, p->x, p->y, 0xff0000);
		p->x += p->xinc;
		p->y += p->yinc;
		i++;
	}
}
