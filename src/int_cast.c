/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 10:59:06 by jmeier            #+#    #+#             */
/*   Updated: 2019/10/17 18:34:42 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	int_cast(va_list arg, t_all *f)
{
	char			*prec_pad;
	char			*width_pad;
	char			*prefix;
	int				output;

	output = va_arg(arg, int);
	prec_pad = sign_prec_parse(output, f);
	width_pad = sign_width_parse(output, f);
	prefix = sign_prefix_parse(output, f);
	if (f->dash == 1)
	{
		ft_putstr_fd(prefix, f->fd);
		ft_putstr_fd(prec_pad, f->fd);
		ft_putnbrf((int)output, f->fd);
		ft_putstr_fd(width_pad, f->fd);
	}
	else
	{
		f->zero == 0 || f->prec_flag == 1 ? ft_putstr_fd(width_pad, f->fd) : 0;
		ft_putstr_fd(prefix, f->fd);
		f->zero == 1 && f->prec_flag == 0 ? ft_putstr_fd(width_pad, f->fd) : 0;
		ft_putstr_fd(prec_pad, f->fd);
		ft_putnbrf((int)output, f->fd);
	}
	supa_free(prec_pad, width_pad, prefix);
}

void	oct_cast(va_list arg, t_all *f)
{
	char			*prec_pad;
	char			*width_pad;
	char			*prefix;
	unsigned int	output;

	output = va_arg(arg, unsigned int);
	prec_pad = prec_parse((unsigned long long)output, f, 8);
	width_pad = width_parse((unsigned long long)output, f, 8);
	prefix = prefix_parse((unsigned int)output, 8, 0, f);
	if (f->dash == 1)
	{
		ft_putstr_fd(prefix, f->fd);
		ft_putstr_fd(prec_pad, f->fd);
		ft_putoct((unsigned long long)output, f->fd);
		ft_putstr_fd(width_pad, f->fd);
	}
	else
	{
		f->prec_flag == 1 ? ft_putstr_fd(width_pad, f->fd) : 0;
		ft_putstr_fd(prefix, f->fd);
		f->zero == 1 && f->prec_flag == 0 ? ft_putstr_fd(width_pad, f->fd) : 0;
		ft_putstr_fd(prec_pad, f->fd);
		ft_putoct((unsigned long long)output, f->fd);
	}
	supa_free(prec_pad, width_pad, prefix);
}

void	hex_cast(va_list arg, t_all *f)
{
	char			*prec_pad;
	char			*width_pad;
	char			*prefix;
	unsigned int	output;

	output = va_arg(arg, unsigned int);
	prec_pad = prec_parse((unsigned long long)output, f, 16);
	width_pad = width_parse((unsigned long long)output, f, 16);
	prefix = prefix_parse((unsigned int)output, 16, 1, f);
	if (f->dash == 1)
	{
		ft_putstr_fd(prefix, f->fd);
		ft_putstr_fd(prec_pad, f->fd);
		ft_puthex((unsigned long long)output, f->fd);
		ft_putstr_fd(width_pad, f->fd);
	}
	else
	{
		f->zero == 0 ? ft_putstr_fd(width_pad, f->fd) : 0;
		ft_putstr_fd(prefix, f->fd);
		f->zero == 1 && f->prec_flag == 0 ? ft_putstr_fd(width_pad, f->fd) : 0;
		ft_putstr_fd(prec_pad, f->fd);
		ft_puthex((unsigned long long)output, f->fd);
	}
	supa_free(prec_pad, width_pad, prefix);
}

void	lhex_cast(va_list arg, t_all *f)
{
	char			*prec_pad;
	char			*width_pad;
	char			*prefix;
	unsigned int	output;

	output = va_arg(arg, unsigned int);
	prec_pad = prec_parse((unsigned long long)output, f, 16);
	width_pad = width_parse((unsigned long long)output, f, 16);
	prefix = prefix_parse((unsigned int)output, 16, 0, f);
	if (f->dash == 1)
	{
		ft_putstr_fd(prefix, f->fd);
		ft_putstr_fd(prec_pad, f->fd);
		ft_putlhex((unsigned long long)output, f->fd);
		ft_putstr_fd(width_pad, f->fd);
	}
	else
	{
		f->zero == 0 ? ft_putstr_fd(width_pad, f->fd) : 0;
		ft_putstr_fd(prefix, f->fd);
		f->zero == 1 && f->prec_flag == 0 ? ft_putstr_fd(width_pad, f->fd) : 0;
		ft_putstr_fd(prec_pad, f->fd);
		ft_putlhex((unsigned long long)output, f->fd);
	}
	supa_free(prec_pad, width_pad, prefix);
}

void	uint_cast(va_list arg, t_all *f)
{
	char			*prec_pad;
	char			*width_pad;
	char			*prefix;
	unsigned int	output;

	output = va_arg(arg, unsigned int);
	prec_pad = prec_parse((unsigned long long)output, f, 10);
	width_pad = width_parse((unsigned long long)output, f, 10);
	prefix = prefix_parse((unsigned int)output, 10, 0, f);
	if (f->dash == 1)
	{
		ft_putstr_fd(prefix, f->fd);
		ft_putstr_fd(prec_pad, f->fd);
		ft_putunbr_base_fd(output, 10, f->fd);
		ft_putstr_fd(width_pad, f->fd);
	}
	else
	{
		f->zero == 0 ? ft_putstr_fd(width_pad, f->fd) : 0;
		ft_putstr_fd(prefix, f->fd);
		f->zero == 1 && f->prec_flag == 0 ? ft_putstr_fd(width_pad, f->fd) : 0;
		ft_putstr_fd(prec_pad, f->fd);
		ft_putunbr_base_fd(output, 10, f->fd);
	}
	supa_free(prec_pad, width_pad, prefix);
}
