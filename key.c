/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebaken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 15:22:43 by llebaken          #+#    #+#             */
/*   Updated: 2018/07/19 15:25:19 by llebaken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		my_key_funct(int keycode, t_main *a)
{
	if (keycode == 53)
		exit(0);
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
