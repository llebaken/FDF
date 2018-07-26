/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebaken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 15:44:50 by llebaken          #+#    #+#             */
/*   Updated: 2018/07/19 15:45:58 by llebaken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "includes/libft/libft.h"
# include "includes/get_next_line/get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>

typedef struct		s_draw
{
	int				dx;
	int				dy;
	int				steps;
	float			xinc;
	float			yinc;
	float			x;
	float			y;
	int				x1;
	int				x2;
	int				y1;
	int				y2;
	int				cx;
	int				cy;
}					t_draw;

typedef struct		s_norm
{
	int				fx;
	int				fy;
	int				coord;
	int				scale;
	int				x;
	int				y;
	int				temp;
}					t_norm;

typedef struct		s_main
{
	int				fd;
	char			*file;
	void			*mlx;
	void			*win;
	int				**mapa;
	int				**mapb;
	int				**fx;
	int				y;
	int				x;
	t_norm			n;
}					t_main;

int					get_next_line(const int fd, char **line);
void				ft_prepdda(t_main *a);
void				ft_dda(t_main *a, t_draw *p, float h);
void				ft_allocatemem(t_main *a);
int					my_key_funct(int keycode, t_main *a);
void				ft_fillmapb(t_main *a);
void				ft_fillmapa(t_main *a);
void				ft_drawmap(t_main *a);

#endif
