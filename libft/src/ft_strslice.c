/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strslice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 23:29:37 by jmeier            #+#    #+#             */
/*   Updated: 2019/05/02 16:11:15 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** A function to rip out chunks of a string and returns them as a new string
** If len = 0, then it grabs everything from idx to the end
** Starting idx is always 0;
*/

char	*ft_strslice(const char *src, int idx, int len)
{
	char	*ret;
	int		src_len;
	int		i;

	src_len = ft_strlen(src);
	if (idx + len > src_len || len == 0)
		return (NULL);
	ret = (char *)malloc(sizeof(char) * len + 1);
	i = 0;
	while (idx < src_len && src[idx])
	{
		if (len > 0 && i >= len)
			break ;
		ret[i++] = src[idx++];
	}
	ret[i]= '\0';
	return (ret);
}
