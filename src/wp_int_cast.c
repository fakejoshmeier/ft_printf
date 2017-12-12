/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wp_int_cast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 10:59:06 by jmeier            #+#    #+#             */
/*   Updated: 2017/12/11 23:04:26 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	wp_int_cast(va_list arg, t_all *f)
{
	int				output;

	output = va_arg(arg, int);
	signed_d_wp(f, output);
}

void	wp_oct_cast(va_list arg, t_all *f)
{
	unsigned int	output;

	output = va_arg(arg, unsigned int);
	unsigned_wp(f, output, 8);
}

void	wp_hex_cast(va_list arg, t_all *f)
{
	unsigned int	output;

	output = va_arg(arg, unsigned int);
	unsigned_wp(f, output, 16);
}

void	wp_lhex_cast(va_list arg, t_all *f)
{
	unsigned int	output;

	output = va_arg(arg, unsigned int);
	unsigned_wp_lc(f, output, 16);
}

void	wp_uint_cast(va_list arg, t_all *f)
{
	unsigned int	output;

	output = va_arg(arg, unsigned int);
	unsigned_wp(f, output, 10);
}
