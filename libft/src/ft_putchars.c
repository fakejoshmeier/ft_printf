/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 14:09:59 by jmeier            #+#    #+#             */
/*   Updated: 2017/12/08 14:30:57 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchars(char c, int amt)
{
	char	*buf;
	int		i;

	buf = (char *)malloc(sizeof(char *) * amt);
	i = -1;
	while (buf[++i])
		buf[i] = c;
	ft_putstr(buf);
	ft_free(buf);
}
