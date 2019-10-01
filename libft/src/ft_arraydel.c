/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraydel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 02:15:34 by jmeier            #+#    #+#             */
/*   Updated: 2019/10/01 11:48:18 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_arrlen(char **arr)
{
	int		i;

	i = 0;
	while (*arr[i])
		++i;
	return (i);
}

char	**ft_arraydel(char ***array)
{
	int		i;

	if (!array || !(*array))
		return (NULL);
	i = -1;
	while ((*array)[++i])
	{
		free((*array)[i]);
		write(1, "FREE\n", 5);
		(*array)[i] = NULL;
	}
	free(*array);
	return ((*array = NULL));
}
