/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 17:57:47 by aridolfi          #+#    #+#             */
/*   Updated: 2016/11/09 20:03:57 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char *tmp;

	tmp = dest;
	if (src > dest)
		dest = ft_memcpy(tmp, src, n);
	if (src < dest)
	{
		src = src + (n - 1);
		tmp = tmp + (n - 1);
		while (n)
		{
			*tmp-- = *(unsigned char*)src--;
			n--;
		}
	}
	return (dest);
}
