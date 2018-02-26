/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 11:23:10 by aridolfi          #+#    #+#             */
/*   Updated: 2016/11/12 00:07:25 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	int		i;

	i = -1;
	if (!(new = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (s[++i])
		new[i] = (*f)(i, s[i]);
	new[i] = '\0';
	return (new);
}
