/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wp_funcs2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 19:52:42 by jmeier            #+#    #+#             */
/*   Updated: 2017/12/11 22:09:25 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	unsigned_l_wp(t_all *f, unsigned long output, int b)
{
	int		i;

	i = ft_ulonglen(output, b);
	if (f->dash == 1)
	{
		f->hash == 1 && b == 8 ? ft_putchar('0') : 0;
		f->hash == 1 && b == 16 ? ft_putstr("0X") : 0;
		if (output != 0 && f->prec != 0)
			i < f->prec ? ft_putchars('0', f->prec - i) : 0;
		output != 0 && f->prec != 0 ? ft_putulong(output, b, 1) : 0;
		f->prec < f->width ? s_saver2(i, b, f) : 0;
	}
	else if (f->dash == 0)
	{
		f->prec < f->width ? s_saver2(i, b, f) : 0;
		f->hash == 1 && b == 8 ? ft_putchar('0') : 0;
		f->hash == 1 && b == 16 ? ft_putstr("0X") : 0;
		if (output != 0 && f->prec != 0)
			i < f->prec ? ft_putchars('0', f->prec - i) : 0;
		output != 0 && f->prec != 0 ? ft_putulong(output, b, 1) : 0;
	}
}

void	unsigned_l_wp_lc(t_all *f, unsigned long output, int b)
{
	int		i;

	i = ft_ulonglen(output, b);
	if (f->dash == 1)
	{
		f->hash == 1 && b == 8 ? ft_putchar('0') : 0;
		f->hash == 1 && b == 16 ? ft_putstr("0x") : 0;
		if (output != 0 && f->prec != 0)
			i < f->prec ? ft_putchars('0', f->prec - i) : 0;
		output != 0 && f->prec != 0 ? ft_putlong_lc(output, b, 1) : 0;
		f->prec < f->width ? s_saver2(i, b, f) : 0;
	}
	else if (f->dash == 0)
	{
		f->prec < f->width ? s_saver2(i, b, f) : 0;
		f->hash == 1 && b == 8 ? ft_putchar('0') : 0;
		f->hash == 1 && b == 16 ? ft_putstr("0x") : 0;
		if (output != 0 && f->prec != 0)
			i < f->prec ? ft_putchars('0', f->prec - i) : 0;
		output != 0 && f->prec != 0 ? ft_putlong_lc(output, b, 1) : 0;
	}
}

void	signed_ll_wp(t_all *f, long long output)
{
	int		i;

	i = ft_longlonglen(output, 10);
	if (f->dash == 1)
	{
		f->spess == 1 && output > 0 ? ft_putchar(' ') : 0;
		f->plus == 1 && output >= 0 ? ft_putchar('+') : 0;
		output < 0 ? ft_putchar('-') : 0;
		if (output != 0 && f->prec != 0)
			i < f->prec ? ft_putchars('0', f->prec - i) : 0;
		output != 0 && f->prec != 0 ? ft_putlonglong(output, 10, 1) : 0;
		f->prec < f->width ? s_saver(i, (int)output, ' ', f) : 0;
	}
	else if (f->dash == 0)
	{
		f->prec < f->width ? s_saver(i, output, ' ', f) : 0;
		f->spess == 1 && output > 0 ? ft_putchar(' ') : 0;
		f->plus == 1 && output >= 0 ? ft_putchar('+') : 0;
		output < 0 ? ft_putchar('-') : 0;
		if (output != 0 && f->prec != 0)
			i < f->prec ? ft_putchars('0', f->prec - i) : 0;
		output != 0 && f->prec != 0 ? ft_putlonglong(output, 10, 1) : 0;
	}
}

void	unsigned_ll_wp(t_all *f, unsigned long long output, int b)
{
	int		i;

	i = ft_ulonglonglen(output, b);
	if (f->dash == 1)
	{
		f->hash == 1 && b == 8 ? ft_putchar('0') : 0;
		f->hash == 1 && b == 16 ? ft_putstr("0X") : 0;
		if (output != 0 && f->prec != 0)
			i < f->prec ? ft_putchars('0', f->prec - i) : 0;
		output != 0 && f->prec != 0 ? ft_putulonglong(output, b, 1) : 0;
		f->prec < f->width ? s_saver2(i, b, f) : 0;
	}
	else if (f->dash == 0)
	{
		f->prec < f->width ? s_saver2(i, b, f) : 0;
		f->hash == 1 && b == 8 ? ft_putchar('0') : 0;
		f->hash == 1 && b == 16 ? ft_putstr("0X") : 0;
		if (output != 0 && f->prec != 0)
			i < f->prec ? ft_putchars('0', f->prec - i) : 0;
		output != 0 && f->prec != 0 ? ft_putulonglong(output, b, 1) : 0;
	}
}

void	unsigned_ll_wp_lc(t_all *f, unsigned long long output, int b)
{
	int		i;

	i = ft_ulonglonglen(output, b);
	if (f->dash == 1)
	{
		f->hash == 1 && b == 8 ? ft_putchar('0') : 0;
		f->hash == 1 && b == 16 ? ft_putstr("0x") : 0;
		if (output != 0 && f->prec != 0)
			i < f->prec ? ft_putchars('0', f->prec - i) : 0;
		output != 0 && f->prec != 0 ? ft_putlonglong_lc(output, b, 1) : 0;
		f->prec < f->width ? s_saver2(i, b, f) : 0;
	}
	else if (f->dash == 0)
	{
		f->prec < f->width ? s_saver2(i, b, f) : 0;
		f->hash == 1 && b == 8 ? ft_putchar('0') : 0;
		f->hash == 1 && b == 16 ? ft_putstr("0x") : 0;
		if (output != 0 && f->prec != 0)
			i < f->prec ? ft_putchars('0', f->prec - i) : 0;
		output != 0 && f->prec != 0 ? ft_putlonglong_lc(output, b, 1) : 0;
	}
}