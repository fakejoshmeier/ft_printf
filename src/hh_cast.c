/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hh_cast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 10:59:06 by jmeier            #+#    #+#             */
/*   Updated: 2017/11/28 14:19:13 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	hh_int_cast(va_list arg)
{
	char			output;

	output = (char)va_arg(arg, void*);
	ft_putnbr((int)output);
}

void	hh_oct_cast(va_list arg)
{
	unsigned char	output;

	output = (unsigned char)va_arg(arg, void*);
	ft_putunbr_base((unsigned int)output, 8);
}

void	hh_hex_cast(va_list arg)
{
	unsigned char	output;

	output = (unsigned char)va_arg(arg, void*);
	ft_putunbr_base((unsigned int)output, 12);
}

void	hh_lhex_cast(va_list arg)
{
	unsigned char	output;

	output = (unsigned char)va_arg(arg, void*);
	ft_putunbr_base_lc((unsigned int)output, 16, 1);
}

void	hh_uint_cast(va_list arg)
{
	unsigned char	output;

	output = (unsigned char)va_arg(arg, void*);
	ft_putunbr_base((unsigned int)output, 10);
}