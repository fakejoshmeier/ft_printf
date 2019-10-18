/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 00:32:34 by jmeier            #+#    #+#             */
/*   Updated: 2019/10/17 17:41:30 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthex(unsigned long long n, int fd)
{
	if (n > 15)
	{
		ft_puthex(n / 16, fd);
		ft_puthex(n % 16, fd);
	}
	else if (n < 10)
		ft_putchar_fd(n + '0', fd);
	else
	{
		n == 10 ? ft_putchar_fd('A', fd) : 0;
		n == 11 ? ft_putchar_fd('B', fd) : 0;
		n == 12 ? ft_putchar_fd('C', fd) : 0;
		n == 13 ? ft_putchar_fd('D', fd) : 0;
		n == 14 ? ft_putchar_fd('E', fd) : 0;
		n == 15 ? ft_putchar_fd('F', fd) : 0;
	}
}
