/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_cast.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 10:59:06 by jmeier            #+#    #+#             */
/*   Updated: 2017/11/28 16:52:02 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	h_int_cast(va_list arg)
{
	short			output;

	output = (short)va_arg(arg, void*);
	ft_putnbr(output);
}

void	h_oct_cast(va_list arg)
{
	unsigned short	output;

	output = (unsigned short)va_arg(arg, void*);
	ft_putunbr_base((unsigned int)output, 8);
}

void	h_hex_cast(va_list arg)
{
	unsigned short	output;

	output = (unsigned short)va_arg(arg, void*);
	ft_putunbr_base((unsigned int)output, 16);
}

void	h_lhex_cast(va_list arg)
{
	unsigned short	output;

	output = (unsigned short)va_arg(arg, void*);
	ft_putunbr_base_lc((unsigned int)output, 16, 1);
}

void	h_uint_cast(va_list arg)
{
	unsigned short	output;

	output = (unsigned short)va_arg(arg, void*);
	ft_putunbr_base((unsigned int)output, 10);
}
