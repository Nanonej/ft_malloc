/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 14:51:52 by aridolfi          #+#    #+#             */
/*   Updated: 2017/01/17 14:46:45 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcat(void *s1, void *s2, size_t len1, size_t len2)
{
	void	*ret;
	void	*tmp;

	ret = ft_strnew(len1 + len2);
	if (ret == NULL)
		return (NULL);
	tmp = ret;
	ret = ft_memcpy(ret, s1, len1);
	tmp = ft_memcpy(ret + len1, s2, len2);
	return (ret);
}
