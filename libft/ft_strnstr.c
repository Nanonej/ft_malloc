/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 14:15:40 by aridolfi          #+#    #+#             */
/*   Updated: 2016/11/09 16:46:15 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	int i;

	i = 0;
	if (!*haystack)
		return (*needle == *haystack ? (char*)haystack : NULL);
	while (*haystack)
	{
		if (ft_strnequ(needle, haystack, ft_strlen(needle)))
			if (ft_strlen(needle) + i <= n)
				return ((char*)haystack);
		i++;
		haystack++;
	}
	return (NULL);
}
