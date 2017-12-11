/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wp_l_cast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 10:59:06 by jmeier            #+#    #+#             */
/*   Updated: 2017/12/09 20:37:56 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	wp_l_int_cast(va_list arg, t_flags *f, t_wp *g)
{
	long			output;

	output = (long)va_arg(arg, void*);
	signed_l_wp(f, g, output);
}

void	wp_l_oct_cast(va_list arg, t_flags *f, t_wp *g)
{
	unsigned long	output;

	output = (unsigned long)va_arg(arg, void*);
	unsigned_l_wp(f, g, output, 8);
}

void	wp_l_hex_cast(va_list arg, t_flags *f, t_wp *g)
{
	unsigned long	output;

	output = (unsigned long)va_arg(arg, void*);
	unsigned_l_wp(f, g, output, 16);
}

void	wp_l_lhex_cast(va_list arg, t_flags *f, t_wp *g)
{
	unsigned long	output;

	output = (unsigned long)va_arg(arg, void*);
	unsigned_l_wp_lc(f, g, output, 16);
}

void	wp_l_uint_cast(va_list arg, t_flags *f, t_wp *g)
{
	unsigned long	output;

	output = (unsigned long)va_arg(arg, void*);
	unsigned_ll_wp(f, g, (unsigned long long)output, 10);
}
