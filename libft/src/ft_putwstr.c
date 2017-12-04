/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 13:42:11 by jmeier            #+#    #+#             */
/*   Updated: 2017/12/03 14:11:19 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_widelen(wchar_t *str)
{
	int	i;

	i = -1;
	while (str[++i])
		;
	return (i);
}

void		ft_putwstr(wchar_t *str)
{
	int	i;

	if (str)
	{
		i = -1;
		while (str[++i])
			write(1, &str[i], 1);
	}
}
