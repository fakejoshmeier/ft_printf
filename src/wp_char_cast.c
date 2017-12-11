/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wp_char_cast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 19:09:56 by jmeier            #+#    #+#             */
/*   Updated: 2017/12/10 18:51:14 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	wp_str_cast(va_list arg, t_flags *f, t_wp *g)
{
	char	*output;

	output = va_arg(arg, char *);
	char_wp(f, g, output);
}

void	wp_loss_cast(va_list arg, t_flags *f, t_wp *g)
{
	wchar_t			*output;

	output = va_arg(arg, wchar_t*);
	wchar_wp(f, g, output);
}
