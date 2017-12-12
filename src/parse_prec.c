/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_prec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 19:33:34 by jmeier            #+#    #+#             */
/*   Updated: 2017/12/11 23:17:17 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	width_parse(const char *str, int *i, t_all *f)
{
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		if (str[*i] >= '0' && str[*i] <= '9')
			f->width = f->width * 10 + (str[*i] - '0');
	}
}

void	prec_parse(const char *str, int *i, t_all *f)
{
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		if (str[*i] >= '0' && str[*i] <= '9')
			f->prec = f->prec * 10 + (str[*i] - '0');
		*i += 1;
	}
}

void	w_parse(const char *str, int *i, va_list arg, t_all *f)
{
	str[*i] == 'd' ? w_int_cast(arg, f) : 0;
	str[*i] == 'i' ? w_int_cast(arg, f) : 0;
	str[*i] == 'o' ? w_oct_cast(arg, f) : 0;
	str[*i] == 'x' ? w_lhex_cast(arg, f) : 0;
	str[*i] == 'X' ? w_hex_cast(arg, f) : 0;
	str[*i] == 'u' ? w_uint_cast(arg, f) : 0;
	str[*i] == 'c' ? w_char_cast(arg, f) : 0;
	str[*i] == 's' ? w_str_cast(arg, f) : 0;
	str[*i] == 'j' ? w_parse_j(arg, i, str, f) : 0;
	str[*i] == 'z' ? w_parse_z(arg, i, str, f) : 0;
	(str[*i] == 'h' && str[*i + 1] != 'h') ? w_parse_h(arg, i, str, f) : 0;
	(str[*i] == 'h' && str[*i + 1] == 'h') ? w_parse_hh(arg, i, str, f) : 0;
	(str[*i] == 'l' && str[*i + 1] != 'l') ? w_parse_l(arg, i, str, f) : 0;
	(str[*i] == 'l' && str[*i + 1] == 'l') ? w_parse_ll(arg, i, str, f) : 0;
	str[*i] == 'O' ? w_l_oct_cast(arg, f) : 0;
	str[*i] == 'D' ? w_l_int_cast(arg, f) : 0;
	str[*i] == 'U' ? w_l_uint_cast(arg, f) : 0;
	str[*i] == 'C' ? w_elsie_cast(arg, f) : 0;
	str[*i] == 'S' ? w_loss_cast(arg, f) : 0;
	supa_free(f);
}

/*
** Precision flags with the c conversion results in undefined behavior
*/
void	wp_parse(const char *str, int *i, va_list arg, t_all *f)
{
	str[*i] == 'd' ? wp_int_cast(arg, f) : 0;
	str[*i] == 'i' ? wp_int_cast(arg, f) : 0;
	str[*i] == 'o' ? wp_oct_cast(arg, f) : 0;
	str[*i] == 'x' ? wp_lhex_cast(arg, f) : 0;
	str[*i] == 'X' ? wp_hex_cast(arg, f) : 0;
	str[*i] == 'u' ? wp_uint_cast(arg, f) : 0;
	str[*i] == 's' ? wp_str_cast(arg, f) : 0;
	str[*i] == 'j' ? wp_parse_j(arg, i, str, f) : 0;
	str[*i] == 'z' ? wp_parse_z(arg, i, str, f) : 0;
	(str[*i] == 'h' && str[*i + 1] != 'h') ? wp_parse_h(arg, i, str, f) : 0;
	(str[*i] == 'h' && str[*i + 1] == 'h') ? wp_parse_hh(arg, i, str, f) : 0;
	(str[*i] == 'l' && str[*i + 1] != 'l') ? wp_parse_l(arg, i, str, f) : 0;
	(str[*i] == 'l' && str[*i + 1] == 'l') ? wp_parse_ll(arg, i, str, f) : 0;
	str[*i] == 'O' ? wp_l_oct_cast(arg, f) : 0;
	str[*i] == 'D' ? wp_l_int_cast(arg, f) : 0;
	str[*i] == 'U' ? wp_l_uint_cast(arg, f) : 0;
	supa_free(f);
}

void	more_parsing(const char *str, int *i, va_list arg, t_all *f)
{
	int		prec_flag;

	*i += 1;
	prec_flag = 0;
	str[*i] == '+' ? f->plus = 1 : 0;
	str[*i] == '-' ? f->dash = 1 : 0;
	str[*i] == ' ' ? f->spess = 1 : 0;
	str[*i] == '0' ? f->zero = 1 : 0;
	str[*i] == '#' ? f->hash = 1 : 0;
	str[*i] > '0' && str[*i] <= '9' ? width_parse(str, i, f) : 0;
	str[*i] == '.' ? prec_flag = 1, prec_parse(str, i, f) : 0;
	if (str[*i + 1] == ' ' || str[*i + 1] == '#' || str[*i + 1] == '-'
		|| str[*i + 1] == '+' || str[*i + 1] == '0' || str[*i] == '.' ||
		(str[*i + 1] > '0' && str[*i + 1] <= '9'))
		more_parsing(str, i, arg, f);
	else
	{
		f->dash == 1 ? f->zero = 0 : 0;
		f->plus == 1 ? f->spess = 0 : 0;
		prec_flag == 1 ? wp_parse(str, i, arg, f) : w_parse(str, i, arg, f);
	}
}
