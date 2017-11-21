/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 14:48:22 by jmeier            #+#    #+#             */
/*   Updated: 2017/11/08 19:47:19 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size, size_t new_size)
{
	void	*new;

	C_ASSERT(ptr);
	if (!(new = ft_memalloc(size)))
	{
		free(ptr);
		return (NULL);
	}
	ft_memcpy(new, ptr, size < new_size ? size : new_size);
	free(ptr);
	return (new);
}
