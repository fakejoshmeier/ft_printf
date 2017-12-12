/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wp_l_cast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 10:59:06 by jmeier            #+#    #+#             */
/*   Updated: 2017/12/11 23:06:14 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	wp_l_int_cast(va_list arg, t_all *f)
{
	long			output;

	output = (long)va_arg(arg, void*);
	signed_l_wp(f, output);
}

void	wp_l_oct_cast(va_list arg, t_all *f)
{
	unsigned long	output;

	output = (unsigned long)va_arg(arg, void*);
	unsigned_l_wp(f, output, 8);
}

void	wp_l_hex_cast(va_list arg, t_all *f)
{
	unsigned long	output;

	output = (unsigned long)va_arg(arg, void*);
	unsigned_l_wp(f, output, 16);
}

void	wp_l_lhex_cast(va_list arg, t_all *f)
{
	unsigned long	output;

	output = (unsigned long)va_arg(arg, void*);
	unsigned_l_wp_lc(f, output, 16);
}

void	wp_l_uint_cast(va_list arg, t_all *f)
{
	unsigned long	output;

	output = (unsigned long)va_arg(arg, void*);
	unsigned_ll_wp(f, (unsigned long long)output, 10);
}
