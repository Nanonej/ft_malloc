/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 20:17:58 by aridolfi          #+#    #+#             */
/*   Updated: 2016/11/08 21:00:10 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char *tmp;

	tmp = (char*)s;
	while (*tmp != c && *tmp)
		tmp++;
	return (*tmp == c ? tmp : NULL);
}
