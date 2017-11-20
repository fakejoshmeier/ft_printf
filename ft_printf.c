/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 19:20:44 by jmeier            #+#    #+#             */
/*   Updated: 2017/11/08 14:59:15 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_commands(char *str, int i)
{
	if (str[i + 1] == 'd')
		MACRO;
	if (str[i + 1] == 'd')
		MACRO;
	if (str[i + 1] == 'd')
		MACRO;
	if (str[i + 1] == 'd')
		MACRO;
	if (str[i + 1] == 'd')
		MACRO;
	if (str[i + 1] == 'd')
		MACRO;
	if (str[i + 1] == 'd')
		MACRO;
	if (str[i + 1] == 'd')
		MACRO;
	if (str[i + 1] == 'd')
		MACRO;
}



int		ft_printf(const char *format, ...)
{
	va_list	ap;
	char	*str;
	int		i;
//	int		;

	ASSERT(format);
	va_start(ap, format);
	str = (char *)format;
	if (!(ft_strchr(str, '%')))
		ft_putstr(str);
	i = -1;
	while (str && str[++i] != '%')
	{
		ft_putchar(str[i]);
		if (str[i] == '%')
		{
			ASSERT(str[i + 1] != '%');
			ASSERT(parse_commands(str, i));
		}
	}
	va_end(ap);
}
