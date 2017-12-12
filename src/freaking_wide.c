/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freaking_wide.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 02:01:55 by jmeier            #+#    #+#             */
/*   Updated: 2017/12/11 21:09:28 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_widelen(wchar_t *s)
{
	int		i;

	i = -1;
	while (s[++i])
		;
	return (i);
}

void	ft_putwsn(wchar_t *s, int n)
{
	int		i;

	i = -1;
	if (s)
	{
		if (ft_widelen(s) < n)
		{
			while (++i <= n)
				write(1, &s[i], 1);
		}
		else
		{
			while (s[++i])
				write(1, &s[i], 1);
		}
	}
}

void	wchar_wp(t_all *f, wchar_t *out)
{
	char	*n;
	int		i;

	n = "(null)";
	out == NULL ? i = 6 : 0;
	out != NULL ? i = ft_widelen(out) : 0;
	if (f->dash)
	{
		if (f->prec != 0)
			out != NULL ? ft_putwsn(out, f->prec) : ft_putstrn(n, f->prec);
		if (f->prec >= i)
			ft_putchars(' ', f->width - i);
		else if (i > f->prec)
			f->zero ? ft_putchars('0', f->width - f->prec) :
				ft_putchars(' ', f->width - f->prec);
	}
	else if (!f->dash)
	{
		if (f->prec >= i)
			ft_putchars(' ', f->width - i);
		else
			ft_putchars(' ', f->width - f->prec);
		if (f->prec != 0)
			out != NULL ? ft_putwsn(out, f->prec) : ft_putstrn(n, f->prec);
	}
}

void	wchar_w(t_all *f, wchar_t *output)
{
	char	*n;
	int		i;

	output != NULL ? i = ft_widelen(output) : 0;
	output == NULL ? i = 6 : 0;
	n = "(null)";
	if (f->dash)
	{
		output != NULL ? ft_putwstr(output) : ft_putstr(n);
		ft_putchars(' ', f->width - i);
	}
	else
	{
		ft_putchars(' ', f->width - i);
		output != NULL ? ft_putwstr(output) : ft_putstr(n);
	}
}
