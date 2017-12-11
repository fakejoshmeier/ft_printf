/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_saver.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 22:36:45 by jmeier            #+#    #+#             */
/*   Updated: 2017/12/10 19:01:04 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	s_saver(int i, int output, char c, t_flags *f, t_wp *g)
{
	if (f->plus || f->spess || output < 0)
	{
		i < g->prec ? ft_putchars(c, g->width - (1 + g->prec)) :
			ft_putchars(c, g->width - (i + 1));
	}
	else
	{
		i < g->prec ? ft_putchars(c, g->width - g->prec) :
			ft_putchars(c, g->width - i);
	}
}

void	s_saver2(int i, int base, t_flags *f, t_wp *g)
{
	if (i < g->prec)
	{
		f->hash && base == 16 ? ft_putchars(' ', g->width - (2 + g->prec)) : 0;
		f->hash && base == 8 ? ft_putchars(' ', g->width - (1 + g->prec)) : 0;
		ft_putchars(' ', g->width - g->prec);
	}
	else
	{
		f->hash && base == 16 ? ft_putchars(' ', g->width - (2 + i)) : 0;
		f->hash && base == 8 ? ft_putchars(' ', g->width - (1 + i)) : 0;
		ft_putchars(' ', g->width - g->prec);
	}
}

void	s_saver3(int i, int output, t_flags *f, t_wp *g)
{
	if (f->plus || f->spess || output < 0)
	{
		if (f->zero)
			ft_putchars('0', g->width - (1 + i));
		else
			ft_putchars(' ', g->width - (1 + i));
	}
	else
	{
		if (f->zero)
			ft_putchars('0', g->width - i);
		else
			ft_putchars(' ', g->width - i);
	}
}

void	s_saver4(int i, int base, t_flags *f, t_wp *g)
{
	if (f->hash)
	{
		if (f->zero)
		{
			base == 8 ? ft_putchars('0', g->width - (1 + i)) : 0;
			base == 16 ? ft_putchars('0', g->width - (2 + 1)) : 0;
		}
		else
		{
			base == 8 ? ft_putchars(' ', g->width - (1 + i)) : 0;
			base == 16 ? ft_putchars(' ', g->width - (2 + 1)) : 0;
		}
	}
	else
	{
		if (f->zero)
			ft_putchars('0', g->width - i);
		else
			ft_putchars(' ', g->width - i);
	}
}

void	supa_free(t_flags *f, t_wp *g)
{
	free(g);
	free(f);
}
