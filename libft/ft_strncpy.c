/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 18:58:52 by aridolfi          #+#    #+#             */
/*   Updated: 2016/11/08 12:45:18 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char *tmp;

	tmp = dest;
	while (*src && n)
	{
		*tmp++ = *src++;
		n--;
	}
	while (*tmp && n)
	{
		*tmp++ = '\0';
		n--;
	}
	return (dest);
}
