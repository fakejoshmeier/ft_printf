/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 19:20:44 by jmeier            #+#    #+#             */
/*   Updated: 2017/11/21 08:22:57 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Accounts for a lack of flags, working as a simple putstr otherwise.  All of
** the initial parsing functions are placed here, so as to make it more compact
** and easy to follow.  Since there are only 5 types of cast that need to be
** made per set of flags, all of the various flag types, e.g. -ll, -h, etc.,
** will have their own functions, titled along the lines of hh_cast or such.
** Credit to mlu for showing me the light of ternary operators and how they
** just werk for a project like this.
*/




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
