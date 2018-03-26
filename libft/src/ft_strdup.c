/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/18 14:40:19 by jmeier            #+#    #+#             */
/*   Updated: 2018/03/25 23:14:37 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*newstr;
	int		j;

	j = 0;
	if (!(newstr = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1))))
		return (NULL);
	while (*str != '\0')
		newstr[j++] = *str++;
	newstr[j] = '\0';
	return (newstr);
}
