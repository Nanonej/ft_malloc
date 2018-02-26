/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strendcpy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/05 19:13:42 by aridolfi          #+#    #+#             */
/*   Updated: 2017/02/05 19:15:21 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strendcpy(char *dest, const char *src)
{
	int		i;
	int		j;

	i = ft_strlen(dest);
	j = ft_strlen(src);
	while (i >= 0 && j >= 0)
	{
		dest[i] = src[j];
		--i;
		--j;
	}
	return (dest);
}
