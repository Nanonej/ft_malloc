/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/06 18:50:04 by aridolfi          #+#    #+#             */
/*   Updated: 2016/11/08 09:38:21 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char *dup;

	if ((dup = (char*)malloc(sizeof(char) * (ft_strlen(s) + 1))) == NULL)
		return (NULL);
	ft_strcpy(dup, s);
	return (dup);
}
