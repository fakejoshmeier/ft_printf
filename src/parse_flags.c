/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 14:49:05 by jmeier            #+#    #+#             */
/*   Updated: 2019/10/17 18:49:09 by jmeier           ###   ########.fr       */
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

void	parse_flags(va_list arg, int *i, const char *str, t_all *f)
{
	str[*i] == 'd' ? int_cast(arg, f) : 0;
	str[*i] == 'i' ? int_cast(arg, f) : 0;
	str[*i] == 'o' ? oct_cast(arg, f) : 0;
	str[*i] == 'x' ? lhex_cast(arg, f) : 0;
	str[*i] == 'X' ? hex_cast(arg, f) : 0;
	str[*i] == 'u' ? uint_cast(arg, f) : 0;
	str[*i] == 'c' ? char_cast(arg, f) : 0;
	str[*i] == 's' ? str_cast(arg, f) : 0;
	str[*i] == '%' ? percent(f) : 0;
	str[*i] == 'j' ? parse_jflag(arg, i, str, f) : 0;
	str[*i] == 'z' ? parse_zflag(arg, i, str, f) : 0;
	str[*i] == 'p' ? address(arg, f) : 0;
	(str[*i] == 'h' && str[*i + 1] != 'h') ? parse_hflag(arg, i, str, f) : 0;
	(str[*i] == 'h' && str[*i + 1] == 'h') ? parse_hhflag(arg, i, str, f) : 0;
	(str[*i] == 'l' && str[*i + 1] != 'l') ? parse_lflag(arg, i, str, f) : 0;
	(str[*i] == 'l' && str[*i + 1] == 'l') ? parse_llflag(arg, i, str, f) : 0;
	str[*i] == 'O' ? l_oct_cast(arg, f) : 0;
	str[*i] == 'D' ? l_int_cast(arg, f) : 0;
	str[*i] == 'U' ? l_uint_cast(arg, f) : 0;
	str[*i] == 'C' ? elsie_cast(arg, f) : 0;
	str[*i] == 'S' ? loss_cast(arg, f) : 0;
	str[*i] == 'n' ? ntame(arg, f) : 0;
}

void	parse_hflag(va_list arg, int *i, const char *str, t_all *f)
{
	*i += 1;
	str[*i] == 'd' ? h_int_cast(arg, f) : 0;
	str[*i] == 'i' ? h_int_cast(arg, f) : 0;
	str[*i] == 'o' ? h_oct_cast(arg, f) : 0;
	str[*i] == 'x' ? h_lhex_cast(arg, f) : 0;
	str[*i] == 'X' ? h_hex_cast(arg, f) : 0;
	str[*i] == 'u' ? h_uint_cast(arg, f) : 0;
}

void	parse_hhflag(va_list arg, int *i, const char *str, t_all *f)
{
	*i += 2;
	str[*i] == 'd' ? hh_int_cast(arg, f) : 0;
	str[*i] == 'i' ? hh_int_cast(arg, f) : 0;
	str[*i] == 'o' ? hh_oct_cast(arg, f) : 0;
	str[*i] == 'x' ? hh_lhex_cast(arg, f) : 0;
	str[*i] == 'X' ? hh_hex_cast(arg, f) : 0;
	str[*i] == 'u' ? hh_uint_cast(arg, f) : 0;
}

void	parse_lflag(va_list arg, int *i, const char *str, t_all *f)
{
	*i += 1;
	str[*i] == 'd' ? l_int_cast(arg, f) : 0;
	str[*i] == 'i' ? l_int_cast(arg, f) : 0;
	str[*i] == 'o' ? l_oct_cast(arg, f) : 0;
	str[*i] == 'x' ? l_lhex_cast(arg, f) : 0;
	str[*i] == 'X' ? l_hex_cast(arg, f) : 0;
	str[*i] == 'u' ? l_uint_cast(arg, f) : 0;
	str[*i] == 'c' ? elsie_cast(arg, f) : 0;
	str[*i] == 's' ? loss_cast(arg, f) : 0;
}

void	parse_llflag(va_list arg, int *i, const char *str, t_all *f)
{
	*i += 2;
	str[*i] == 'd' ? ll_int_cast(arg, f) : 0;
	str[*i] == 'i' ? ll_int_cast(arg, f) : 0;
	str[*i] == 'o' ? ll_oct_cast(arg, f) : 0;
	str[*i] == 'x' ? ll_lhex_cast(arg, f) : 0;
	str[*i] == 'X' ? ll_hex_cast(arg, f) : 0;
	str[*i] == 'u' ? ll_uint_cast(arg, f) : 0;
}
