/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_cast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 19:09:56 by jmeier            #+#    #+#             */
/*   Updated: 2017/12/03 13:35:29 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	char_cast(va_list arg)
{
	unsigned char	output;

	output = (unsigned char)va_arg(arg, int);
	write(1, &output, 1);
}

void	str_cast(va_list arg)
{
	unsigned char	*output;

	output = (unsigned char *)va_arg(arg, char*);
	if (output)
		ft_putstr((char *)output);
	else
		ft_putstr("(null)");
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

	output = (wchar_t *)va_arg(arg, char*);
	ft_putstr((char *)output);
}
