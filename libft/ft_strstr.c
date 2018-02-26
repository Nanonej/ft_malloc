/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 12:18:51 by aridolfi          #+#    #+#             */
/*   Updated: 2016/11/09 14:08:41 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	if (!*haystack)
		return (*needle == *haystack ? (char*)haystack : NULL);
	while (*haystack)
	{
		if (ft_strnequ(needle, haystack, ft_strlen(needle)))
			return ((char*)haystack);
		haystack++;
	}
	return (NULL);
}
