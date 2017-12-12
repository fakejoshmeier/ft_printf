/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 19:21:30 by jmeier            #+#    #+#             */
/*   Updated: 2017/12/12 00:55:19 by jmeier           ###   ########.fr       */
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
	int			width;
	int			prec;
}				t_all;

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
void			parse_extra_flags(const char *str, int *i, va_list arg);
void			more_parsing(const char *str, int *i, va_list arg, t_all *f);
void			width_parse(const char *str, int *i, t_all *f);
void			prec_parse(const char *str, int *i, t_all *f);
void			wp_parse(const char *str, int *i, va_list arg, t_all *f);
void			w_parse(const char *str, int *i, va_list arg, t_all *f);
void			wp_parse_h(va_list arg, int *i, const char *str, t_all *f);
void			wp_parse_hh(va_list arg, int *i, const char *str, t_all *f);
void			wp_parse_l(va_list arg, int *i, const char *str, t_all *f);
void			wp_parse_ll(va_list arg, int *i, const char *str, t_all *f);
void			wp_parse_z(va_list arg, int *i, const char *str, t_all *f);
void			wp_parse_j(va_list arg, int *i, const char *str, t_all *f);
void			w_parse_h(va_list arg, int *i, const char *str, t_all *f);
void			w_parse_hh(va_list arg, int *i, const char *str, t_all *f);
void			w_parse_l(va_list arg, int *i, const char *str, t_all *f);
void			w_parse_ll(va_list arg, int *i, const char *str, t_all *f);
void			w_parse_z(va_list arg, int *i, const char *str, t_all *f);
void			w_parse_j(va_list arg, int *i, const char *str, t_all *f);
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

void			w_int_cast(va_list arg, t_all *f);
void			w_oct_cast(va_list arg, t_all *f);
void			w_hex_cast(va_list arg, t_all *f);
void			w_lhex_cast(va_list arg, t_all *f);
void			w_uint_cast(va_list arg, t_all *f);
void			w_h_int_cast(va_list arg, t_all *f);
void			w_h_oct_cast(va_list arg, t_all *f);
void			w_h_hex_cast(va_list arg, t_all *f);
void			w_h_lhex_cast(va_list arg, t_all *f);
void			w_h_uint_cast(va_list arg, t_all *f);
void			w_hh_int_cast(va_list arg, t_all *f);
void			w_hh_oct_cast(va_list arg, t_all *f);
void			w_hh_hex_cast(va_list arg, t_all *f);
void			w_hh_lhex_cast(va_list arg, t_all *f);
void			w_hh_uint_cast(va_list arg, t_all *f);
void			w_l_int_cast(va_list arg, t_all *f);
void			w_l_oct_cast(va_list arg, t_all *f);
void			w_l_hex_cast(va_list arg, t_all *f);
void			w_l_lhex_cast(va_list arg, t_all *f);
void			w_l_uint_cast(va_list arg, t_all *f);
void			w_ll_int_cast(va_list arg, t_all *f);
void			w_ll_oct_cast(va_list arg, t_all *f);
void			w_ll_hex_cast(va_list arg, t_all *f);
void			w_ll_lhex_cast(va_list arg, t_all *f);
void			w_ll_uint_cast(va_list arg, t_all *f);
void			w_j_int_cast(va_list arg, t_all *f);
void			w_j_oct_cast(va_list arg, t_all *f);
void			w_j_hex_cast(va_list arg, t_all *f);
void			w_j_lhex_cast(va_list arg, t_all *f);
void			w_j_uint_cast(va_list arg, t_all *f);
void			w_z_int_cast(va_list arg, t_all *f);
void			w_z_oct_cast(va_list arg, t_all *f);
void			w_z_hex_cast(va_list arg, t_all *f);
void			w_z_lhex_cast(va_list arg, t_all *f);
void			w_z_uint_cast(va_list arg, t_all *f);
void			w_char_cast(va_list arg, t_all *f);
void			w_str_cast(va_list arg, t_all *f);
void			w_elsie_cast(va_list arg, t_all *f);
void			w_loss_cast(va_list arg, t_all *f);

