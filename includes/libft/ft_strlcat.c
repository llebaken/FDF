/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebaken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 11:54:22 by llebaken          #+#    #+#             */
/*   Updated: 2018/06/28 17:36:21 by llebaken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	length;
	size_t	div;
	size_t	size;

	size = dstsize;
	length = 0;
	while (length < size && *dst && *(dst++))
		length++;
	div = size - length;
	if (!div)
		return (length + ft_strlen(src));
	while (*src)
	{
		if (div != 1)
		{
			*(dst++) = *src;
			div--;
		}
		src++;
		length++;
	}
	*dst = '\0';
	return (length);
}
