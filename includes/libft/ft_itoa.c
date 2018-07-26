/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebaken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 11:46:55 by llebaken          #+#    #+#             */
/*   Updated: 2018/06/28 17:34:23 by llebaken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_length(int n)
{
	int			i;

	i = 0;
	if (n <= 0)
		i++;
	while (n)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char		*ptr;
	int			length;
	int			neg;
	long int	num;

	length = ft_length(n) - 1;
	num = (long int)n;
	neg = 0;
	if (!(ptr = ft_strnew(length + 1)))
		return (NULL);
	if (num < 0)
	{
		num = num * -1;
		neg = 1;
	}
	while (length >= 0)
	{
		ptr[length] = num % 10 + 48;
		num = num / 10;
		length--;
	}
	if (neg == 1)
		ptr[0] = '-';
	return (ptr);
}
