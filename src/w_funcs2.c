/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_funcs2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 23:02:49 by jmeier            #+#    #+#             */
/*   Updated: 2017/12/12 00:47:50 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	unsigned_w(t_all *f, unsigned int output, int b)
{
	int		i;

	i = ft_unumlen(output, b);
	if (f->dash == 1)
	{
		f->hash == 1 && b == 8 && output != 0 ? ft_putchar('0') : 0;
		f->hash == 1 && b == 16 && output != 0 ? ft_putstr("0X") : 0;
		b == 8 ? ft_putoct(output) : 0;
		b == 16 ? ft_puthex(output) : 0;
		b == 10 ? ft_putunbr_base(output, 10) : 0;
		s_saver4(i, b, f);
	}
	else
	{
		f->zero == 0 ? s_saver4(i, b, f) : 0;
		f->hash == 1 && b == 8 && output != 0 ? ft_putchar('0') : 0;
		f->hash == 1 && b == 16 && output != 0 ? ft_putstr("0X") : 0;
		(f->zero) ? s_saver4(i, b, f) : 0;
		b == 8 ? ft_putoct(output) : 0;
		b == 16 ? ft_puthex(output) : 0;
		b == 10 ? ft_putunbr_base(output, 10) : 0;
	}
}

void	unsigned_l_w(t_all *f, unsigned long output, int b)
{
	int		i;

	i = ft_ulonglen(output, b);
	if (f->dash == 1)
	{
		f->hash == 1 && b == 8 ? ft_putchar('0') : 0;
		f->hash == 1 && b == 16 ? ft_putstr("0X") : 0;
		ft_putulong(output, b, 1);
		s_saver4(i, b, f);
	}
	else
	{
		f->zero == 0 ? s_saver4(i, b, f) : 0;
		f->hash == 1 && b == 8 ? ft_putchar('0') : 0;
		f->hash == 1 && b == 16 ? ft_putstr("0X") : 0;
		(f->zero) ? s_saver4(i, b, f) : 0;
		ft_putulong(output, b, 1);
	}
}

void	unsigned_ll_w(t_all *f, unsigned long long output, int b)
{
	int		i;

	i = ft_ulonglonglen(output, b);
	if (f->dash == 1)
	{
		f->hash == 1 && b == 8 ? ft_putchar('0') : 0;
		f->hash == 1 && b == 16 ? ft_putstr("0X") : 0;
		ft_putulonglong(output, b, 1);
		s_saver4(i, b, f);
	}
	else
	{
		f->zero == 0 ? s_saver4(i, b, f) : 0;
		f->hash == 1 && b == 8 ? ft_putchar('0') : 0;
		f->hash == 1 && b == 16 ? ft_putstr("0X") : 0;
		f->zero == 1 ? s_saver4(i, b, f) : 0;
		ft_putulonglong(output, b, 1);
	}
}

void	unsigned_l_w_lc(t_all *f, unsigned long output, int b)
{
	int		i;

	i = ft_ulonglen(output, b);
	if (f->dash == 1)
	{
		f->hash == 1 && b == 8 ? ft_putchar('0') : 0;
		f->hash == 1 && b == 16 ? ft_putstr("0x") : 0;
		ft_putlong_lc(output, b, 1);
		s_saver4(i, b, f);
	}
	else
	{
		f->zero == 0 ? s_saver4(i, b, f) : 0;
		f->hash == 1 && b == 8 ? ft_putchar('0') : 0;
		f->hash == 1 && b == 16 ? ft_putstr("0x") : 0;
		f->zero == 1 ? s_saver4(i, b, f) : 0;
		ft_putlong_lc(output, b, 1);
	}
}

void	unsigned_ll_w_lc(t_all *f, unsigned long long output, int b)
{
	int		i;

	i = ft_ulonglonglen(output, b);
	if (f->dash == 1)
	{
		f->hash == 1 && b == 8 ? ft_putchar('0') : 0;
		f->hash == 1 && b == 16 ? ft_putstr("0x") : 0;
		ft_putlonglong_lc(output, b, 1);
		s_saver4(i, b, f);
	}
	else
	{
		f->zero == 0 ? s_saver4(i, b, f) : 0;
		f->hash == 1 && b == 8 ? ft_putchar('0') : 0;
		f->hash == 1 && b == 16 ? ft_putstr("0x") : 0;
		f->zero == 1 ? s_saver4(i, b, f) : 0;
		ft_putlonglong_lc(output, b, 1);
	}
}
