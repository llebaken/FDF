/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebaken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/22 12:26:23 by llebaken          #+#    #+#             */
/*   Updated: 2018/06/28 17:35:38 by llebaken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)ft_memalloc(len + 1);
	if (!str)
		return (NULL);
	if (s)
		while (s[start + i] && i < len)
		{
			str[i] = s[start + i];
			i++;
		}
	return (str);
}
