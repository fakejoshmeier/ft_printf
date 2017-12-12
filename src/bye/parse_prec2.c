/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_prec2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 14:49:05 by jmeier            #+#    #+#             */
/*   Updated: 2017/12/11 20:28:38 by jmeier           ###   ########.fr       */
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

void	wp_parse_h(va_list arg, int *i, const char *str, t_all *f)
{
	*i += 1;
	str[*i] == 'd' ? wp_h_int_cast(arg, f) : 0;
	str[*i] == 'i' ? wp_h_int_cast(arg, f) : 0;
	str[*i] == 'o' ? wp_h_oct_cast(arg, f) : 0;
	str[*i] == 'x' ? wp_h_lhex_cast(arg, f) : 0;
	str[*i] == 'X' ? wp_h_hex_cast(arg, f) : 0;
	str[*i] == 'u' ? wp_h_uint_cast(arg, f) : 0;
}

void	wp_parse_hh(va_list arg, int *i, const char *str, t_all *f)
{
	*i += 2;
	str[*i] == 'd' ? wp_hh_int_cast(arg, f) : 0;
	str[*i] == 'i' ? wp_hh_int_cast(arg, f) : 0;
	str[*i] == 'o' ? wp_hh_oct_cast(arg, f) : 0;
	str[*i] == 'x' ? wp_hh_lhex_cast(arg, f) : 0;
	str[*i] == 'X' ? wp_hh_hex_cast(arg, f) : 0;
	str[*i] == 'u' ? wp_hh_uint_cast(arg, f) : 0;
}

void	wp_parse_l(va_list arg, int *i, const char *str, t_all *f)
{
	*i += 1;
	str[*i] == 'd' ? wp_l_int_cast(arg, f) : 0;
	str[*i] == 'i' ? wp_l_int_cast(arg, f) : 0;
	str[*i] == 'o' ? wp_l_oct_cast(arg, f) : 0;
	str[*i] == 'x' ? wp_l_lhex_cast(arg, f) : 0;
	str[*i] == 'X' ? wp_l_hex_cast(arg, f) : 0;
	str[*i] == 'u' ? wp_l_uint_cast(arg, f) : 0;
	str[*i] == 's' ? wp_loss_cast(arg, f) : 0;
}

void	wp_parse_ll(va_list arg, int *i, const char *str, t_all *f)
{
	*i += 2;
	str[*i] == 'd' ? wp_ll_int_cast(arg, f) : 0;
	str[*i] == 'i' ? wp_ll_int_cast(arg, f) : 0;
	str[*i] == 'o' ? wp_ll_oct_cast(arg, f) : 0;
	str[*i] == 'x' ? wp_ll_lhex_cast(arg, f) : 0;
	str[*i] == 'X' ? wp_ll_hex_cast(arg, f) : 0;
	str[*i] == 'u' ? wp_ll_uint_cast(arg, f) : 0;
}
