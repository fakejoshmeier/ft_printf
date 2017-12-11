/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_funcs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 23:02:49 by jmeier            #+#    #+#             */
/*   Updated: 2017/12/10 16:34:10 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	signed_w(t_flags *f, t_wp *g, int output)
{
	int		i;

	i = ft_numlen(output, 10);
	if (f->dash)
	{
		f->spess && output >= 0 ? ft_putchar(' ') : 0;
		f->plus && output >= 0 ? ft_putchar('+') : 0;
		output < 0 ? ft_putchar('-') : 0;
		ft_putnbrf(output);
		s_saver3(i, output, f, g);
	}
	else
	{
		s_saver3(i, output, f, g);
		f->spess && output >= 0 ? ft_putchar(' ') : 0;
		f->plus && output >= 0 ? ft_putchar('+') : 0;
		output < 0 ? ft_putchar('-') : 0;
		ft_putnbrf(output);
	}
}

void	signed_l_w(t_flags *f, t_wp *g, long output)
{
	int		i;

	i = ft_longlen(output, 10);
	if (f->dash)
	{
		f->spess && output >= 0 ? ft_putchar(' ') : 0;
		f->plus && output >= 0 ? ft_putchar('+') : 0;
		output < 0 ? ft_putchar('-') : 0;
		ft_putlong(output, 10, 1);
		s_saver3(i, (int)output, f, g);
	}
	else
	{
		s_saver3(i, output, f, g);
		f->spess && output >= 0 ? ft_putchar(' ') : 0;
		f->plus && output >= 0 ? ft_putchar('+') : 0;
		output < 0 ? ft_putchar('-') : 0;
		ft_putlong(output, 10, 1);
	}
}

void	signed_ll_w(t_flags *f, t_wp *g, long long output)
{
	int		i;

	i = ft_longlonglen(output, 10);
	if (f->dash)
	{
		f->spess && output >= 0 ? ft_putchar(' ') : 0;
		f->plus && output >= 0 ? ft_putchar('+') : 0;
		output < 0 ? ft_putchar('-') : 0;
		ft_putlong(output, 10, 1);
		s_saver3(i, (int)output, f, g);
	}
	else
	{
		s_saver3(i, output, f, g);
		f->spess && output >= 0 ? ft_putchar(' ') : 0;
		f->plus && output >= 0 ? ft_putchar('+') : 0;
		output < 0 ? ft_putchar('-') : 0;
		ft_putlong(output, 10, 1);
	}
}

void	unsigned_w_lc(t_flags *f, t_wp *g, unsigned int output, int b)
{
	int		i;

	i = ft_unumlen(output, b);
	if (f->dash)
	{
		f->hash && b == 8 ? ft_putchar('0') : 0;
		f->hash && b == 16 ? ft_putstr("0x") : 0;
		ft_putunbr_base_lc(output, b, 1);
		s_saver4(i, b, f, g);
	}
	else
	{
		(!f->zero) ? s_saver4(i, b, f, g) : 0;
		f->hash && b == 8 ? ft_putchar('0') : 0;
		f->hash && b == 16 ? ft_putstr("0x") : 0;
		(f->zero) ? s_saver4(i, b, f, g) : 0;
		ft_putunbr_base_lc(output, b, 1);
	}
}

void	char_w(t_flags *f, t_wp *g, char *output)
{
	char	*n;
	int		i;

	if (output != NULL)
		i = ft_strlen(output);
	else
		i = 6;
	n = "(null)";
	if (f->dash)
	{
		output != NULL ? ft_putstr(output) : ft_putstr(n);
		ft_putchars(' ', g->width - i);
	}
	else
	{
		ft_putchars(' ', g->width - i);
		output != NULL ? ft_putstr(output) : ft_putstr(n);
	}
}
