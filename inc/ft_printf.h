/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 19:21:30 by jmeier            #+#    #+#             */
/*   Updated: 2017/11/29 12:21:26 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include "libft.h"
int		ft_printf(const char *format, ...);
/*
** Parse functions
*/
void	parse_flags(va_list arg, int *i, const char *str);
void	parse_hflag(va_list arg, int *i, const char *str);
void	parse_hhflag(va_list arg, int *i, const char *str);
void	parse_lflag(va_list arg, int *i, const char *str);
void	parse_llflag(va_list arg, int *i, const char *str);
void	parse_zflag(va_list arg, int *i, const char *str);
void	parse_jflag(va_list arg, int *i, const char *str);
/*
** Casting couch ;)
*/
void	int_cast(va_list arg);
void	oct_cast(va_list arg);
void	hex_cast(va_list arg);
void	lhex_cast(va_list arg);
void	uint_cast(va_list arg);
void	h_int_cast(va_list arg);
void	h_oct_cast(va_list arg);
void	h_hex_cast(va_list arg);
void	h_lhex_cast(va_list arg);
void	h_uint_cast(va_list arg);
void	hh_int_cast(va_list arg);
void	hh_oct_cast(va_list arg);
void	hh_hex_cast(va_list arg);
void	hh_lhex_cast(va_list arg);
void	hh_uint_cast(va_list arg);
void	l_int_cast(va_list arg);
void	l_oct_cast(va_list arg);
void	l_hex_cast(va_list arg);
void	l_lhex_cast(va_list arg);
void	l_uint_cast(va_list arg);
void	ll_int_cast(va_list arg);
void	ll_oct_cast(va_list arg);
void	ll_hex_cast(va_list arg);
void	ll_lhex_cast(va_list arg);
void	ll_uint_cast(va_list arg);
void	j_int_cast(va_list arg);
void	j_oct_cast(va_list arg);
void	j_hex_cast(va_list arg);
void	j_lhex_cast(va_list arg);
void	j_uint_cast(va_list arg);
void	z_int_cast(va_list arg);
void	z_oct_cast(va_list arg);
void	z_hex_cast(va_list arg);
void	z_lhex_cast(va_list arg);
void	z_uint_cast(va_list arg);


#endif
