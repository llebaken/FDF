/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebaken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 12:07:42 by llebaken          #+#    #+#             */
/*   Updated: 2018/06/28 17:31:12 by llebaken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t		x;
	size_t		y;

	if (ft_strlen(needle) == 0)
		return ((char*)haystack);
	x = 0;
	while (haystack[x] != '\0')
	{
		y = 0;
		while (needle[y] != '\0' && haystack[x + y] != '\0' && needle[y] ==
				haystack[x + y])
			y++;
		if (y == ft_strlen(needle))
			return ((char*)(&(haystack[x])));
		x++;
	}
	return (NULL);
}
