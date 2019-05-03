/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 19:55:13 by jmeier            #+#    #+#             */
/*   Updated: 2019/04/22 17:34:29 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_freek(void **ptr)
{
	void	*tmp;

	tmp = *ptr;
	free(tmp);
	tmp = NULL;
}

void	ft_free(void *tmp)
{
	free(tmp);
	tmp = NULL;
}
