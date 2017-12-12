/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_hh_cast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 10:59:06 by jmeier            #+#    #+#             */
/*   Updated: 2017/12/11 22:37:48 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	w_hh_int_cast(va_list arg, t_all *f)
{
	short			output;

	output = (char)va_arg(arg, void*);
	signed_w(f, (int)output);
}

void	w_hh_oct_cast(va_list arg, t_all *f)
{
	unsigned char	output;

	output = (unsigned char)va_arg(arg, void*);
	unsigned_w(f, (unsigned int)output, 8);
}

void	w_hh_hex_cast(va_list arg, t_all *f)
{
	unsigned char	output;

	output = (unsigned char)va_arg(arg, void*);
	unsigned_w(f, (unsigned int)output, 16);
}

void	w_hh_lhex_cast(va_list arg, t_all *f)
{
	unsigned char	output;

	output = (unsigned char)va_arg(arg, void*);
	unsigned_w_lc(f, (unsigned int)output, 16);
}

void	w_hh_uint_cast(va_list arg, t_all *f)
{
	unsigned char	output;

	output = (unsigned char)va_arg(arg, void*);
	unsigned_w(f, (unsigned int)output, 10);
}
