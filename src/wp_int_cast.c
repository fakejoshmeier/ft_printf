/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wp_int_cast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 10:59:06 by jmeier            #+#    #+#             */
/*   Updated: 2017/12/08 13:33:27 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	wp_int_cast(va_list arg, t_flags f, t_wp g)
{
	int				output;

	output = va_arg(arg, int);
	if ()



	ft_putnbr(output);
}

void	oct_cast(va_list arg)
{
	unsigned int	output;

	output = va_arg(arg, unsigned int);
	ft_putunbr_base(output, 8);
}

void	hex_cast(va_list arg)
{
	unsigned int	output;

	output = va_arg(arg, unsigned int);
	ft_putunbr_base(output, 16);
}

void	lhex_cast(va_list arg)
{
	unsigned int	output;

	output = va_arg(arg, unsigned int);
	ft_putunbr_base_lc(output, 16, 1);
}

void	uint_cast(va_list arg)
{
	unsigned int	output;

	output = va_arg(arg, unsigned int);
	ft_putunbr_base(output, 10);
}