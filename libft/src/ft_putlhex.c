/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlhex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 00:34:03 by jmeier            #+#    #+#             */
/*   Updated: 2019/10/17 17:45:49 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putlhex(unsigned long long n, int fd)
{
	if (n > 15)
	{
		ft_putlhex(n / 16, fd);
		ft_putlhex(n % 16, fd);
	}
	else if (n < 10)
		ft_putchar_fd(n + '0', fd);
	else
	{
		n == 10 ? ft_putchar_fd('a', fd) : 0;
		n == 11 ? ft_putchar_fd('b', fd) : 0;
		n == 12 ? ft_putchar_fd('c', fd) : 0;
		n == 13 ? ft_putchar_fd('d', fd) : 0;
		n == 14 ? ft_putchar_fd('e', fd) : 0;
		n == 15 ? ft_putchar_fd('f', fd) : 0;
	}
}
