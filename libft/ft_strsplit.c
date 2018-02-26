/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 17:40:16 by aridolfi          #+#    #+#             */
/*   Updated: 2016/11/12 00:09:20 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_splittedcount(char *s, char c)
{
	size_t	nb;

	while (*s && *s == c)
		s++;
	nb = (*s ? 1 : 0);
	while (*s)
	{
		if (*s == c && *(s + 1) != c && *(s + 1))
			nb++;
		s++;
	}
	return (nb);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	n;
	char	*tmp;
	char	**new;

	n = ft_splittedcount((char*)s, c);
	if ((new = (char**)malloc(sizeof(char*) * (n + 1))) == NULL)
		return (NULL);
	tmp = (char*)s;
	while (*s)
	{
		if (*s == c)
		{
			if (tmp != s)
				*(new++) = ft_strsub(tmp, 0, s - tmp);
			tmp = (char*)s + 1;
		}
		s++;
	}
	if (tmp != s)
		*(new++) = ft_strsub(tmp, 0, s - tmp);
	*new = NULL;
	return (new - n);
}
