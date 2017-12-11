/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_h_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 10:59:06 by jmeier            #+#    #+#             */
/*   Updated: 2017/12/10 01:08:46 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	w_h_int_cast(va_list arg, t_flags *f, t_wp *g)
{
	short			output;

	output = (short)va_arg(arg, void*);
	signed_w(f, g, output);
}

void	w_h_oct_cast(va_list arg, t_flags *f, t_wp *g)
{
	unsigned short	output;

	output = (unsigned short)va_arg(arg, void*);
	unsigned_w(f, g, (unsigned int)output, 8);
}

void	w_h_hex_cast(va_list arg, t_flags *f, t_wp *g)
{
	unsigned short	output;

	output = (unsigned short)va_arg(arg, void*);
	unsigned_w(f, g, (unsigned int)output, 16);
}

void	w_h_lhex_cast(va_list arg, t_flags *f, t_wp *g)
{
	unsigned short	output;

	output = (unsigned short)va_arg(arg, void*);
	unsigned_w_lc(f, g, (unsigned int)output, 16);
}

void	w_h_uint_cast(va_list arg, t_flags *f, t_wp *g)
{
	unsigned short	output;

	output = (unsigned short)va_arg(arg, void*);
	unsigned_w(f, g, (unsigned int)output, 10);
}
