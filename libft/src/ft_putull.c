/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putull.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 20:44:37 by jmeier            #+#    #+#             */
/*   Updated: 2019/10/18 16:54:35 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putull(unsigned long long n, int fd)
{
	if (n >= 10)
	{
		ft_putull(n / 10, fd);
		ft_putull(n % 10, fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}
