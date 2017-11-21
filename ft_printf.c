/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 19:20:44 by jmeier            #+#    #+#             */
/*   Updated: 2017/11/20 16:32:02 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list	arg;
	int		i;
//	int		;

	ASSERT(format);
	va_start(arg, format);
	if (!(ft_strchr(format, '%')))
		ft_putstr((char *)format);
	i = -1;
	while (format[++i])
	{
		if (format[i] == '%')
			parse_flags(format, &i, arg);
		else
			ft_putchar(format[i]);
	}
	va_end(arg);
	return (1);
}
