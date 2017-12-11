/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 14:09:59 by jmeier            #+#    #+#             */
/*   Updated: 2017/12/09 21:35:13 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchars(char c, int amt)
{
	char	*buf;
	int		i;

	if (amt < 0)
		amt = 0;
	buf = (char *)malloc(sizeof(char *) * amt);
	if (!buf)
		return ;
	i = -1;
	while (buf[++i])
		buf[i] = c;
	ft_putstr(buf);
	ft_free(buf);
}
