/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 19:20:44 by jmeier            #+#    #+#             */
/*   Updated: 2017/12/10 19:31:44 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Accounts for a lack of flags, working as putstr otherwise.  All of
** the initial parsing functions are placed here, so as to make it more compact
** and easy to follow.  Since there are 5 types of cast that need to be
** made per set of flags, all of the various flag types, e.g. -ll, -h, etc.,
** will have their own functions, titled along the lines of hh_cast or such.
** Nonprintable characters are taken care of immediately, as I like not having
** to think about them in a separate function.  parse_extra_flags is written
** as it is to provide space for any future additions to my code.
** Credit to mlu for showing me the light of ternary operators and how they
** just werk for a project like this.
*/

void	parse_escape(int *i, const char *str)
{
	*i += 1;
	str[*i] == 'a' ? ft_putchar('\a') : 0;
	str[*i] == '\\' ? ft_putchar('\\') : 0;
	str[*i] == 'b' ? ft_putchar('\b') : 0;
	str[*i] == 'r' ? ft_putchar('\r') : 0;
	str[*i] == '"' ? ft_putchar('\"') : 0;
	str[*i] == 'f' ? ft_putchar('\f') : 0;
	str[*i] == 't' ? ft_putchar('\t') : 0;
	str[*i] == 'n' ? ft_putchar('\n') : 0;
	str[*i] == '0' ? ft_putchar('\0') : 0;
	str[*i] == '\'' ? ft_putchar('\'') : 0;
	str[*i] == 'v' ? ft_putchar('\v') : 0;
	str[*i] == '?' ? ft_putchar('\?') : 0;
}

void	parse_extra_flags(const char *str, int *i, va_list arg)
{
	str[*i] == 'O' ? l_oct_cast(arg) : 0;
	str[*i] == 'D' ? l_int_cast(arg) : 0;
	str[*i] == 'U' ? l_uint_cast(arg) : 0;
	str[*i] == 'C' ? elsie_cast(arg) : 0;
	str[*i] == 'S' ? loss_cast(arg) : 0;
	if (str[*i] == '+' || str[*i] == '-' || str[*i] == ' ' || str[*i] == '#'
			|| str[*i] == 0)
		parse_width_and_prec(str, i, arg);
}

void	parse_flags(va_list arg, int *i, const char *str)
{
	*i += 1;
	str[*i] == 'd' ? int_cast(arg) : 0;
	str[*i] == 'i' ? int_cast(arg) : 0;
	str[*i] == 'o' ? oct_cast(arg) : 0;
	str[*i] == 'x' ? lhex_cast(arg) : 0;
	str[*i] == 'X' ? hex_cast(arg) : 0;
	str[*i] == 'u' ? uint_cast(arg) : 0;
	str[*i] == 'c' ? char_cast(arg) : 0;
	str[*i] == 's' ? str_cast(arg) : 0;
	str[*i] == '%' ? ft_putchar('%') : 0;
	//str[*i] == 'n' ? int_cast(arg) : 0; Figure this one out later.
	//str[*i] == 't' ? parse_hflags(arg, i , str) : 0;
	str[*i] == 'j' ? parse_jflag(arg, i, str) : 0;
	str[*i] == 'z' ? parse_zflag(arg, i, str) : 0;
	(str[*i] == 'h' && str[*i + 1] != 'h') ? parse_hflag(arg, i, str) : 0;
	(str[*i] == 'h' && str[*i + 1] == 'h') ? parse_hhflag(arg, i, str) : 0;
	(str[*i] == 'l' && str[*i + 1] != 'l') ? parse_lflag(arg, i, str) : 0;
	(str[*i] == 'l' && str[*i + 1] == 'l') ? parse_llflag(arg, i, str) : 0;
	parse_extra_flags(str, i, arg);
}

int		ft_printf(const char *format, ...)
{
	va_list	arg;
	int		pos;

	ASSERT(format);
	va_start(arg, format);
	if (!(ft_strchr(format, '%')))
	{
		ft_putstr((char *)format);
		return (0);
	}
	pos = -1;
	while (format[++pos])
	{
		if (format[pos] == '%')
			parse_flags(arg, &pos, format);
		else if (format[pos] == '\\')
			parse_escape(&pos, format);
		else
			ft_putchar(format[pos]);
	}
	va_end(arg);
	return (0);
}
