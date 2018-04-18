/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 12:30:44 by aridolfi          #+#    #+#             */
/*   Updated: 2018/04/18 12:42:26 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_malloc.h"

static int	resize_zone(t_map *start, t_map *list, size_t size, size_t zone_max)
{
	if (((char *)list + size <= (char *)list->end) || \
		(list->next == NULL && \
			((char *)list + size) <= (char *)start + zone_max) || \
		(list->next != NULL && \
			(char *)list + size <= (char *)list->next))
	{
		list->end = (t_map *)((char *)list + size);
		return (1);
	}
	return (0);
}

static void	*realloc_zone(t_map *start, void *ptr, size_t size, size_t zone_max)
{
	t_map	*list;

	list = start;
	while (list->next)
	{
		if (ptr == (list->next + 1))
		{
			if (resize_zone(start, list->next, size, zone_max))
				return (ptr);
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

static void	*realloc_large(t_map *start, void *ptr, size_t size)
{
	t_map	*list;

	list = start;
	while (list->next)
	{
		if (ptr == (list->next + 1))
		{
			if (!(ptr = malloc(size)))
				return (NULL);
			if ((long)size > (char *)list->next->end - (char *)list->next)
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
		return (NULL);
	addr = init_zone()->tiny;
	if (addr < ptr && ptr < (addr + TINY_ZONE))
		return (realloc_zone(addr, ptr, size, TINY_ZONE));
	addr = init_zone()->small;
	if (addr < ptr && ptr < (addr + SMALL_ZONE))
		return (realloc_zone(addr, ptr, size, SMALL_ZONE));
	return (realloc_large(init_zone()->large, ptr, size));
}