void			wp_int_cast(va_list arg, t_all *f);
void			wp_oct_cast(va_list arg, t_all *f);
void			wp_hex_cast(va_list arg, t_all *f);
void			wp_lhex_cast(va_list arg, t_all *f);
void			wp_uint_cast(va_list arg, t_all *f);
void			wp_h_int_cast(va_list arg, t_all *f);
void			wp_h_oct_cast(va_list arg, t_all *f);
void			wp_h_hex_cast(va_list arg, t_all *f);
void			wp_h_lhex_cast(va_list arg, t_all *f);
void			wp_h_uint_cast(va_list arg, t_all *f);
void			wp_hh_int_cast(va_list arg, t_all *f);
void			wp_hh_oct_cast(va_list arg, t_all *f);
void			wp_hh_hex_cast(va_list arg, t_all *f);
void			wp_hh_lhex_cast(va_list arg, t_all *f);
void			wp_hh_uint_cast(va_list arg, t_all *f);
void			wp_l_int_cast(va_list arg, t_all *f);
void			wp_l_oct_cast(va_list arg, t_all *f);
void			wp_l_hex_cast(va_list arg, t_all *f);
void			wp_l_lhex_cast(va_list arg, t_all *f);
void			wp_l_uint_cast(va_list arg, t_all *f);
void			wp_ll_int_cast(va_list arg, t_all *f);
void			wp_ll_oct_cast(va_list arg, t_all *f);
void			wp_ll_hex_cast(va_list arg, t_all *f);
void			wp_ll_lhex_cast(va_list arg, t_all *f);
void			wp_ll_uint_cast(va_list arg, t_all *f);
void			wp_j_int_cast(va_list arg, t_all *f);
void			wp_j_oct_cast(va_list arg, t_all *f);
void			wp_j_hex_cast(va_list arg, t_all *f);
void			wp_j_lhex_cast(va_list arg, t_all *f);
void			wp_j_uint_cast(va_list arg, t_all *f);
void			wp_z_int_cast(va_list arg, t_all *f);
void			wp_z_oct_cast(va_list arg, t_all *f);
void			wp_z_hex_cast(va_list arg, t_all *f);
void			wp_z_lhex_cast(va_list arg, t_all *f);
void			wp_z_uint_cast(va_list arg, t_all *f);
void			wp_char_cast(va_list arg, t_all *f);
void			wp_str_cast(va_list arg, t_all *f);
void			wp_elsie_cast(va_list arg, t_all *f);
void			wp_loss_cast(va_list arg, t_all *f);
/*
** Precision and Width calculations and application
*/
void			signed_d_wp(t_all *f, int output);
void			unsigned_wp(t_all *f, unsigned int output, int b);
void			unsigned_wp_lc(t_all *f, unsigned int output, int b);
void			signed_l_wp(t_all *f, long output);
void			unsigned_l_wp(t_all *f, unsigned long output, int b);
void			unsigned_l_wp_lc(t_all *f, unsigned long output, int b);
void			signed_ll_wp(t_all *f, long long output);
void			unsigned_ll_wp(t_all *f, unsigned long long output, int b);
void			unsigned_ll_wp_lc(t_all *f, unsigned long long output, int b);
void			char_wp(t_all *f, char *out);
void			wchar_wp(t_all *f, wchar_t *out);
void			signed_w(t_all *f, int output);
void			signed_l_w(t_all *f, long output);
void			signed_ll_w(t_all *f, long long output);
void			unsigned_w(t_all *f, unsigned int output, int b);
void			unsigned_l_w(t_all *f, unsigned long output, int b);
void			unsigned_ll_w(t_all *f, unsigned long long output, int b);
void			unsigned_w_lc(t_all *f, unsigned int output, int b);
void			unsigned_l_w_lc(t_all *f, unsigned long output, int b);
void			unsigned_ll_w_lc(t_all *f, unsigned long long output, int b);
void			char_w(t_all *f, char *output);
void			wchar_w(t_all *f, wchar_t *output);
void			ft_putwsn(wchar_t *s, int n);
int				ft_widelen(wchar_t *s);
void			s_saver(int i, int output, char c, t_all *f);
void			s_saver2(int i, int base, t_all *f);
void			s_saver3(int i, int output, t_all *f);
void			s_saver4(int i, int base, t_all *f);
#endif
