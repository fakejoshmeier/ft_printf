/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putllong_base_lc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 12:52:12 by jmeier            #+#    #+#             */
/*   Updated: 2017/11/29 12:01:28 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putullong_base_lc(unsigned long long n, unsigned long long b, int fd)
{
	unsigned long long	p;
	char				*c;

	p = 1;
	c = "0123456789abcdefghijklmnopqrstuvwxyz";
	while ((n / p) >= b)
		p *= b;
	b == 2 ? ft_putstr_fd("0b", fd) : 0;
	b == 8 ? ft_putstr_fd("0o", fd) : 0;
	b == 16 ? ft_putstr_fd("0x", fd) : 0;
	while (p > 0)
	{
		ft_putchar_fd(c[(n / p) % b], fd);
		p /= b;
	}
}
