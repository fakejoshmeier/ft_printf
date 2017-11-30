/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_cast.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 10:59:06 by jmeier            #+#    #+#             */
/*   Updated: 2017/11/28 15:15:56 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	l_int_cast(va_list arg)
{
	long			output;

	output = (long)va_arg(arg, void*);
	ft_putlong_base_fd(output, 10, 1);
}

void	l_oct_cast(va_list arg)
{
	unsigned long	output;

	output = (unsigned long)va_arg(arg, void*);
	ft_putulong_base_fd(output, 8, 1);
}

void	l_hex_cast(va_list arg)
{
	unsigned long	output;

	output = (unsigned long)va_arg(arg, void*);
	ft_putulong_base_fd(output, 12, 1);
}

void	l_lhex_cast(va_list arg)
{
	unsigned long	output;

	output = (unsigned long)va_arg(arg, void*);
	ft_putlong_base_lc(output, 16, 1);
}

void	l_uint_cast(va_list arg)
{
	unsigned long	output;

	output = (unsigned long)va_arg(arg, void*);
	ft_putulong_base_fd(output, 10, 1);
}