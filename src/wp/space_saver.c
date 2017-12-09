/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_saver.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 22:36:45 by jmeier            #+#    #+#             */
/*   Updated: 2017/12/08 23:47:12 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	s_saver(int i, int output, char c, t_flag *f, t_wp *g)
{
	if (f.plus || f.spess || output < 0)
	{
		i < g.prec ? ft_putchars(c, g.width - (1 + g.prec)) :
			ft_putchars(c, g.width - (i + 1));
	}
	i < g.prec ? ft_putchars(c, g.width - g.prec) : ft_putchars(c, g.width - i);
}

void	s_saver2(int i, int output, int base, t_flag *f, t_wp *g)
{
	if (i < g.prec)
	{
		f.hash && base == 16 ? ft_putchars(' ', g.width - (2 + g.prec)) : 0;
		f.hash && base == 8 ? ft_putchars(' ', g.width - (1 + g.prec)) : 0;
		ft_putchars(' ', g.width - g.prec);
	}
	else
	{
		f.hash && base == 16 ? ft_putchars(' ', g.width - (2 + i)) : 0;
		f.hash && base == 8 ? ft_putchars(' ', g.width - (1 + i)) : 0;
		ft_putchars(' ', g.width - g.prec);
	}
}
