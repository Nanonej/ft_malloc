/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 22:11:53 by aridolfi          #+#    #+#             */
/*   Updated: 2016/11/08 22:27:59 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *alloc;

	if ((alloc = (void*)malloc(sizeof(char) * size)) == NULL)
		return (NULL);
	ft_bzero(alloc, size);
	return (alloc);
}
