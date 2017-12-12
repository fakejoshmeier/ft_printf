/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_prec4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 14:49:05 by jmeier            #+#    #+#             */
/*   Updated: 2017/12/11 21:07:27 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** These should cover all of the other flags that can be applied to the
** commands.
*/

void	w_parse_z(va_list arg, int *i, const char *str, t_all *f)
{
	*i += 1;
	str[*i] == 'd' ? w_z_int_cast(arg, f) : 0;
	str[*i] == 'i' ? w_z_int_cast(arg, f) : 0;
	str[*i] == 'o' ? w_z_oct_cast(arg, f) : 0;
	str[*i] == 'x' ? w_z_lhex_cast(arg, f) : 0;
	str[*i] == 'X' ? w_z_hex_cast(arg, f) : 0;
	str[*i] == 'u' ? w_z_uint_cast(arg, f) : 0;
}

void	w_parse_j(va_list arg, int *i, const char *str, t_all *f)
{
	*i += 1;
	str[*i] == 'd' ? w_j_int_cast(arg, f) : 0;
	str[*i] == 'i' ? w_j_int_cast(arg, f) : 0;
	str[*i] == 'o' ? w_j_oct_cast(arg, f) : 0;
	str[*i] == 'x' ? w_j_lhex_cast(arg, f) : 0;
	str[*i] == 'X' ? w_j_hex_cast(arg, f) : 0;
	str[*i] == 'u' ? w_j_uint_cast(arg, f) : 0;
}

void	wp_parse_z(va_list arg, int *i, const char *str, t_all *f)
{
	*i += 1;
	str[*i] == 'd' ? wp_z_int_cast(arg, f) : 0;
	str[*i] == 'i' ? wp_z_int_cast(arg, f) : 0;
	str[*i] == 'o' ? wp_z_oct_cast(arg, f) : 0;
	str[*i] == 'x' ? wp_z_lhex_cast(arg, f) : 0;
	str[*i] == 'X' ? wp_z_hex_cast(arg, f) : 0;
	str[*i] == 'u' ? wp_z_uint_cast(arg, f) : 0;
}

void	wp_parse_j(va_list arg, int *i, const char *str, t_all *f)
{
	*i += 1;
	str[*i] == 'd' ? wp_j_int_cast(arg, f) : 0;
	str[*i] == 'i' ? wp_j_int_cast(arg, f) : 0;
	str[*i] == 'o' ? wp_j_oct_cast(arg, f) : 0;
	str[*i] == 'x' ? wp_j_lhex_cast(arg, f) : 0;
	str[*i] == 'X' ? wp_j_hex_cast(arg, f) : 0;
	str[*i] == 'u' ? wp_j_uint_cast(arg, f) : 0;
}
