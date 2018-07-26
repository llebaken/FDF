/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebaken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 14:15:12 by llebaken          #+#    #+#             */
/*   Updated: 2018/06/28 17:22:40 by llebaken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*str;

	i = 0;
	str = NULL;
	if (s)
	{
		str = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
		if (!str)
			return (NULL);
		while (s[i])
		{
			str[i] = f((char)s[i]);
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}
