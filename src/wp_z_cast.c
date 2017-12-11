/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wp_z_cast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 10:59:06 by jmeier            #+#    #+#             */
/*   Updated: 2017/12/09 21:11:44 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	wp_z_int_cast(va_list arg, t_flags *f, t_wp *g)
{
	ssize_t	output;

	output = (ssize_t)va_arg(arg, void*);
	signed_d_wp(f, g, (int)output);
}

void	wp_z_oct_cast(va_list arg, t_flags *f, t_wp *g)
{
	size_t	output;

	output = (size_t)va_arg(arg, void*);
	unsigned_wp(f, g, (unsigned int)output, 8);
}

void	wp_z_hex_cast(va_list arg, t_flags *f, t_wp *g)
{
	size_t	output;

	output = (size_t)va_arg(arg, void*);
	unsigned_wp(f, g, (unsigned int)output, 16);
}

void	wp_z_lhex_cast(va_list arg, t_flags *f, t_wp *g)
{
	size_t	output;

	output = (size_t)va_arg(arg, void*);
	unsigned_wp_lc(f, g, (unsigned int)output, 16);
}

void	wp_z_uint_cast(va_list arg, t_flags *f, t_wp *g)
{
	size_t	output;

	output = (size_t)va_arg(arg, void*);
	unsigned_wp(f, g, (unsigned int)output, 10);
}
