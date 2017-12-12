/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_int_cast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 10:59:06 by jmeier            #+#    #+#             */
/*   Updated: 2017/12/11 22:38:58 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	w_int_cast(va_list arg, t_all *f)
{
	int				output;

	output = va_arg(arg, int);
	signed_w(f, output);
}

void	w_oct_cast(va_list arg, t_all *f)
{
	unsigned int	output;

	output = va_arg(arg, unsigned int);
	unsigned_w(f, output, 8);
}

void	w_hex_cast(va_list arg, t_all *f)
{
	unsigned int	output;

	output = va_arg(arg, unsigned int);
	unsigned_w(f, output, 16);
}

void	w_lhex_cast(va_list arg, t_all *f)
{
	unsigned int	output;

	output = va_arg(arg, unsigned int);
	unsigned_w_lc(f, output, 16);
}

void	w_uint_cast(va_list arg, t_all *f)
{
	unsigned int	output;

	output = va_arg(arg, unsigned int);
	unsigned_w(f, output, 10);
}
