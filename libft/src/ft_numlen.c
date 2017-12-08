/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 16:19:51 by jmeier            #+#    #+#             */
/*   Updated: 2017/12/08 14:36:32 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_numlen(int n, int base)
{
	int		len;
	long	nb;

	len = 0;
	nb = (long)n;
	if (nb <= 0)
	{
		len++;
		nb *= -1;
	}
	while (nb != 0)
	{
		len++;
		nb /= base;
	}
	return (len);
}
