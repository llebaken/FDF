/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebaken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 15:22:43 by llebaken          #+#    #+#             */
/*   Updated: 2018/08/15 15:16:23 by llebaken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_arrays(t_main *a)
{
	ft_free2dint(a->mapa, a->y);
	ft_free2dint(a->mapb, a->y);
	ft_free2dint(a->fx, a->y);
}

int		ft_key_funct(int keycode, t_main *a)
{
	if (keycode == 53)
	{
		mlx_destroy_window(a->mlx, a->win);
		ft_free_arrays(a);
		exit(0);
	}
	if (keycode == 126)
	{
		if (mlx_clear_window(a->mlx, a->win))
		{
			a->n.scale += 1;
			ft_drawmap(a);
		}
	}
	else if (keycode == 125 && (a->n.scale - 0.5 >= 5))
	{
		if (mlx_clear_window(a->mlx, a->win))
		{
			a->n.scale -= 0.5;
			ft_drawmap(a);
		}
	}
	return (0);
}
