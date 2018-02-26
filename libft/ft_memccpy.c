/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:11:24 by aridolfi          #+#    #+#             */
/*   Updated: 2016/11/08 09:24:41 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char *tmp;

	tmp = dest;
	while (n--)
		if ((*tmp++ = *(unsigned char*)src++) == c)
		{
			dest = tmp;
			return (dest);
		}
	return (NULL);
}
