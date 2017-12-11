/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 14:09:59 by jmeier            #+#    #+#             */
/*   Updated: 2017/12/10 21:29:07 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchars(char c, int amt)
{
	int		i;

	i = -1;
	while (++i <= amt)
		write(1, &c, 1);
}

int		main(void)
{
	char c = 'i';

	ft_putchars(c, 5);
	ft_putchar('\n');
	return (0);
}
