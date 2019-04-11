/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 23:22:42 by jmeier            #+#    #+#             */
/*   Updated: 2018/08/24 23:31:07 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strndup(const char *src, int len)
{
	char	*ret;
	int		i;

	i = 0;
	NULL_GUARD(ret = ft_strnew(len));
	while (i < len)
	{
		*ret++ = *src++;
		if (*src == '\0')
			break ;
		++i;
	}
	*ret = '\0';
	return (ret);
}
