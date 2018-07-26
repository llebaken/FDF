/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llebaken <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 12:26:24 by llebaken          #+#    #+#             */
/*   Updated: 2018/06/28 17:33:28 by llebaken         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t			ft_wordcount(char const *s, char c)
{
	int					i;
	size_t				words;

	i = 0;
	words = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			while (s[i] && s[i] != c)
				i++;
			words++;
		}
	}
	return (words);
}

char					**ft_strsplit(char const *s, char c)
{
	char				**str;
	size_t				word;
	int					i;
	int					start;

	if (!s || !(str = (char **)malloc(sizeof(char *) * (ft_wordcount(s, c)
		+ 1))))
		return (NULL);
	i = 0;
	word = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			start = i;
			while (s[i] && s[i] != c)
				i++;
			str[word] = ft_strsub(s, start, i - start);
			word++;
		}
	}
	str[word] = NULL;
	return (str);
}
