/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wp_int_cast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 10:59:06 by jmeier            #+#    #+#             */
/*   Updated: 2017/12/09 00:10:40 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	wp_int_cast(va_list arg, t_flags *f, t_wp *g)
{
	int				output;

	output = va_arg(arg, int);
	signed_d_wp(f, g, output);
}

void	wp_oct_cast(va_list arg, t_flags *f, t_wp *g)
{
	unsigned int	output;

	output = va_arg(arg, unsigned int);
	unsigned_wp(f, g, output, 8);
}

void	hex_cast(va_list arg, t_flags *f, t_wp *g)
{
	unsigned int	output;

	output = va_arg(arg, unsigned int);
	unsigned_wp(f, g, output, 16);
}

void	lhex_cast(va_list arg, t_flags *f, t_wp *g)
{
	unsigned int	output;

	output = va_arg(arg, unsigned int);
	unsigned_wp_lc(f, g, output, 16);
}

void	uint_cast(va_list arg, t_flags *f, t_wp *g)
{
	unsigned int	output;

	output = va_arg(arg, unsigned int);
	unsigned_wp(f, g, output, 10);
}
