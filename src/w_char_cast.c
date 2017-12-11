/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_char_cast.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 19:09:56 by jmeier            #+#    #+#             */
/*   Updated: 2017/12/10 16:37:13 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	w_char_cast(va_list arg, t_flags *f, t_wp *g)
{
	unsigned char	output;

	output = (unsigned char)va_arg(arg, int);
	!(f->dash) ? ft_putchars(' ', g->width - 1) : 0;
	write(1, &output, 1);
	f->dash ? ft_putchars(' ', g->width - 1) : 0;
}

void	w_str_cast(va_list arg, t_flags *f, t_wp *g)
{
	unsigned char	*output;

	output = (unsigned char *)va_arg(arg, char*);
	char_w(f, g, (char *)output);
}

void	w_elsie_cast(va_list arg, t_flags *f, t_wp *g)
{
	wchar_t			output;

	output = (wchar_t)va_arg(arg, void*);
	!(f->dash) ? ft_putchars(' ', g->width - 1) : 0;
	ft_putchar((char)output);
	f->dash ? ft_putchars(' ', g->width - 1) : 0;
}

void	w_loss_cast(va_list arg, t_flags *f, t_wp *g)
{
	wchar_t			*output;

	output = va_arg(arg, wchar_t*);
	wchar_w(f, g, output);
}
