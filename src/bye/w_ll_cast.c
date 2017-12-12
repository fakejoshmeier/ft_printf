/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_ll_cast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 10:59:06 by jmeier            #+#    #+#             */
/*   Updated: 2017/12/11 22:49:07 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	w_ll_int_cast(va_list arg, t_all *f)
{
	long long			output;

	output = (long long)va_arg(arg, void*);
	signed_ll_w(f, output);
}

void	w_ll_oct_cast(va_list arg, t_all *f)
{
	unsigned long long	output;

	output = (unsigned long long)va_arg(arg, void*);
	unsigned_ll_w(f, output, 8);
}

void	w_ll_hex_cast(va_list arg, t_all *f)
{
	unsigned long long	output;

	output = (unsigned long long)va_arg(arg, void*);
	unsigned_ll_w(f, output, 16);
}

void	w_ll_lhex_cast(va_list arg, t_all *f)
{
	unsigned long	output;

	output = (unsigned long long)va_arg(arg, void*);
	unsigned_ll_w_lc(f, output, 16);
}

void	w_ll_uint_cast(va_list arg, t_all *f)
{
	unsigned long	output;

	output = (unsigned long long)va_arg(arg, void*);
	unsigned_ll_w(f, output, 10);
}
