/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freaking_wide.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 02:01:55 by jmeier            #+#    #+#             */
/*   Updated: 2017/12/10 19:10:06 by jmeier           ###   ########.fr       */
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

void	wchar_wp(t_flags *f, t_wp *g, wchar_t *out)
{
	char	*n;
	int		i;

	n = "(null)";
	out == NULL ? i = 6 : 0;
	out != NULL ? i = ft_widelen(out) : 0;
	if (f->dash)
	{
		if (g->prec != 0)
			out != NULL ? ft_putwsn(out, g->prec) : ft_putstrn(n, g->prec);
		if (g->prec >= i)
			ft_putchars(' ', g->width - i);
		else if (i > g->prec)
			f->zero ? ft_putchars('0', g->width - g->prec) :
				ft_putchars(' ', g->width - g->prec);
	}
	else if (!f->dash)
	{
		if (g->prec >= i)
			ft_putchars(' ', g->width - i);
		else
			ft_putchars(' ', g->width - g->prec);
		if (g->prec != 0)
			out != NULL ? ft_putwsn(out, g->prec) : ft_putstrn(n, g->prec);
	}
}

void	wchar_w(t_flags *f, t_wp *g, wchar_t *output)
{
	char	*n;
	int		i;

	output != NULL ? i = ft_widelen(output) : 0;
	output == NULL ? i = 6 : 0;
	n = "(null)";
	if (f->dash)
	{
		output != NULL ? ft_putwstr(output) : ft_putstr(n);
		ft_putchars(' ', g->width - i);
	}
	else
	{
		ft_putchars(' ', g->width - i);
		output != NULL ? ft_putwstr(output) : ft_putstr(n);
	}
}
