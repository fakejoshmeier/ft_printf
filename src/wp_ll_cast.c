/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wp_ll_cast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 10:59:06 by jmeier            #+#    #+#             */
/*   Updated: 2017/12/11 23:07:08 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	wp_ll_int_cast(va_list arg, t_all *f)
{
	long long			output;

	output = (long long)va_arg(arg, void*);
	signed_d_wp(f, (int)output);
}

void	wp_ll_oct_cast(va_list arg, t_all *f)
{
	unsigned long long	output;

	output = (unsigned long long)va_arg(arg, void*);
	unsigned_ll_wp(f, output, 8);
}

void	wp_ll_hex_cast(va_list arg, t_all *f)
{
	unsigned long long	output;

	output = (unsigned long long)va_arg(arg, void*);
	unsigned_ll_wp(f, output, 16);
}

void	wp_ll_lhex_cast(va_list arg, t_all *f)
{
	unsigned long	output;

	output = (unsigned long long)va_arg(arg, void*);
	unsigned_ll_wp_lc(f, output, 16);
}

void	wp_ll_uint_cast(va_list arg, t_all *f)
{
	unsigned long	output;

	output = (unsigned long long)va_arg(arg, void*);
	unsigned_ll_wp(f, (unsigned long long)output, 10);
}
