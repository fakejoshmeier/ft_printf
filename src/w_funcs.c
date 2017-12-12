/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_funcs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 23:02:49 by jmeier            #+#    #+#             */
/*   Updated: 2017/12/12 00:48:13 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	signed_w(t_all *f, int output)
{
	int		i;

	i = ft_numlen(output, 10);
	if (f->dash == 1)
	{
		f->spess == 1 && output >= 0 ? ft_putchar(' ') : 0;
		f->plus == 1 && output >= 0 ? ft_putchar('+') : 0;
		output < 0 ? ft_putchar('-') : 0;
		ft_putnbrf(output);
		s_saver3(i, output, f);
	}
	else
	{
		s_saver3(i, output, f);
		f->spess == 1 && output >= 0 ? ft_putchar(' ') : 0;
		f->plus == 1 && output >= 0 ? ft_putchar('+') : 0;
		output < 0 ? ft_putchar('-') : 0;
		ft_putnbrf(output);
	}
}

void	signed_l_w(t_all *f, long output)
{
	int		i;

	i = ft_longlen(output, 10);
	if (f->dash == 1)
	{
		f->spess == 1 && output >= 0 ? ft_putchar(' ') : 0;
		f->plus == 1 && output >= 0 ? ft_putchar('+') : 0;
		output < 0 ? ft_putchar('-') : 0;
		ft_putlong(output, 10, 1);
		s_saver3(i, (int)output, f);
	}
	else
	{
		s_saver3(i, (int)output, f);
		f->spess == 1 && output >= 0 ? ft_putchar(' ') : 0;
		f->plus == 1 && output >= 0 ? ft_putchar('+') : 0;
		output < 0 ? ft_putchar('-') : 0;
		ft_putlong(output, 10, 1);
	}
}

void	signed_ll_w(t_all *f, long long output)
{
	int		i;

	i = ft_longlonglen(output, 10);
	if (f->dash == 1)
	{
		f->spess == 1 && output >= 0 ? ft_putchar(' ') : 0;
		f->plus == 1 && output >= 0 ? ft_putchar('+') : 0;
		output < 0 ? ft_putchar('-') : 0;
		ft_putlonglong(output, 10, 1);
		s_saver3(i, (int)output, f);
	}
	else
	{
		s_saver3(i, (int)output, f);
		f->spess == 1 && output >= 0 ? ft_putchar(' ') : 0;
		f->plus == 1 && output >= 0 ? ft_putchar('+') : 0;
		output < 0 ? ft_putchar('-') : 0;
		ft_putlonglong(output, 10, 1);
	}
}

void	unsigned_w_lc(t_all *f, unsigned int output, int b)
{
	int		i;

	i = ft_unumlen(output, b);
	if (f->dash == 1)
	{
		f->hash == 1 && b == 8 && output != 0 ? ft_putchar('0') : 0;
		f->hash == 1 && b == 16 && output != 0 ? ft_putstr("0x") : 0;
		b == 8 ? ft_putoct(output) : 0;
		b == 16 ? ft_putlhex(output) : 0;
		b == 10 ? ft_putunbr_base(output, 10) : 0;
		s_saver4(i, b, f);
	}
	else
	{
		f->zero == 0 ? s_saver4(i, b, f) : 0;
		f->hash == 1 && b == 8 ? ft_putchar('0') : 0;
		f->hash == 1 && b == 16 ? ft_putstr("0x") : 0;
		f->zero == 1 ? s_saver4(i, b, f) : 0;
		b == 8 ? ft_putoct(output) : 0;
		b == 16 ? ft_putlhex(output) : 0;
		b == 10 ? ft_putunbr_base(output, 10) : 0;
	}
}

void	char_w(t_all *f, char *output)
{
	char	*n;
	int		i;

	if (output != NULL)
		i = ft_strlen(output);
	else
		i = 6;
	n = "(null)";
	if (f->dash == 1)
	{
		output != NULL ? ft_putstr(output) : ft_putstr(n);
		ft_putchars(' ', f->width - i);
	}
	else
	{
		ft_putchars(' ', f->width - i);
		output != NULL ? ft_putstr(output) : ft_putstr(n);
	}
}
