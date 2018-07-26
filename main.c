/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebaken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 15:39:09 by llebaken          #+#    #+#             */
/*   Updated: 2018/07/19 15:44:13 by llebaken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_drawmap(t_main *a)
{
	ft_fillmapb(a);
	ft_prepdda(a);
}

void	ft_scale(t_main *a)
{
	if ((a->y <= 22) && (a->x <= 22))
		a->n.scale = 15;
	else
		a->n.scale = 6;
}

int		main(int ac, char **av)
{
	t_main a;

	a.mlx = mlx_init();
	a.win = mlx_new_window(a.mlx, 1920, 1080, "FDF");
	if ((ac != 2) || (!ft_strstr(av[1], ".fdf")))
		ft_putstr("Please add .fdf file\n");
	else if ((a.fd = open(av[1], O_RDONLY)) == -1)
		ft_putstr("File cannot be read\n.");
	else
	{
		a.file = av[1];
		ft_allocatemem(&a);
		ft_fillmapa(&a);
		ft_scale(&a);
		ft_drawmap(&a);
		mlx_key_hook(a.win, my_key_funct, &a);
		mlx_loop(a.mlx);
	}
	close(a.fd);
	free(a.mapa);
	free(a.mapb);
	return (0);
}
