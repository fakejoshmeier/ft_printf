/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wp_funcs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 21:18:35 by jmeier            #+#    #+#             */
/*   Updated: 2017/12/11 23:18:54 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	signed_d_wp(t_all *f, int output)
{
	int		i;

	i = ft_numlen(output, 10);
	if (f->dash == 1)
	{
		f->spess && output > 0 ? ft_putchar(' ') : 0;
		f->plus && output >= 0 ? ft_putchar('+') : 0;
		output < 0 ? ft_putchar('-') : 0;
		if (output != 0 && f->prec != 0)
			i < f->prec ? ft_putchars('0', f->prec - i) : 0;
		output != 0 && f->prec != 0 ? ft_putnbrf(output) : 0;
		f->prec < f->width ? s_saver(i, output, ' ', f) : 0;
	}
	else if (f->dash == 0)
	{
		f->prec < f->width ? s_saver(i, output, ' ', f) : 0;
		f->spess && output > 0 ? ft_putchar(' ') : 0;
		f->plus && output >= 0 ? ft_putchar('+') : 0;
		output < 0 ? ft_putchar('-') : 0;
		if (output != 0 && f->prec != 0)
			i < f->prec ? ft_putchars('0', f->prec - i) : 0;
		output != 0 && f->prec != 0 ? ft_putnbrf(output) : 0;
	}
}

void	unsigned_wp(t_all *f, unsigned int output, int b)
{
	int		i;

	i = ft_unumlen(output, b);
	if (f->dash == 1)
	{
		f->hash == 1 && b == 8 ? ft_putchar('0') : 0;
		f->hash == 1 && b == 16 ? ft_putstr("0X") : 0;
		if (output != 0 && f->prec != 0)
			i < f->prec ? ft_putchars('0', f->prec - i) : 0;
		output != 0 && f->prec != 0 ? ft_putunbr_base(output, b) : 0;
		f->prec < f->width ? s_saver2(i, b, f) : 0;
	}
	else if (f->dash == 0)
	{
		f->prec < f->width ? s_saver2(i, b, f) : 0;
		f->hash == 1 && b == 8 ? ft_putchar('0') : 0;
		f->hash == 1 && b == 16 ? ft_putstr("0X") : 0;
		if (output != 0 && f->prec != 0)
			i < f->prec ? ft_putchars('0', f->prec - i) : 0;
		output != 0 && f->prec != 0 ? ft_putunbr_base(output, b) : 0;
	}
}
void	unsigned_wp_lc(t_all *f, unsigned int output, int b)
{
	int		i;

	i = ft_unumlen(output, b);
	if (f->dash == 1)
	{
		f->hash == 1 && b == 8 ? ft_putchar('0') : 0;
		f->hash == 1 && b == 16 ? ft_putstr("0x") : 0;
		if (output != 0 && f->prec != 0)
			i < f->prec ? ft_putchars('0', f->prec - i) : 0;
		output != 0 && f->prec != 0 ? ft_putunbr_base_lc(output, b, 1) : 0;
		f->prec < f->width && i < f->width ? s_saver2(i, b, f) : 0;
	}
	else if (f->dash == 0)
	{
		f->prec < f->width && i < f->width ? s_saver2(i, b, f) : 0;
		f->hash == 1 && b == 8 ? ft_putchar('0') : 0;
		f->hash == 1 && b == 16 ? ft_putstr("0x") : 0;
		if (output != 0 && f->prec != 0)
			i < f->prec ? ft_putchars('0', f->prec - i) : 0;
		output != 0 && f->prec != 0 ? ft_putunbr_base_lc(output, b, 1) : 0;
	}
}

void	signed_l_wp(t_all *f, long output)
{
	int		i;

	i = ft_longlen(output, 10);
	if (f->dash == 1)
	{
		f->spess == 1 && output > 0 ? ft_putchar(' ') : 0;
		f->plus == 1 && output >= 0 ? ft_putchar('+') : 0;
		output < 0 ? ft_putchar('-') : 0;
		if (output != 0 && f->prec != 0)
			i < f->prec ? ft_putchars('0', f->prec - i) : 0;
		output != 0 && f->prec != 0 ? ft_putlong((long)output, 10, 1) : 0;
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
		output != 0 && f->prec != 0 ? ft_putlong((long)output, 10, 1) : 0;
	}
}

void	char_wp(t_all *f, char *out)
{
	char	*n;
	int		i;

	n = "(null)";
	(out != NULL) ? i = ft_strlen(out) : 0;
	out == NULL ? i = 6 : 0;
	if (f->dash == 1)
	{
		if (f->prec != 0)
			out != NULL ? ft_putstrn(out, f->prec) : ft_putstrn(n, f->prec);
		if (f->prec >= i)
			ft_putchars(' ', f->width - i);
		else if (i > f->prec)
			f->zero ? ft_putchars('0', f->width - f->prec) :
				ft_putchars(' ', f->width - f->prec);
	}
	else if (f->dash == 0)
	{
		if (f->prec >= i)
			ft_putchars(' ', f->width - i);
		else
			ft_putchars(' ', f->width - f->prec);
		if (f->prec != 0)
			out != NULL ? ft_putstrn(out, f->prec) : ft_putstrn(n, f->prec);
	}
}
