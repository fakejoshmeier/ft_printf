/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_cast.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 19:09:56 by jmeier            #+#    #+#             */
/*   Updated: 2019/10/17 18:03:12 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pita(wchar_t *pita)
{
	free(pita);
	pita = NULL;
}

void	char_cast(va_list arg, t_all *f)
{
	char	output;
	char	*padding;

	output = (char)va_arg(arg, int);
	padding = char_width(output, f);
	f->dash == 0 ? ft_putstr_fd(padding, f->fd) : 0;
	f->prec_flag == 1 ? char_prec(output, f) : write(f->fd, &output, 1);
	f->dash == 1 ? ft_putstr_fd(padding, f->fd) : 0;
	free(padding);
	padding = NULL;
}

void	str_cast(va_list arg, t_all *f)
{
	char	*output;
	char	*width;
	char	*prec;

	output = va_arg(arg, char*);
	width = str_width(output, f);
	prec = str_prec(output, f);
	if (f->prec_flag == 0)
	{
		f->dash == 0 ? ft_putstr_fd(width, f->fd) : 0;
		output != NULL ? ft_putstr_fd(output, f->fd) :
			ft_putstr_fd("(null)", f->fd);
		f->dash == 1 ? ft_putstr_fd(width, f->fd) : 0;
	}
	else
	{
		f->dash == 0 ? ft_putstr_fd(width, f->fd) : 0;
		ft_putstr_fd(prec, f->fd);
		f->dash == 1 ? ft_putstr_fd(width, f->fd) : 0;
	}
	free(width);
	free(prec);
	width = NULL;
	prec = NULL;
}

void	elsie_cast(va_list arg, t_all *f)
{
	wchar_t	output;
	char	*padding;

	output = (wchar_t)va_arg(arg, void*);
	padding = output != '\0' ? ft_strnew(f->width - 1) : ft_strnew(f->width);
	ft_memset(padding, ' ', (ft_strlen(padding)));
	f->dash == 0 ? ft_putstr_fd(padding, f->fd) : 0;
	if (f->prec_flag == 1)
		output != '\0' && f->prec >= 1 ? ft_putchar_fd((char)output, f->fd)
		: 0;
	else
		ft_putchar_fd((char)output, f->fd);
	f->dash == 1 ? ft_putstr_fd(padding, f->fd) : 0;
	free(padding);
	padding = NULL;
}

void	loss_cast(va_list arg, t_all *f)
{
	wchar_t	*output;
	wchar_t	*prec;
	char	*width;

	output = va_arg(arg, wchar_t*);
	width = wchar_width(output, f);
	prec = output != '\0' ? ft_wstrnew(f->prec) : ft_wstrnew(6);
	if (f->prec_flag == 0)
	{
		f->dash == 0 ? ft_putstr_fd(width, f->fd) : 0;
		output != NULL ? ft_putwstr(output) : ft_putstr_fd("(null)", f->fd);
		f->dash == 1 ? ft_putstr_fd(width, f->fd) : 0;
	}
	else
	{
		pita(prec);
		f->dash == 0 ? ft_putstr_fd(width, f->fd) : 0;
		prec = wchar_prec(output, f);
		prec != '\0' ? ft_putwstr(prec) : 0;
		f->dash == 1 ? ft_putstr_fd(width, f->fd) : 0;
	}
	free(prec);
	free(width);
	width = NULL;
	prec = NULL;
}
