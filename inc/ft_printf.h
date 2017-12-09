/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 19:21:30 by jmeier            #+#    #+#             */
/*   Updated: 2017/12/08 21:31:44 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct	s_flags
{
	int			dash;
	int			zero;
	int			plus;
	int			hash;
	int			spess;
}				t_flags;

typedef struct	s_wp
{
	int			width;
	int			prec;
}				t_wp;

int				ft_printf(const char *format, ...);
/*
** Parse functions
*/
void			parse_flags(va_list arg, int *i, const char *str);
void			parse_hflag(va_list arg, int *i, const char *str);
void			parse_hhflag(va_list arg, int *i, const char *str);
void			parse_lflag(va_list arg, int *i, const char *str);
void			parse_llflag(va_list arg, int *i, const char *str);
void			parse_zflag(va_list arg, int *i, const char *str);
void			parse_jflag(va_list arg, int *i, const char *str);
void			parse_escape(int *i, const char *str);
void			parse_width_and_prec(const char *str, int *i, va_list arg);
/*
** Casting couch ;)
*/
void			int_cast(va_list arg);
void			oct_cast(va_list arg);
void			hex_cast(va_list arg);
void			lhex_cast(va_list arg);
void			uint_cast(va_list arg);
void			h_int_cast(va_list arg);
void			h_oct_cast(va_list arg);
void			h_hex_cast(va_list arg);
void			h_lhex_cast(va_list arg);
void			h_uint_cast(va_list arg);
void			hh_int_cast(va_list arg);
void			hh_oct_cast(va_list arg);
void			hh_hex_cast(va_list arg);
void			hh_lhex_cast(va_list arg);
void			hh_uint_cast(va_list arg);
void			l_int_cast(va_list arg);
void			l_oct_cast(va_list arg);
void			l_hex_cast(va_list arg);
void			l_lhex_cast(va_list arg);
void			l_uint_cast(va_list arg);
void			ll_int_cast(va_list arg);
void			ll_oct_cast(va_list arg);
void			ll_hex_cast(va_list arg);
void			ll_lhex_cast(va_list arg);
void			ll_uint_cast(va_list arg);
void			j_int_cast(va_list arg);
void			j_oct_cast(va_list arg);
void			j_hex_cast(va_list arg);
void			j_lhex_cast(va_list arg);
void			j_uint_cast(va_list arg);
void			z_int_cast(va_list arg);
void			z_oct_cast(va_list arg);
void			z_hex_cast(va_list arg);
void			z_lhex_cast(va_list arg);
void			z_uint_cast(va_list arg);
void			char_cast(va_list arg);
void			str_cast(va_list arg);
void			elsie_cast(va_list arg);
void			loss_cast(va_list arg);

#endif
