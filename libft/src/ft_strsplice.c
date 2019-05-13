/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplice.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmeier <jmeier@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 22:43:52 by jmeier            #+#    #+#             */
/*   Updated: 2019/05/13 01:16:11 by jmeier           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Given a string 'splice' and another string 'insert', after 'splice_adr',
** the entirety of 'insert' is placed into 'splice'.
** Returns the spliced string, which is malloced.
** Does not free original string
*/

char	*ft_strsplice(char **splice, char *splice_adr, char *insert)
{
	char	*ret;
	char	*tmp;
	int		ret_len;
	int		i;

	NULL_GUARD(!splice_adr || !splice);
	if (!splice || !(*splice) || (!(ret_len = ft_strlen(*splice) +
		ft_strlen(insert))))
		return (*splice);
	NULL_GUARD(ret = ft_strnew(ret_len));
	i = -1;
	tmp = *splice;
	while (tmp != splice_adr && *tmp)
		ret[++i] = *(tmp++);
	while (*insert)
		ret[++i] = *(insert++);
	while (*tmp)
		ret[++i] = *(tmp++);
	return (ret);
}

/*
** Frees original string
*/

char	*ft_strfsplice(char **splice, char *splice_adr, char *insert)
{
	char	*ret;
	char	*tmp;
	int		ret_len;
	int		i;

	NULL_GUARD(!splice_adr || !splice);
	if (!splice || !(*splice) || (!(ret_len = ft_strlen(*splice) +
		ft_strlen(insert))))
		return (*splice);
	NULL_GUARD(ret = ft_strnew(ret_len));
	i = -1;
	tmp = *splice;
	while (tmp != splice_adr && *tmp)
		ret[++i] = *(tmp++);
	while (*insert)
		ret[++i] = *(insert++);
	while (*tmp)
		ret[++i] = *(tmp++);
	ft_strdel(splice);
	return (ret);
}
