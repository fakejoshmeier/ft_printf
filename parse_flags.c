/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 14:49:05 by jmeier            #+#    #+#             */
/*   Updated: 2017/11/21 08:11:59 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Credit to mlu for helping me with this and showing me the light that is
** ternary operators.  Holy shit, do they make this clusterfuck compact.
** Basically, this works by parsing the arguments, running under the assumption
** that there are indeed arguments to parse, and casts the arguments 
** accordingly.  Need to make a printer for all the good casting that 
** I'm doing.  Oh shit, I gotta call this the casting couch or something 
** equally horrid.
*/

void	parse_hflag(va_list arg, int *i, char *str)
{
	*i += 1;
	str[*i] == 'd' ? h_int_cast(arg) : 0;
	str[*i] == 'i' ? h_int_cast(arg) : 0;
	str[*i] == 'o' ? h_oct_cast(arg) : 0;
	str[*i] == 'x' ? h_hex_cast(arg) : 0;
	str[*i] == 'X' ? h_hex_cast(arg) : 0;
	str[*i] == 'u' ? h_uint_cast(arg) : 0;
}

void	parse_hhflag(va_list arg, int *i, char *str)
{
	*i += 2;
	str[*i] == 'd' ? hh_int_cast(arg) : 0;
	str[*i] == 'i' ? hh_int_cast(arg) : 0;
	str[*i] == 'o' ? hh_oct_cast(arg) : 0;
	str[*i] == 'x' ? hh_hex_cast(arg) : 0;
	str[*i] == 'X' ? hh_hex_cast(arg) : 0;
	str[*i] == 'u' ? hh_uint_cast(arg) : 0;
}

//void	parse_prec_flags(char *str, int *i, va_list arg)
//{
//	str[*i] == '-' ? just_l : 0;
//	str[*i] == '0' ? just_l : 0;
//	str[*i] == '+' ? just_l : 0;
//	str[*i] == '#' ? just_l : 0;
//	str[*i] == ' ' ? 
//	str[*i] == 'j' ? just_l : 0;
//	str[*i] == 'z' ? just_l : 0;
//	str[*i] == 'O' ? just_l : 0;
//	str[*i] == ''' ? just_l : 0;
//}

void	parse_flags(char *str, int *i, va_list arg)
{
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
//	str[*i] == 'f' ? dub_cast(arg) : 0;
//	str[*i] == 'e' ? dub_cast(arg) : 0;
//	str[*i] == 'E' ? dub_cast(arg) : 0;
//	str[*i] == 'g' ? dub_cast(arg) : 0;
//	str[*i] == 'G' ? dub_cast(arg) : 0;
//	str[*i] == 'n' ? int_cast(arg) : 0; Figure this one out later.
//	str[*i] == 't' ? parse_hflags(arg, i , str) : 0;
	(str[*i] == 'h' && str[*i + 1] != 'h') ? parse_hflag(arg, i , str) : 0;
	(str[*i] == 'h' && str[*i + 1] == 'h') ? parse_hhflag(arg, i , str) : 0;
	(str[*i] == 'l' && str[*i + 1] != 'l') ? parse_lflag(arg, i , str) : 0;
	(str[*i] == 'l' && str[*i + 1] == 'l') ? parse_llflag(arg, i , str) : 0;
//	parse_prec_flags(str, &i, arg);
}
