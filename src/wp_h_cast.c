/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wp_h_cast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 10:59:06 by jmeier            #+#    #+#             */
/*   Updated: 2017/12/11 22:51:47 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	wp_h_int_cast(va_list arg, t_all *f)
{
	short			output;

	output = (short)va_arg(arg, void*);
	signed_d_wp(f, output);
}

void	wp_h_oct_cast(va_list arg, t_all *f)
{
	unsigned short	output;

	output = (unsigned short)va_arg(arg, void*);
	unsigned_wp(f, (unsigned int)output, 8);
}

void	wp_h_hex_cast(va_list arg, t_all *f)
{
	unsigned short	output;

	output = (unsigned short)va_arg(arg, void*);
	unsigned_wp(f, (unsigned int)output, 16);
}

void	wp_h_lhex_cast(va_list arg, t_all *f)
{
	unsigned short	output;

	output = (unsigned short)va_arg(arg, void*);
	unsigned_wp_lc(f, (unsigned int)output, 16);
}

void	wp_h_uint_cast(va_list arg, t_all *f)
{
	unsigned short	output;

	output = (unsigned short)va_arg(arg, void*);
	unsigned_wp(f, (unsigned int)output, 10);
}
