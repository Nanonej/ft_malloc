/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 18:37:18 by aridolfi          #+#    #+#             */
/*   Updated: 2016/11/08 19:28:50 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
		n--;
	}
	return (n ? *(unsigned char*)s1 - *(unsigned char*)s2 : 0);
}
