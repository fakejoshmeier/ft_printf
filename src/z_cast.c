/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_cast.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 10:55:52 by jmeier            #+#    #+#             */
/*   Updated: 2017/11/30 11:31:13 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	z_int_cast(va_list arg)
{
	ssize_t	output;

	output = (ssize_t)va_arg(arg, void*);
	ft_putnbr((int)output);
}

void	z_oct_cast(va_list arg)
{
	size_t	output;

	output = (size_t)va_arg(arg, void*);
	ft_putunbr_base((unsigned int)output, 8);
}

void	z_hex_cast(va_list arg)
{
	size_t	output;

	output = (size_t)va_arg(arg, void*);
	ft_putunbr_base((unsigned int)output, 16);
}

void	z_lhex_cast(va_list arg)
{
	size_t	output;

	output = (size_t)va_arg(arg, void*);
	ft_putunbr_base_lc((unsigned int)output, 16, 1);
}

void	z_uint_cast(va_list arg)
{
	size_t	output;

	output = (size_t)va_arg(arg, void*);
	ft_putulonglong((unsigned long long)output, 10, 1);
}
