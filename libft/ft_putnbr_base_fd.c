/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 12:52:12 by jmeier            #+#    #+#             */
/*   Updated: 2017/11/21 11:43:19 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base_fd(int n, int base, int fd)
{
	int		p;
	char	*c;

	p = 1;
	c = "0123456789ABCDEFHIJKLMNOPQRSTUVWXYZ";
	while ((n / p) >= base || (n / p) <= -base)
		p *= base;
	if (n < 0)
		ft_putchar_fd('-', fd);
	base == 2 ? ft_putstr_fd("0b", fd) : 0;
	base == 8 ? ft_putstr_fd("0o", fd) : 0;
	base == 16 ? ft_putstr_fd("0x", fd) : 0;
	while (p > 0)
	{
		ft_putchar_fd(c[(n / p) % base], fd);
		p /= base;
	}
}
