/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebaken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 12:17:30 by llebaken          #+#    #+#             */
/*   Updated: 2018/06/28 17:12:18 by llebaken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	int						i;
	unsigned char			*tmps1;
	const unsigned char		*tmps2;

	i = 0;
	tmps1 = dst;
	tmps2 = src;
	while (n > 0)
	{
		tmps1[i] = tmps2[i];
		if (tmps1[i] == (unsigned char)c)
			return (dst + 1 + i);
		i++;
		n--;
	}
	return (NULL);
}
