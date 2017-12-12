/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_saver.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 22:36:45 by jmeier            #+#    #+#             */
/*   Updated: 2017/12/11 23:19:31 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	s_saver(int i, int output, char c, t_all *f)
{
	if (f->plus == 1 || f->spess == 1 || output < 0)
	{
		i < f->prec ? ft_putchars(c, f->width - (1 + f->prec)) :
			ft_putchars(c, f->width - (i + 1));
	}
	else
	{
		i < f->prec ? ft_putchars(c, f->width - f->prec) :
			ft_putchars(c, f->width - i);
	}
}

void	s_saver2(int i, int base, t_all *f)
{
	if (i < f->prec)
	{
		f->hash == 1 && base == 16 ?
			ft_putchars(' ', f->width - (2 + f->prec)) : 0;
		f->hash == 1 && base == 8 ?
			ft_putchars(' ', f->width - (1 + f->prec)) : 0;
		ft_putchars(' ', f->width - f->prec);
	}
	else
	{
		f->hash == 1 && base == 16 ? ft_putchars(' ', f->width - (2 + i)) : 0;
		f->hash == 1 && base == 8 ? ft_putchars(' ', f->width - (1 + i)) : 0;
		ft_putchars(' ', f->width - f->prec);
	}
}

void	s_saver3(int i, int output, t_all *f)
{
	if (f->plus == 1 || f->spess == 1 || output < 0)
	{
		if (f->zero == 1)
			ft_putchars('0', f->width - (1 + i));
		else
			ft_putchars(' ', f->width - (1 + i));
	}
	else
	{
		if (f->zero == 1)
			ft_putchars('0', f->width - i);
		else
			ft_putchars(' ', f->width - i);
	}
}

void	s_saver4(int i, int base, t_all *f)
{
	if (f->hash == 1)
	{
		if (f->zero == 1)
		{
			base == 8 ? ft_putchars('0', f->width - (1 + i)) : 0;
			base == 16 ? ft_putchars('0', f->width - (2 + 1)) : 0;
		}
		else
		{
			base == 8 ? ft_putchars(' ', f->width - (1 + i)) : 0;
			base == 16 ? ft_putchars(' ', f->width - (2 + 1)) : 0;
		}
	}
	else
	{
		if (f->zero == 1)
			ft_putchars('0', f->width - i);
		else
			ft_putchars(' ', f->width - i);
	}
}

void	supa_free(t_all *f)
{
	free(f);
}
