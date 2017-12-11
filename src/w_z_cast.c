/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_z_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 10:59:06 by jmeier            #+#    #+#             */
/*   Updated: 2017/12/10 01:44:54 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	w_z_int_cast(va_list arg, t_flags *f, t_wp *g)
{
	ssize_t	output;

	output = (ssize_t)va_arg(arg, void*);
	signed_w(f, g, (int)output);
}

void	w_z_oct_cast(va_list arg, t_flags *f, t_wp *g)
{
	size_t	output;

	output = (size_t)va_arg(arg, void*);
	unsigned_w(f, g, (unsigned int)output, 8);
}

void	w_z_hex_cast(va_list arg, t_flags *f, t_wp *g)
{
	size_t	output;

	output = (size_t)va_arg(arg, void*);
	unsigned_w(f, g, (unsigned int)output, 16);
}

void	w_z_lhex_cast(va_list arg, t_flags *f, t_wp *g)
{
	size_t	output;

	output = (size_t)va_arg(arg, void*);
	unsigned_w_lc(f, g, (unsigned int)output, 16);
}

void	w_z_uint_cast(va_list arg, t_flags *f, t_wp *g)
{
	size_t	output;

	output = (size_t)va_arg(arg, void*);
	unsigned_w(f, g, (unsigned int)output, 10);
}
