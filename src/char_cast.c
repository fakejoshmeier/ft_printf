/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_cast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 19:09:56 by jmeier            #+#    #+#             */
/*   Updated: 2017/12/02 19:34:58 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	char_cast(va_list arg)
{
	unsigned char	output;

	output = (unsigned char)va_arg(arg, void*);
	ft_putchar((char)output);
}

void	str_cast(va_list arg)
{
	unsigned char	*output;

	output = (unsigned char *)va_arg(arg, void*);
	ft_putstr((char *)output);
}

void	elsie_cast(va_list arg)
{
	wchar_t			output;

	output = (wchar_t)va_arg(arg, void*);
	ft_putchar((char)output);
}

void	loss_cast(va_list arg)
{
	wchar_t			*output;

	output = (wchar_t *)va_arg(arg, void*);
	ft_putstr((char *)output);
}
