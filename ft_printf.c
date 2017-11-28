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

//void	parse_prec_flags(char *str, int *i, va_list arg)
//{
//str[*i] == '-' ? just_l : 0;
//str[*i] == '0' ? just_l : 0;
//str[*i] == '+' ? just_l : 0;
//str[*i] == '#' ? just_l : 0;
//str[*i] == ' ' ? 
//str[*i] == 'j' ? just_l : 0;
//str[*i] == 'z' ? just_l : 0;
//str[*i] == 'O' ? just_l : 0;
//str[*i] == ''' ? just_l : 0;
//}

void	parse_flags(char *str, int *i, va_list arg)
nt{
	*i += 1;
	str[*i] == 'd' ? int_cast(arg) : 0;
	str[*i] == 'i' ? int_cast(arg) : 0;
	str[*i] == 'o' ? oct_cast(arg) : 0;
	str[*i] == 'x' ? hex_cast(arg) : 0;
	str[*i] == 'X' ? hex_cast(arg) : 0;
	str[*i] == 'u' ? uint_cast(arg) : 0;
	str[*i] == 'c' ? char_cast(arg) : 0;
	str[*i] == 's' ? str_cast(arg) : 0;
	str[*i] == '%' ? ft_putchar('%') : 0;
	//str[*i] == 'f' ? dub_cast(arg) : 0;
	//str[*i] == 'e' ? dub_cast(arg) : 0;
	//str[*i] == 'E' ? dub_cast(arg) : 0;
	//str[*i] == 'g' ? dub_cast(arg) : 0;
	//str[*i] == 'G' ? dub_cast(arg) : 0;
	//str[*i] == 'n' ? int_cast(arg) : 0; Figure this one out later.
	//str[*i] == 't' ? parse_hflags(arg, i , str) : 0;
	(str[*i] == 'h' && str[*i + 1] != 'h') ? parse_hflag(arg, i , str) : 0;
	(str[*i] == 'h' && str[*i + 1] == 'h') ? parse_hhflag(arg, i , str) : 0;
	(str[*i] == 'l' && str[*i + 1] != 'l') ? parse_lflag(arg, i , str) : 0;
	(str[*i] == 'l' && str[*i + 1] == 'l') ? parse_llflag(arg, i , str) : 0;
	//parse_prec_flags(str, &i, arg);
}

int		ft_printf(const char *format, ...)
{
	va_list	arg;
	int		pos;
//	int		;

	ASSERT(format);
	va_start(arg, format);
	if (!(ft_strchr(format, '%')))
	{
		ft_putstr((char *)format);
		return (1);
	}
	pos = -1;
	while (format[++pos])
	{
		if (format[pos] == '%')
			parse_flags(format, &pos, arg);
		else
			ft_putchar(format[pos]);
	}
	va_end(arg);
	return (1);
}
