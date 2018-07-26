/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebaken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 12:20:39 by llebaken          #+#    #+#             */
/*   Updated: 2018/06/28 17:30:43 by llebaken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		x;
	size_t		y;
	size_t		size;

	size = len;
	x = 0;
	y = 0;
	if (ft_strlen(needle) == 0)
		return ((char*)haystack);
	while (haystack[x] != '\0' && x < size)
	{
		y = 0;
		while ((needle[y] != '\0') && haystack[x + y] != '\0' &&
			(haystack[x + y] == needle[y]) && (x + y < size))
		{
			y++;
		}
		if (needle[y] == '\0')
			return ((char*)(haystack + x));
		x++;
	}
	return (NULL);
}
