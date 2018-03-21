#include "libft.h"

int		ft_stricmp(char const *a, char const *b)
{
	size_t	i;
	int		a;

	i = 0;
	a = -1;
	while (a[++a])
		ft_tolower(a[a]);
	a = -1;
	while (b[++a])
		ft_tolower(b[a]);
	while (s1[i] && s1[i] == s2[i])
		i++;
	return ((*((unsigned char *)s1 + i)) - (*((unsigned char *)s2 + i)));
}