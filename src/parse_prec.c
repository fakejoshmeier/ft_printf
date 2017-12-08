/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_prec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 19:33:34 by jmeier            #+#    #+#             */
/*   Updated: 2017/12/07 23:52:35 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	rip_n_tear(const char *str, int *i, t_flags f)
{
	int				j;

	j = *i;
	while (!ft_isvalue(str[j++]))
	{
		str[j] == '-' ? f.dash_flag = 1 : 0;
		str[j] == '0' ? f.zero_flag = 1 : 0;
		str[j] == '+' ? f.plus_flag = 1 : 0;
		str[j] == ' ' ? f.spess_flag = 1 : 0;
		str[j] == '#' ? f.hash_flag = 1 : 0;
	}
	f.dash_flag == 1 ? f.zero_flag = 0 : 0;
	f.plus_flag == 1 ? f.spess_flag = 0 : 0;
	*i = j;
}

void	w_parse(const char *str, int *i, va_list arg, t_flags f, t_wp g)
{
	if (f.hash_flag == 1 && (f.zero_flag == 1 || f.dash_flag == 1))
	{
		str[*i] == 'o' || str[*i] == 'O' ? ft_putchar('0') : 0;
		str[*i] == 'x' ? ft_putstr("0x") : 0;
		str[*i] == 'X' ? ft_putstr("0X") : 0;
	}
	str[*i] == 'd' ? w_int_cast(arg, f, g) : 0;
	str[*i] == 'i' ? w_int_cast(arg, f, g) : 0;
	str[*i] == 'o' ? w_oct_cast(arg, f, g) : 0;
	str[*i] == 'x' ? w_lhex_cast(arg, f, g) : 0;
	str[*i] == 'X' ? w_hex_cast(arg, f, g) : 0;
	str[*i] == 'u' ? w_uint_cast(arg, f, g) : 0;
	str[*i] == 'c' ? w_char_cast(arg, f, g) : 0;
	str[*i] == 's' ? w_str_cast(arg, f, g) : 0;
	str[*i] == 'j' ? w_parse_jflag(arg, i, str, f, g) : 0;
	str[*i] == 'z' ? w_parse_zflag(arg, i, str, f, g) : 0;
	(str[*i] == 'h' && str[*i + 1] != 'h') ? w_parse_hflag(arg, i, str, f, g)
		: 0;
	(str[*i] == 'h' && str[*i + 1] == 'h') ? w_parse_hhflag(arg, i, str, f, g)
		: 0;
	(str[*i] == 'l' && str[*i + 1] != 'l') ? w_parse_lflag(arg, i, str, f, g)
		: 0;
	(str[*i] == 'l' && str[*i + 1] == 'l') ? w_parse_llflag(arg, i, str, f, g)
		: 0;
}

void»···wp_parse(const char *str, int *i, va_list arg, t_flags f, t_wp g)
{
	if (f.hash_flag == 1)
	{
		str[*i] == 'o' || str[*i] == 'O' ? ft_putchar('0') : 0;
		str[*i] == 'x' ? ft_putstr("0x") : 0;
		str[*i] == 'X' ? ft_putstr("0X") : 0;
	}
	str[*i] == 'd' ? wp_int_cast(arg, f, g) : 0;
	str[*i] == 'i' ? wp_int_cast(arg, f, g) : 0;
	str[*i] == 'o' ? wp_oct_cast(arg, f, g) : 0;
	str[*i] == 'x' ? wp_lhex_cast(arg, f, g) : 0;
	str[*i] == 'X' ? wp_hex_cast(arg, f, g) : 0;
	str[*i] == 'u' ? wp_uint_cast(arg, f, g) : 0;
	str[*i] == 'c' ? wp_char_cast(arg, f, g) : 0;
	str[*i] == 's' ? wp_str_cast(arg, f, g) : 0;
	str[*i] == 'j' ? wp_parse_jflag(arg, i, str, f, g) : 0;
	str[*i] == 'z' ? wp_parse_zflag(arg, i, str, f, g) : 0;
	(str[*i] == 'h' && str[*i + 1] != 'h') ? wp_parse_hflag(arg, i, str, f, g)
		: 0;
	(str[*i] == 'h' && str[*i + 1] == 'h') ? wp_parse_hhflag(arg, i, str, f, g)
		: 0;
	(str[*i] == 'l' && str[*i + 1] != 'l') ? wp_parse_lflag(arg, i, str, f, g)
		: 0;
	(str[*i] == 'l' && str[*i + 1] == 'l') ? wp_parse_llflag(arg, i, str, f, g)
		: 0;
}

void	parse_width_and_prec(const char *str, int *i, va_list arg)
{
	static t_flags	f;
	static t_wp		g;
	int				prec_flag;

	prec_flag = 0;
	rip_n_tear(str, i, f);
	g.width = ft_atoi(str + *i);
	g.width > 0 ? i* += (ft_numlen(g.width) + 1) : i* += 1;
	if (str[*i] == '.')
	{
		prec_flag = 1;
		i* += 1;
		prec = ft_atoi(str + *i);
		if (prec == 0 && ft_isdigit(str[*i]))
			i* += 1;
		else if (prec > 0)
			i* += ft_numlen(prec);
	}
	prec_flag == 1 ? wp_parse(str, i, arg, f, g) : w_parse(str, i, arg, f, g);
}
