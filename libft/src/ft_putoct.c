/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putoct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 00:31:40 by jmeier            #+#    #+#             */
/*   Updated: 2019/10/17 17:47:27 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putoct(unsigned long long n, int fd)
{
	if (n > 7)
	{
		ft_putoct(n / 8, fd);
		ft_putoct(n % 8, fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}
