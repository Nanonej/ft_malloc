/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 12:25:58 by aridolfi          #+#    #+#             */
/*   Updated: 2018/04/18 12:18:29 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_malloc.h"

static void	*alloc_zone(t_map *start, size_t size, size_t zone_max)
{
	t_map *list;
	t_map *swap;

	list = start;
	while (list->next && ((char *)list->next - (char *)list->end) < (long)size)
		list = list->next;
	if ((char *)list->end + size > (char *)start + zone_max)
		return (NULL);
	swap = list->next;
	list->next = list->end;
	list->next->end = (t_map *)((char *)list->next + size);
	list->next->next = swap;
	return (list->next + 1);
}

static void	*alloc_large(t_map *start, size_t size)
{
	t_map *list;

	list = start;
	while (list)
		list = list->next;
	list = mmap(NULL, size, \
					PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	if (!list)
		return (NULL);
	list->end = (t_map *)((char *)list + size);
	list->next = NULL;
	return (list + 1);
}

void		*malloc(size_t size)
{
	t_map	*ptr;

	ptr = NULL;
	size += sizeof(ptr);
	if (!size)
		return (NULL);
	else if (size <= (size_t)TINY_MAX)
		ptr = alloc_zone(init_zone()->tiny, size, TINY_ZONE);
	else if (size <= (size_t)SMALL_MAX)
		ptr = alloc_zone(init_zone()->small, size, SMALL_ZONE);
	if (!ptr)
		ptr = alloc_large(init_zone()->large, size);
	return (ptr);
}
