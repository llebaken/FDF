/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebaken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 09:16:17 by llebaken          #+#    #+#             */
/*   Updated: 2018/08/15 15:44:16 by llebaken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_read_and_count(const int fd, char **holder)
{
	char	*lin;
	char	*tmp;
	int		counter;

	lin = (char*)malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (lin == NULL)
		return (-1);
	counter = read(fd, lin, BUFF_SIZE);
	if (counter > 0)
	{
		lin[counter] = '\0';
		tmp = ft_strjoin(*holder, lin);
		free(*holder);
		*holder = tmp;
	}
	free(lin);
	return (counter);
}

static int		ft_precheck(char **holder, const int fd, char **eol)
{
	int	rvalue;

	if (*holder == NULL)
	{
		*holder = (char *)malloc(sizeof(char));
		*holder[0] = '\0';
	}
	if (*holder == NULL || fd < 0 || BUFF_SIZE < 0)
		rvalue = -1;
	else
		rvalue = 1;
	*eol = ft_strchr(*holder, '\n');
	return (rvalue);
}

void			ft_temp_holder(char **holder, char **eol)
{
	char *temp;

	temp = *holder;
	*holder = ft_strjoin(*holder, "\n");
	free(temp);
	*eol = ft_strchr(*holder, '\n');
}

int				get_next_line(const int fd, char **line)
{
	static char	*holder = NULL;
	char		*eol;
	int			counter;

	if (ft_precheck(&holder, fd, &eol) == -1)
		return (-1);
	while (eol == NULL)
	{
		counter = ft_read_and_count(fd, &holder);
		if (counter == 0)
		{
			if (ft_strlen(holder) == 0)
				return (0);
			ft_temp_holder(&holder, &eol);
		}
		else if (counter < 0)
			return (-1);
		eol = ft_strchr(holder, '\n');
	}
	*line = ft_strsub(holder, 0, ft_strlen(holder) - ft_strlen(eol));
	free(holder);
	eol = ft_strdup(&(eol[1]));
	holder = eol;
	return (1);
}
