/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_cast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 10:59:06 by jmeier            #+#    #+#             */
/*   Updated: 2017/11/28 15:17:40 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	l_int_cast(va_list arg)
{
	long long			output;

	output = (long long)va_arg(arg, void*);
	ft_putllong_base_fd(output, 10, 1);
}

void	ll_oct_cast(va_list arg)
{
	unsigned long long	output;

	output = (unsigned long long)va_arg(arg, void*);
	ft_putullong_base_fd(output, 8, 1);
}

void	ll_hex_cast(va_list arg)
{
	unsigned long long	output;

	output = (unsigned long long)va_arg(arg, void*);
	ft_putullong_base_fd(output, 12, 1);
}

void	ll_lhex_cast(va_list arg)
{
	unsigned long long	output;

	output = (unsigned long long)va_arg(arg, void*);
	ft_putllong_base_lc(output, 16, 1);
}

void	ll_uint_cast(va_list arg)
{
	unsigned long long	output;

	output = (unsigned long long)va_arg(arg, void*);
	ft_putullong_base_fd(output, 10, 1);
}