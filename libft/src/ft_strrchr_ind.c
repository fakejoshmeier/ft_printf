/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr_ind.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 15:50:38 by jmeier            #+#    #+#             */
/*   Updated: 2019/03/21 15:51:57 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strrchr_ind(const char *s, int c)
{
	int		i;

	i = ft_strlen(s) - 1;
	while (s[i] != (char)c && s[i] != '\0')
		--i;
	if (s[i] == (char)c)
		return (i);
	return (-1);
}
