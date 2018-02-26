/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 21:19:57 by aridolfi          #+#    #+#             */
/*   Updated: 2016/11/08 21:38:37 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		n;
	char	*tmp;

	n = ft_strlen(s);
	tmp = (char*)s + n;
	while (n-- && *tmp != c)
		tmp--;
	return (*tmp == c ? tmp : NULL);
}
