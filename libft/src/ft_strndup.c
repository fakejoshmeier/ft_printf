/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/24 23:22:42 by jmeier            #+#    #+#             */
/*   Updated: 2019/04/17 23:01:07 by jmeier           ###   ########.fr       */
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
		ret[i++] = *src++;
		if (*src == '\0')
			break ;
	}
	ret[i] = '\0';
	return (ret);
}
