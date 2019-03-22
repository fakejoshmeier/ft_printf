/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 16:10:46 by jmeier            #+#    #+#             */
/*   Updated: 2019/03/21 18:41:35 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *a, char const *b)
{
	char		*c;
	unsigned	len;

	len = (a ? ft_strlen(a) : 0) + (b ? ft_strlen(b) : 0);
	NULL_GUARD(c = malloc(len + 1));
	c[len] = '\0';
	if (a)
		while (*a)
			*c++ = *a++;
	if (b)
		while (*b)
			*c++ = *b++;
	return (c - len);
}
