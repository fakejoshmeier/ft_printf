/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_cast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 10:59:06 by jmeier            #+#    #+#             */
/*   Updated: 2017/12/10 20:43:04 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ll_int_cast(va_list arg)
{
	long long			output;

	output = (long long)va_arg(arg, void*);
	ft_putnbr_base_fd((int)output, 10, 1);
}

void	ll_oct_cast(va_list arg)
{
	unsigned long long	output;

	output = (unsigned long long)va_arg(arg, void*);
	ft_putunbr_base_fd((unsigned int)output, 8, 1);
}

void	ll_hex_cast(va_list arg)
{
	unsigned long long	output;

	output = (unsigned long long)va_arg(arg, void*);
	ft_putunbr_base_fd((unsigned int)output, 16, 1);
}

void	ll_lhex_cast(va_list arg)
{
	unsigned long long	output;

	output = (unsigned long long)va_arg(arg, void*);
	ft_putunbr_base_lc((unsigned int)output, 16, 1);
}

void	ll_uint_cast(va_list arg)
{
	unsigned long long	output;

	output = (unsigned long long)va_arg(arg, void*);
	ft_putulonglong((unsigned long long)output, 10, 1);
}
