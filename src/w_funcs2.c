/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_funcs2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 23:02:49 by jmeier            #+#    #+#             */
/*   Updated: 2017/12/10 16:35:04 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	unsigned_w(t_flags *f, t_wp *g, unsigned int output, int b)
{
	int		i;

	i = ft_unumlen(output, b);
	if (f->dash)
	{
		f->hash && b == 8 ? ft_putchar('0') : 0;
		f->hash && b == 16 ? ft_putstr("0X") : 0;
		ft_putunbr_base(output, b);
		s_saver4(i, b, f, g);
	}
	else
	{
		(!f->zero) ? s_saver4(i, b, f, g) : 0;
		f->hash && b == 8 ? ft_putchar('0') : 0;
		f->hash && b == 16 ? ft_putstr("0X") : 0;
		(f->zero) ? s_saver4(i, b, f, g) : 0;
		ft_putunbr_base(output, b);
	}
}

void	unsigned_l_w(t_flags *f, t_wp *g, unsigned long output, int b)
{
	int		i;

	i = ft_ulonglen(output, b);
	if (f->dash)
	{
		f->hash && b == 8 ? ft_putchar('0') : 0;
		f->hash && b == 16 ? ft_putstr("0X") : 0;
		ft_putulong(output, b, 1);
		s_saver4(i, b, f, g);
	}
	else
	{
		(!f->zero) ? s_saver4(i, b, f, g) : 0;
		f->hash && b == 8 ? ft_putchar('0') : 0;
		f->hash && b == 16 ? ft_putstr("0X") : 0;
		(f->zero) ? s_saver4(i, b, f, g) : 0;
		ft_putulong(output, b, 1);
	}
}

void	unsigned_ll_w(t_flags *f, t_wp *g, unsigned long long output, int b)
{
	int		i;

	i = ft_ulonglonglen(output, b);
	if (f->dash)
	{
		f->hash && b == 8 ? ft_putchar('0') : 0;
		f->hash && b == 16 ? ft_putstr("0X") : 0;
		ft_putulonglong(output, b, 1);
		s_saver4(i, b, f, g);
	}
	else
	{
		(!f->zero) ? s_saver4(i, b, f, g) : 0;
		f->hash && b == 8 ? ft_putchar('0') : 0;
		f->hash && b == 16 ? ft_putstr("0X") : 0;
		(f->zero) ? s_saver4(i, b, f, g) : 0;
		ft_putulonglong(output, b, 1);
	}
}

void	unsigned_l_w_lc(t_flags *f, t_wp *g, unsigned long output, int b)
{
	int		i;

	i = ft_ulonglen(output, b);
	if (f->dash)
	{
		f->hash && b == 8 ? ft_putchar('0') : 0;
		f->hash && b == 16 ? ft_putstr("0x") : 0;
		ft_putlong_lc(output, b, 1);
		s_saver4(i, b, f, g);
	}
	else
	{
		(!f->zero) ? s_saver4(i, b, f, g) : 0;
		f->hash && b == 8 ? ft_putchar('0') : 0;
		f->hash && b == 16 ? ft_putstr("0x") : 0;
		(f->zero) ? s_saver4(i, b, f, g) : 0;
		ft_putlong_lc(output, b, 1);
	}
}

void	unsigned_ll_w_lc(t_flags *f, t_wp *g, unsigned long long output, int b)
{
	int		i;

	i = ft_ulonglonglen(output, b);
	if (f->dash)
	{
		f->hash && b == 8 ? ft_putchar('0') : 0;
		f->hash && b == 16 ? ft_putstr("0x") : 0;
		ft_putlonglong_lc(output, b, 1);
		s_saver4(i, b, f, g);
	}
	else
	{
		(!f->zero) ? s_saver4(i, b, f, g) : 0;
		f->hash && b == 8 ? ft_putchar('0') : 0;
		f->hash && b == 16 ? ft_putstr("0x") : 0;
		(f->zero) ? s_saver4(i, b, f, g) : 0;
		ft_putlonglong_lc(output, b, 1);
	}
}
