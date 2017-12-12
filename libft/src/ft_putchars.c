/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 14:09:59 by jmeier            #+#    #+#             */
/*   Updated: 2017/12/11 17:39:37 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchars(char c, int amt)
{
	int		i;

	i = -1;
	while (++i < amt)
		write(1, &c, 1);
}

int		main(void)
{
	ft_putchars('i', 0);
	ft_putchars('\n', 1);
	ft_putchars('0', 4);
	ft_putchars('\n', 1);
	ft_putchars('i', -2);
	ft_putchars('\n', 1);
	return (0);
}
