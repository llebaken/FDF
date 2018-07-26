/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebaken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 14:15:22 by llebaken          #+#    #+#             */
/*   Updated: 2018/06/28 17:22:55 by llebaken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*str;

	str = NULL;
	i = 0;
	if (s)
	{
		str = (char *)malloc(ft_strlen(s) + 1);
		if (!str)
			return (NULL);
		while (s[i])
		{
			str[i] = f((unsigned int)i, s[i]);
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}
