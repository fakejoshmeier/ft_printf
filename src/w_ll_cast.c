/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_ll_cast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 10:59:06 by jmeier            #+#    #+#             */
/*   Updated: 2017/12/10 01:42:16 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	w_ll_int_cast(va_list arg, t_flags *f, t_wp *g)
{
	long long			output;

	output = (long long)va_arg(arg, void*);
	signed_ll_w(f, g, output);
}

void	w_ll_oct_cast(va_list arg, t_flags *f, t_wp *g)
{
	unsigned long long	output;

	output = (unsigned long long)va_arg(arg, void*);
	unsigned_ll_w(f, g, output, 8);
}

void	w_ll_hex_cast(va_list arg, t_flags *f, t_wp *g)
{
	unsigned long long	output;

	output = (unsigned long long)va_arg(arg, void*);
	unsigned_ll_w(f, g, output, 16);
}

void	w_ll_lhex_cast(va_list arg, t_flags *f, t_wp *g)
{
	unsigned long	output;

	output = (unsigned long long)va_arg(arg, void*);
	unsigned_ll_w_lc(f, g, output, 16);
}

void	w_ll_uint_cast(va_list arg, t_flags *f, t_wp *g)
{
	unsigned long	output;

	output = (unsigned long long)va_arg(arg, void*);
	unsigned_ll_w(f, g, output, 10);
}
