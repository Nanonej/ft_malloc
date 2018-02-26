/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 13:59:34 by aridolfi          #+#    #+#             */
/*   Updated: 2016/11/13 20:30:04 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*new;
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	while (ft_iswhitespace(s[i]))
		i++;
	if (!s[i])
		return (ft_strnew(1));
	n = ft_strlen(s) - 1;
	while (ft_iswhitespace(s[n]))
		n--;
	n = n - i + 1;
	if (!(new = ft_strsub(s, i, n)))
		return (NULL);
	return (new);
}
