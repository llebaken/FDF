/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebaken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 12:21:51 by llebaken          #+#    #+#             */
/*   Updated: 2018/06/28 17:14:06 by llebaken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char		h;
	char		*str;

	h = (unsigned char)c;
	str = (char*)s;
	while (n--)
	{
		if (*str == h)
			return (str);
		str++;
	}
	return (NULL);
}
