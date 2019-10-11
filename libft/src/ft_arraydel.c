/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arraydel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 02:15:34 by jmeier            #+#    #+#             */
/*   Updated: 2019/10/10 16:54:48 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_arrlen(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
		++i;
	return (i);
}

char	**ft_arr_add(char **arr, char *add)
{
	char	**new;
	int		len;
	int		i;

	if (arr)
		len = ft_arrlen(arr) + 1;
	else
		len = 1;
	if (!(new = (char**)malloc(sizeof(char*) * (len + 1))))
		return (NULL);
	*(new + len) = 0;
	i = 0;
	while (arr && *(arr + i))
	{
		*(new + i) = *(arr + i);
		i++;
	}
	*(new + i) = ft_strdup(add);
	free(arr);
	return (new);
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
		(*array)[i] = NULL;
	}
	free(*array);
	return ((*array = NULL));
}
