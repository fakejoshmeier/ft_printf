/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_h_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 10:59:06 by jmeier            #+#    #+#             */
/*   Updated: 2017/12/11 22:36:52 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	w_h_int_cast(va_list arg, t_all *f)
{
	short			output;

	output = (short)va_arg(arg, void*);
	signed_w(f, output);
}

void	w_h_oct_cast(va_list arg, t_all *f)
{
	unsigned short	output;

	output = (unsigned short)va_arg(arg, void*);
	unsigned_w(f, (unsigned int)output, 8);
}

void	w_h_hex_cast(va_list arg, t_all *f)
{
	unsigned short	output;

	output = (unsigned short)va_arg(arg, void*);
	unsigned_w(f, (unsigned int)output, 16);
}

void	w_h_lhex_cast(va_list arg, t_all *f)
{
	unsigned short	output;

	output = (unsigned short)va_arg(arg, void*);
	unsigned_w_lc(f, (unsigned int)output, 16);
}

void	w_h_uint_cast(va_list arg, t_all *f)
{
	unsigned short	output;

	output = (unsigned short)va_arg(arg, void*);
	unsigned_w(f, (unsigned int)output, 10);
}
