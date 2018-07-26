/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebaken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 11:28:33 by llebaken          #+#    #+#             */
/*   Updated: 2018/06/28 17:12:07 by llebaken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*s1;
	const char	*s2;
	size_t		i;

	i = 0;
	s1 = (char*)dst;
	s2 = (char*)src;
	while (i < n)
	{
		s1[i] = s2[i];
		i++;
	}
	return (dst);
}
