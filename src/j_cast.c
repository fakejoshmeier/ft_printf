/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   j_cast.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 10:59:06 by jmeier            #+#    #+#             */
/*   Updated: 2019/10/18 16:52:57 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	j_int_cast(va_list arg, t_all *f)
{
	char		*prec_pad;
	char		*width_pad;
	char		*prefix;
	intmax_t	output;

	output = (intmax_t)va_arg(arg, void*);
	prec_pad = sign_prec_parse(output, f);
	width_pad = sign_width_parse(output, f);
	prefix = sign_prefix_parse((int)output, f);
	if (f->dash == 1)
	{
		ft_putstr(prefix);
		ft_putstr(prec_pad);
		ft_putnbrf((int)output, f->fd);
		ft_putstr(width_pad);
	}
	else
	{
		f->zero == 0 ? ft_putstr(width_pad) : 0;
		ft_putstr(prefix);
		f->zero == 1 && f->prec_flag == 0 ? ft_putstr(width_pad) : 0;
		ft_putstr(prec_pad);
		ft_putnbrf((int)output, f->fd);
	}
	supa_free(prec_pad, width_pad, prefix);
}

void	j_oct_cast(va_list arg, t_all *f)
{
	char		*prec_pad;
	char		*width_pad;
	char		*prefix;
	uintmax_t	output;

	output = (uintmax_t)va_arg(arg, void*);
	prec_pad = prec_parse(output, f, 8);
	width_pad = width_parse(output, f, 8);
	prefix = prefix_parse((unsigned int)output, 8, 0, f);
	if (f->dash == 1)
	{
		ft_putstr(prefix);
		ft_putstr(prec_pad);
		ft_putunbr_base(output, 8);
		ft_putstr(width_pad);
	}
	else
	{
		f->zero == 0 ? ft_putstr(width_pad) : 0;
		ft_putstr(prefix);
		f->zero == 1 && f->prec_flag == 0 ? ft_putstr(width_pad) : 0;
		ft_putstr(prec_pad);
		ft_putunbr_base(output, 8);
	}
	supa_free(prec_pad, width_pad, prefix);
}

void	j_hex_cast(va_list arg, t_all *f)
{
	char		*prec_pad;
	char		*width_pad;
	char		*prefix;
	uintmax_t	output;

	output = (uintmax_t)va_arg(arg, void*);
	prec_pad = prec_parse(output, f, 16);
	width_pad = width_parse(output, f, 16);
	prefix = prefix_parse((unsigned int)output, 16, 1, f);
	if (f->dash == 1)
	{
		ft_putstr(prefix);
		ft_putstr(prec_pad);
		ft_putunbr_base(output, 16);
		ft_putstr(width_pad);
	}
	else
	{
		f->zero == 0 ? ft_putstr(width_pad) : 0;
		ft_putstr(prefix);
		f->zero == 1 && f->prec_flag == 0 ? ft_putstr(width_pad) : 0;
		ft_putstr(prec_pad);
		ft_putunbr_base(output, 16);
	}
	supa_free(prec_pad, width_pad, prefix);
}

void	j_lhex_cast(va_list arg, t_all *f)
{
	char		*prec_pad;
	char		*width_pad;
	char		*prefix;
	uintmax_t	output;

	output = (uintmax_t)va_arg(arg, void*);
	prec_pad = prec_parse(output, f, 16);
	width_pad = width_parse(output, f, 16);
	prefix = prefix_parse((unsigned int)output, 16, 0, f);
	if (f->dash == 1)
	{
		ft_putstr(prefix);
		ft_putstr(prec_pad);
		ft_putunbr_base_lc(output, 16, 1);
		ft_putstr(width_pad);
	}
	else
	{
		f->zero == 0 ? ft_putstr(width_pad) : 0;
		ft_putstr(prefix);
		f->zero == 1 && f->prec_flag == 0 ? ft_putstr(width_pad) : 0;
		ft_putstr(prec_pad);
		ft_putunbr_base_lc(output, 16, 1);
	}
	supa_free(prec_pad, width_pad, prefix);
}

void	j_uint_cast(va_list arg, t_all *f)
{
	char		*prec_pad;
	char		*width_pad;
	char		*prefix;
	uintmax_t	output;

	output = (uintmax_t)va_arg(arg, void*);
	prec_pad = prec_parse(output, f, 10);
	width_pad = width_parse(output, f, 10);
	prefix = prefix_parse((unsigned int)output, 10, 0, f);
	if (f->dash == 1)
	{
		ft_putstr(prefix);
		ft_putstr(prec_pad);
		ft_putull((unsigned long long)output, f->fd);
		ft_putstr(width_pad);
	}
	else
	{
		f->zero == 0 ? ft_putstr(width_pad) : 0;
		ft_putstr(prefix);
		f->zero == 1 && f->prec_flag == 0 ? ft_putstr(width_pad) : 0;
		ft_putstr(prec_pad);
		ft_putull(output, f->fd);
	}
	supa_free(prec_pad, width_pad, prefix);
}
