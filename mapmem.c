/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapmem.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebaken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 15:33:16 by llebaken          #+#    #+#             */
/*   Updated: 2018/07/19 15:37:24 by llebaken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_getxy(t_main *a)
{
	int		i;
	int		c;
	char	*line;
	char	**str;

	a->y = 0;
	i = 0;
	while (get_next_line(a->fd, &line) > 0)
	{
		str = ft_strsplit(line, ' ');
		a->x = 0;
		c = 0;
		while (str[c++])
			a->x++;
		i++;
		a->y++;
		free(line);
		ft_free2dchar(str);
	}
	close(a->fd);
}

void	ft_allocatemem(t_main *a)
{
	int i;

	i = 0;
	ft_getxy(a);
	a->mapa = (int **)malloc(sizeof(int *) * a->y);
	a->mapb = (int **)malloc(sizeof(int *) * a->y);
	a->fx = (int **)malloc(sizeof(int *) * a->y);
	while (i < a->y)
	{
		a->mapa[i] = (int *)malloc(sizeof(int) * a->x);
		a->mapb[i] = (int *)malloc(sizeof(int) * a->x);
		a->fx[i] = (int *)malloc(sizeof(int) * a->x);
		i++;
	}
}
