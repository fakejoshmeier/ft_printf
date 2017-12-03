/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlong_lc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 12:52:12 by jmeier            #+#    #+#             */
/*   Updated: 2017/12/02 20:42:29 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putlong_lc(unsigned long n, unsigned long b, int fd)
{
	long	p;
	char	*c;

	p = 1;
	c = "0123456789abcdefghijklmnopqrstuvwxyz";
	while ((n / p) >= b)
		p *= b;
/*
** b == 2 ? ft_putstr_fd("0b", fd) : 0;
** b == 8 ? ft_putstr_fd("0o", fd) : 0;
** b == 16 ? ft_putstr_fd("0x", fd) : 0;
*/
	while (p > 0)
	{
		ft_putchar_fd(c[(n / p) % b], fd);
		p /= b;
	}
}
