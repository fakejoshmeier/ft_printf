/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wp_j_cast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 10:59:06 by jmeier            #+#    #+#             */
/*   Updated: 2017/12/11 23:05:18 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	wp_j_int_cast(va_list arg, t_all *f)
{
	intmax_t	output;

	output = (intmax_t)va_arg(arg, void*);
	signed_d_wp(f, (int)output);
}

void	wp_j_oct_cast(va_list arg, t_all *f)
{
	uintmax_t	output;

	output = (uintmax_t)va_arg(arg, void*);
	unsigned_wp(f, (unsigned int)output, 8);
}

void	wp_j_hex_cast(va_list arg, t_all *f)
{
	uintmax_t	output;

	output = (uintmax_t)va_arg(arg, void*);
	unsigned_wp(f, (unsigned int)output, 16);
}

void	wp_j_lhex_cast(va_list arg, t_all *f)
{
	uintmax_t	output;

	output = (uintmax_t)va_arg(arg, void*);
	unsigned_wp_lc(f, (unsigned int)output, 16);
}

void	wp_j_uint_cast(va_list arg, t_all *f)
{
	uintmax_t	output;

	output = (uintmax_t)va_arg(arg, void*);
	unsigned_ll_wp(f, (unsigned long long)output, 10);
}
