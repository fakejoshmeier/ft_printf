/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_prec3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 14:49:05 by jmeier            #+#    #+#             */
/*   Updated: 2017/12/11 21:05:56 by jmeier           ###   ########.fr       */
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

void	w_parse_h(va_list arg, int *i, const char *str, t_all *f)
{
	*i += 1;
	str[*i] == 'd' ? w_h_int_cast(arg, f) : 0;
	str[*i] == 'i' ? w_h_int_cast(arg, f) : 0;
	str[*i] == 'o' ? w_h_oct_cast(arg, f) : 0;
	str[*i] == 'x' ? w_h_lhex_cast(arg, f) : 0;
	str[*i] == 'X' ? w_h_hex_cast(arg, f) : 0;
	str[*i] == 'u' ? w_h_uint_cast(arg, f) : 0;
}

void	w_parse_hh(va_list arg, int *i, const char *str, t_all *f)
{
	*i += 2;
	str[*i] == 'd' ? w_hh_int_cast(arg, f) : 0;
	str[*i] == 'i' ? w_hh_int_cast(arg, f) : 0;
	str[*i] == 'o' ? w_hh_oct_cast(arg, f) : 0;
	str[*i] == 'x' ? w_hh_lhex_cast(arg, f) : 0;
	str[*i] == 'X' ? w_hh_hex_cast(arg, f) : 0;
	str[*i] == 'u' ? w_hh_uint_cast(arg, f) : 0;
}

void	w_parse_l(va_list arg, int *i, const char *str, t_all *f)
{
	*i += 1;
	str[*i] == 'd' ? w_l_int_cast(arg, f) : 0;
	str[*i] == 'i' ? w_l_int_cast(arg, f) : 0;
	str[*i] == 'o' ? w_l_oct_cast(arg, f) : 0;
	str[*i] == 'x' ? w_l_lhex_cast(arg, f) : 0;
	str[*i] == 'X' ? w_l_hex_cast(arg, f) : 0;
	str[*i] == 'u' ? w_l_uint_cast(arg, f) : 0;
	str[*i] == 'c' ? w_elsie_cast(arg, f) : 0;
	str[*i] == 's' ? w_loss_cast(arg, f) : 0;
}

void	w_parse_ll(va_list arg, int *i, const char *str, t_all *f)
{
	*i += 2;
	str[*i] == 'd' ? w_ll_int_cast(arg, f) : 0;
	str[*i] == 'i' ? w_ll_int_cast(arg, f) : 0;
	str[*i] == 'o' ? w_ll_oct_cast(arg, f) : 0;
	str[*i] == 'x' ? w_ll_lhex_cast(arg, f) : 0;
	str[*i] == 'X' ? w_ll_hex_cast(arg, f) : 0;
	str[*i] == 'u' ? w_ll_uint_cast(arg, f) : 0;
}
