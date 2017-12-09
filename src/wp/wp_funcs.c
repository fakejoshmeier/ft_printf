/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wp_funcs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 21:18:35 by jmeier            #+#    #+#             */
/*   Updated: 2017/12/08 23:47:55 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	signed_d_wp(t_flags *f, t_wp *g, int output)
{
	int		i;

	i = ft_numlen(output, 10);
	if (f.dash)
	{
		f.spess && output > 0 ? ft_putchar(' ') : 0;
		f.plus && output >= 0 ? ft_putchar('+') : 0;
		(f.plus || f.spess) && output < 0 ? ft_putchar('-') : 0;
		if (output != 0 && g.prec != 0)
			i < g.prec ? ft_putchars('0', g.prec - i) : 0;
		output != 0 && g.prec != 0 ? ft_putnbrf(output) : 0;
		g.prec < g.width ? s_saver(i, output, ' ', f, g) : 0;
	}
	else if (!f.dash)
	{
		g.prec < g.width ? s_saver(i, output, ' ', f, g) : 0;
		f.spess && output > 0 ? ft_putchar(' ') : 0;
		f.plus && output >= 0 ? ft_putchar('+') : 0;
		(f.plus || f.spess) && output < 0 ? ft_putchar('-') : 0;
		if (output != 0 && g.prec != 0)
			i < g.prec ? ft_putchars('0', g.prec - i) : 0;
		output != 0 && g.prec != 0 ? ft_putnbrf(output) : 0;
	}
}

void	unsigned_wp(t_flags *f, t_wp *g, unsigned int output, int b)
{
	int		i;

	i = ft_unumlen(output, b);
	if (f.dash)
	{
		f.hash && b == 8 ? ft_putchar('0') : 0;
		f.hash && b == 16 ? ft_putstr("0X") : 0;
		if (output != 0 && g.prec != 0)
			i < g.prec ? ft_putchars('0', g.prec - i) : 0;
		output != 0 && g.prec != 0 ? ft_putunbr_base(output, b) : 0;
		g.prec < g.width ? s_saver(i, output, ' ', f, g) : 0;
	}
	else if (!f.dash)
	{
		g.prec < g.width ? s_saver(i, output, ' ', f, g) : 0;
		f.hash && b == 8 ? ft_putchar('0') : 0;
		f.hash && b == 16 && c ? ft_putstr("0X") : 0;
		if (output != 0 && g.prec != 0)
			i < g.prec ? ft_putchars('0', g.prec - i) : 0;
		output != 0 && g.prec != 0 ? ft_putunbr_base(output, b) : 0
	}
}
void	unsigned_wp_lc(t_flags *f, t_wp *g, unsigned int output, int b)
{
	int		i;

	i = ft_unumlen(output, b);
	if (f.dash)
	{
		f.hash && b == 8 ? ft_putchar('0') : 0;
		f.hash && b == 16 ? ft_putstr("0x") : 0;
		if (output != 0 && g.prec != 0)
			i < g.prec ? ft_putchars('0', g.prec - i) : 0;
		output != 0 && g.prec != 0 ? ft_putunbr_base_lc(output, b, 1) : 0;
		g.prec < g.width && i < g.width ? s_saver(i, output, ' ', f, g) : 0;
	}
	else if (!f.dash)
	{
		g.prec < g.width && i < g.width ? s_saver2(i, output, ' ', f, g) : 0;
		f.hash && b == 8 ? ft_putchar('0') : 0;
		f.hash && b == 16 && c ? ft_putstr("0x") : 0;
		if (output != 0 && g.prec != 0)
			i < g.prec ? ft_putchars('0', g.prec - i) : 0;
		output != 0 && g.prec != 0 ? ft_putunbr_base_lc(output, b, 1) : 0
	}
}

