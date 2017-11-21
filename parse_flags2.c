/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 14:49:05 by jmeier            #+#    #+#             */
/*   Updated: 2017/11/21 08:23:02 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * The l and ll flags turn the d and i into long, and long long, respectively.
 * For o, u, x, X, they turn into unsigned long and long long.
*/

void	parse_lflag(va_list arg, int *i, char *str)
{
	*i += 1;
	str[*i] == 'd' ? l_int_cast(arg) : 0;
	str[*i] == 'i' ? l_int_cast(arg) : 0;
	str[*i] == 'o' ? l_oct_cast(arg) : 0;
	str[*i] == 'x' ? l_hex_cast(arg) : 0;
	str[*i] == 'X' ? l_hex_cast(arg) : 0;
	str[*i] == 'u' ? l_uint_cast(arg) : 0;
}

void	parse_llflag(va_list arg, int *i, char *str)
{
	*i += 2;
	str[*i] == 'd' ? ll_int_cast(arg) : 0;
	str[*i] == 'i' ? ll_int_cast(arg) : 0;
	str[*i] == 'o' ? ll_oct_cast(arg) : 0;
	str[*i] == 'x' ? ll_hex_cast(arg) : 0;
	str[*i] == 'X' ? ll_hex_cast(arg) : 0;
	str[*i] == 'u' ? ll_uint_cast(arg) : 0;
}

void	parse_zflag(va_list arg, int *i, char *str)
{
	*i += 1;
	str[*i] == 'd' ? z_int_cast(arg) : 0;
	str[*i] == 'i' ? z_int_cast(arg) : 0;
	str[*i] == 'o' ? z_oct_cast(arg) : 0;
	str[*i] == 'x' ? z_hex_cast(arg) : 0;
	str[*i] == 'X' ? z_hex_cast(arg) : 0;
	str[*i] == 'u' ? z_uint_cast(arg) : 0;
}

void	parse_jflag(va_list arg, int *i, char *str)
{
	*i += 1;
	str[*i] == 'd' ? j_int_cast(arg) : 0;
	str[*i] == 'i' ? j_int_cast(arg) : 0;
	str[*i] == 'o' ? j_oct_cast(arg) : 0;
	str[*i] == 'x' ? j_hex_cast(arg) : 0;
	str[*i] == 'X' ? j_hex_cast(arg) : 0;
	str[*i] == 'u' ? j_uint_cast(arg) : 0;
}
