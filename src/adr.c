/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adr.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 19:47:02 by jmeier            #+#    #+#             */
/*   Updated: 2019/10/17 17:28:23 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	putadr(unsigned long n, t_all *f)
{
	if (n > 15)
	{
		putadr((n / 16), f);
		putadr((n % 16), f);
	}
	else if (n < 10)
	{
		f->adr += 1;
		ft_putchar_fd(n + '0', f->fd);
	}
	else
	{
		n == 10 ? ft_putchar_fd('a', f->fd) : 0;
		n == 11 ? ft_putchar_fd('b', f->fd) : 0;
		n == 12 ? ft_putchar_fd('c', f->fd) : 0;
		n == 13 ? ft_putchar_fd('d', f->fd) : 0;
		n == 14 ? ft_putchar_fd('e', f->fd) : 0;
		n == 15 ? ft_putchar_fd('f', f->fd) : 0;
		f->adr += 1;
	}
}

void	address(va_list arg, t_all *f)
{
	void			*output;
	unsigned long	adr;

	output = va_arg(arg, void*);
	adr = (unsigned long)(output);
	write(f->fd, "0x", 2);
	f->adr += 2;
	putadr(adr, f);
}

void	ntame(va_list arg, t_all *f)
{
	int		skip;

	skip = va_arg(arg, int);
	ft_putnbr_fd(f->adr, f->fd);
	f->adr += (ft_numlen(f->adr, 10));
	f->adr += (ft_numlen(skip, 10));
}
