/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_prec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 19:33:34 by jmeier            #+#    #+#             */
/*   Updated: 2017/12/10 16:20:08 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	rip_n_tear(const char *str, int *i, t_flags *f)
{
	int				j;

	j = *i;
	while (!ft_isvalue(str[j++]))
	{
		str[j] == '-' ? f->dash = 1 : 0;
		str[j] == '0' ? f->zero = 1 : 0;
		str[j] == '+' ? f->plus = 1 : 0;
		str[j] == ' ' ? f->spess = 1 : 0;
		str[j] == '#' ? f->hash = 1 : 0;
	}
	f->dash == 1 ? f->zero = 0 : 0;
	f->plus == 1 ? f->spess = 0 : 0;
	*i = j;
}

void	w_parse(const char *str, int *i, va_list arg, t_flags *f, t_wp *g)
{
	str[*i] == 'd' ? w_int_cast(arg, f, g) : 0;
	str[*i] == 'i' ? w_int_cast(arg, f, g) : 0;
	str[*i] == 'o' ? w_oct_cast(arg, f, g) : 0;
	str[*i] == 'x' ? w_lhex_cast(arg, f, g) : 0;
	str[*i] == 'X' ? w_hex_cast(arg, f, g) : 0;
	str[*i] == 'u' ? w_uint_cast(arg, f, g) : 0;
	str[*i] == 'c' ? w_char_cast(arg, f, g) : 0;
	str[*i] == 's' ? w_str_cast(arg, f, g) : 0;
	str[*i] == 'j' ? w_parse_j(arg, i, str, f, g) : 0;
	str[*i] == 'z' ? w_parse_z(arg, i, str, f, g) : 0;
	(str[*i] == 'h' && str[*i + 1] != 'h') ? w_parse_h(arg, i, str, f, g)
		: 0;
	(str[*i] == 'h' && str[*i + 1] == 'h') ? w_parse_hh(arg, i, str, f, g)
		: 0;
	(str[*i] == 'l' && str[*i + 1] != 'l') ? w_parse_l(arg, i, str, f, g)
		: 0;
	(str[*i] == 'l' && str[*i + 1] == 'l') ? w_parse_ll(arg, i, str, f, g)
		: 0;
	str[*i] == 'O' ? w_l_oct_cast(arg, f, g) : 0;
	str[*i] == 'D' ? w_l_int_cast(arg, f, g) : 0;
	str[*i] == 'U' ? w_l_uint_cast(arg, f, g) : 0;
	str[*i] == 'C' ? w_elsie_cast(arg, f, g) : 0;
	str[*i] == 'S' ? w_loss_cast(arg, f, g) : 0;
	supa_free(f, g);
}

/*
** Precision flags with the c conversion results in undefined behavior
*/

void	wp_parse(const char *str, int *i, va_list arg, t_flags *f, t_wp *g)
{
	str[*i] == 'd' ? wp_int_cast(arg, f, g) : 0;
	str[*i] == 'i' ? wp_int_cast(arg, f, g) : 0;
	str[*i] == 'o' ? wp_oct_cast(arg, f, g) : 0;
	str[*i] == 'x' ? wp_lhex_cast(arg, f, g) : 0;
	str[*i] == 'X' ? wp_hex_cast(arg, f, g) : 0;
	str[*i] == 'u' ? wp_uint_cast(arg, f, g) : 0;
	str[*i] == 's' ? wp_str_cast(arg, f, g) : 0;
	str[*i] == 'j' ? wp_parse_j(arg, i, str, f, g) : 0;
	str[*i] == 'z' ? wp_parse_z(arg, i, str, f, g) : 0;
	(str[*i] == 'h' && str[*i + 1] != 'h') ? wp_parse_h(arg, i, str, f, g)
		: 0;
	(str[*i] == 'h' && str[*i + 1] == 'h') ? wp_parse_hh(arg, i, str, f, g)
		: 0;
	(str[*i] == 'l' && str[*i + 1] != 'l') ? wp_parse_l(arg, i, str, f, g)
		: 0;
	(str[*i] == 'l' && str[*i + 1] == 'l') ? wp_parse_ll(arg, i, str, f, g)
		: 0;
	str[*i] == 'O' ? wp_l_oct_cast(arg, f, g) : 0;
	str[*i] == 'D' ? wp_l_int_cast(arg, f, g) : 0;
	str[*i] == 'U' ? wp_l_uint_cast(arg, f, g) : 0;
	supa_free(f, g);
}


void	parse_width_and_prec(const char *str, int *i, va_list arg)
{
	t_flags	*f;
	t_wp	*g;
	int		prec_flag;

	g = (t_wp *)malloc(sizeof(t_wp*));
	f = (t_flags *)malloc(sizeof(t_flags*));
	prec_flag = 0;
	rip_n_tear(str, i, f);
	g->width = ft_atoi(str + *i);
	g->width > 0 ? *i += (ft_numlen(g->width, 10) + 1) : 0;
	g->width <= 0 ? *i += 1 : 0;
	if (str[*i] == '.')
	{
		prec_flag = 1;
		*i += 1;
		g->prec = ft_atoi(str + *i);
		if (g->prec == 0 && ft_isdigit(str[*i]))
			*i += 1;
		else if (g->prec > 0)
			*i += ft_numlen(g->prec, 10);
	}
	prec_flag == 1 ? wp_parse(str, i, arg, f, g) : w_parse(str, i, arg, f, g);
}
