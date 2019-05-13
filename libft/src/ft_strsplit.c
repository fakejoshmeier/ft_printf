/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/25 16:10:03 by jmeier            #+#    #+#             */
/*   Updated: 2019/05/13 01:13:53 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		word_size(const char *chr, char d)
{
	int size;

	size = 0;
	while (*chr && *chr != d)
	{
		++size;
		++chr;
	}
	return (size);
}

static size_t	num_words(const char *str, char d)
{
	size_t num;

	num = 0;
	while (*str)
	{
		if (*str != d && (*(str + 1) == d || *(str + 1) == '\0'))
			++num;
		++str;
	}
	return (num);
}

char			**ft_strsplit(char const *str, char c)
{
	char		**split_words;
	size_t		size;
	size_t		w_size;
	unsigned	w;
	unsigned	chr;

	NULL_GUARD(str);
	size = num_words(str, c) + 1;
	NULL_GUARD(split_words = (char **)malloc(sizeof(char*) * size));
	w = 0;
	while (w < size - 1)
	{
		while (*str == c)
			++str;
		w_size = word_size(str, c);
		split_words[w] = malloc(w_size + 1);
		NULL_GUARD(split_words[w]);
		split_words[w][w_size] = '\0';
		chr = 0;
		while (chr < w_size)
			split_words[w][chr++] = *str++;
		++w;
	}
	split_words[size - 1] = 0;
	return (split_words);
}
