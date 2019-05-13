/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dll.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 06:53:54 by jmeier            #+#    #+#             */
/*   Updated: 2019/05/13 01:18:01 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Doubly Linked List implementation
*/

t_dll	*ft_dllnew(void const *content, size_t content_size)
{
	t_dll	*tmp;

	if (!(tmp = (t_dll *)malloc(sizeof(t_dll))))
		return (NULL);
	if (!content)
	{
		tmp->content = NULL;
		tmp->content_size = 0;
	}
	else
	{
		if (!(tmp->content = malloc(content_size)))
		{
			free(tmp);
			return (NULL);
		}
		ft_memcpy(tmp->content, (void *)content, content_size);
		tmp->content_size = content_size;
	}
	tmp->next = NULL;
	tmp->prev = NULL;
	return (tmp);
}

/*
** Given a single node on a dll, I should be able to delete them all.
*/

void	ft_dlldel(t_dll **dll, void (*free_fn)(void *, size_t))
{
	t_dll	*a;
	t_dll	*b;

	if (!dll || !*dll)
		return ;
	a = *dll->next;
	b = *dll->prev;
	free_fn((*dll)->content, (*dll)->content_size);
	free(*dll);
	ft_dlldel(&a, free_fn);
	ft_dlldel(&b, free_fn);
}

void	ft_dlladd(t_dll **dll, t_dll *new)
{
	if (!dll || !new)
		return ;
	new->next = *alst;
	new->prev = NULL;
	(*alst)->prev = new;
	*alst = new;
}
