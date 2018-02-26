/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 13:36:00 by aridolfi          #+#    #+#             */
/*   Updated: 2016/11/12 00:08:23 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	i = -1;
	if (!(new = ft_strnew(len)))
		return (NULL);
	while (++i < len)
		new[i] = s[start + i];
	new[i] = '\0';
	return (new);
}
