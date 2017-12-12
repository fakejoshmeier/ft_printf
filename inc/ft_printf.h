/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 19:21:30 by jmeier            #+#    #+#             */
/*   Updated: 2017/12/12 12:38:46 by jmeier           ###   ########.fr       */
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
	int			adr;
	int			wid_flag;
	int			prec_flag;
}				t_all;

int				ft_printf(const char *format, ...);
/*
** Parse functions
*/
void			parse_flags(va_list arg, int *i, const char *str, t_all *f);
void			parse_hflag(va_list arg, int *i, const char *str, t_all *f);
void			parse_hhflag(va_list arg, int *i, const char *str, t_all *f);
void			parse_lflag(va_list arg, int *i, const char *str, t_all *f);
void			parse_llflag(va_list arg, int *i, const char *str, t_all *f);
void			parse_zflag(va_list arg, int *i, const char *str, t_all *f);
void			parse_jflag(va_list arg, int *i, const char *str, t_all *f);
void			parse_escape(int *i, const char *str, t_all *f);
void			parse_width(const char *str, int *i, va_list arg, t_all *f);
void			parse_prec(const char *str, int *i, va_list arg, t_all *f);
void			parse_format(const char *str, int *i, t_all *f);
char			*prefix_parse(int output, int base, int caps, t_all *f);
char			*sign_width_parse(long long output, t_all *f);
char			*width_parse(unsigned long long output, t_all *f, int base);
char			*prec_parse(unsigned long long output, t_all *f, int b);
char			*sign_prec_parse(long long output, t_all *f);

void			supa_free(char *s1, char *s2, char *s3);
int				isflag(char c);
void			percent(t_all *f);
/*
** Casting couch ;)
*/
void			int_cast(va_list arg, t_all *f);
void			oct_cast(va_list arg, t_all *f);
void			hex_cast(va_list arg, t_all *f);
void			lhex_cast(va_list arg, t_all *f);
void			uint_cast(va_list arg, t_all *f);
void			h_int_cast(va_list arg, t_all *f);
void			h_oct_cast(va_list arg, t_all *f);
void			h_hex_cast(va_list arg, t_all *f);
void			h_lhex_cast(va_list arg, t_all *f);
void			h_uint_cast(va_list arg, t_all *f);
void			hh_int_cast(va_list arg, t_all *f);
void			hh_oct_cast(va_list arg, t_all *f);
void			hh_hex_cast(va_list arg, t_all *f);
void			hh_lhex_cast(va_list arg, t_all *f);
void			hh_uint_cast(va_list arg, t_all *f);
void			l_int_cast(va_list arg, t_all *f);
void			l_oct_cast(va_list arg, t_all *f);
void			l_hex_cast(va_list arg, t_all *f);
void			l_lhex_cast(va_list arg, t_all *f);
void			l_uint_cast(va_list arg, t_all *f);
void			ll_int_cast(va_list arg, t_all *f);
void			ll_oct_cast(va_list arg, t_all *f);
void			ll_hex_cast(va_list arg, t_all *f);
void			ll_lhex_cast(va_list arg, t_all *f);
void			ll_uint_cast(va_list arg, t_all *f);
void			j_int_cast(va_list arg, t_all *f);
void			j_oct_cast(va_list arg, t_all *f);
void			j_hex_cast(va_list arg, t_all *f);
void			j_lhex_cast(va_list arg, t_all *f);
void			j_uint_cast(va_list arg, t_all *f);
void			z_int_cast(va_list arg, t_all *f);
void			z_oct_cast(va_list arg, t_all *f);
void			z_hex_cast(va_list arg, t_all *f);
void			z_lhex_cast(va_list arg, t_all *f);
void			z_uint_cast(va_list arg, t_all *f);
void			char_cast(va_list arg, t_all *f);
void			str_cast(va_list arg, t_all *f);
void			elsie_cast(va_list arg, t_all *f);
void			loss_cast(va_list arg, t_all *f);
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
