/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 12:30:44 by aridolfi          #+#    #+#             */
/*   Updated: 2018/04/19 17:27:27 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_malloc.h"

static void	*realloc_alloc(t_map *start, void *ptr, size_t size)
{
	t_map	*list;

	list = start;
	while (list->next)
	{
		if (ptr == (list->next + 1))
		{
			if (!(ptr = malloc(size)))
				return (NULL);
			if ((long)size > (char*)list->next->end - (char *)list->next)
				size = (char *)list->next->end - (char *)list->next;
			ft_memcpy(ptr, list->next + 1, size);
			free(list->next);
			return (ptr);
		}
		list = list->next;
	}
	return (NULL);
}

void		*realloc(void *ptr, size_t size)
{
	void *addr;

	if (!ptr || !size)
		return (!ptr ? malloc(size) : NULL);
	addr = init_zone()->tiny;
	if (addr < ptr && ptr < (addr + TINY_ZONE))
		return (realloc_alloc(addr, ptr, size));
	addr = init_zone()->small;
	if (addr < ptr && ptr < (addr + SMALL_ZONE))
		return (realloc_alloc(addr, ptr, size));
	return (realloc_alloc(init_zone()->large, ptr, size));
}
