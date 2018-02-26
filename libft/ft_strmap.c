/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 10:10:50 by aridolfi          #+#    #+#             */
/*   Updated: 2016/11/12 00:07:21 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new;
	int		i;

	i = -1;
	if (!(new = ft_strnew(ft_strlen(s))))
		return (NULL);
	while (s[++i])
		new[i] = (*f)(s[i]);
	new[i] = '\0';
	return (new);
}
