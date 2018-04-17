/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 12:25:58 by aridolfi          #+#    #+#             */
/*   Updated: 2018/04/17 11:36:12 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_malloc.h"

void	*alloc_zone(t_map *list, size_t size, size_t zone_max)
{
	t_map *start;
	t_map *swap;

	start = list;
	while (list->next)
	{
		if (((char *)list->next - (char *)list->end) >= (long)size)
			break ;
		list = list->next;
	}
	if ((char *)list->end + size > (char *)start + zone_max)
		return (NULL);
	swap = list->next;
	list->next = list->end;
	list->next->end = (t_map *)((char *)list->next + size);
	list->next->next = swap;
	return (list->next + 1);
}

void	*alloc_large(t_map *list, size_t size)
{
	while (list->next)
		list = list->next;
	list->next = mmap(NULL, size, \
					PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	if (!list->next)
		return (NULL);
	list->next->end = (t_map *)((char *)list->next + size);
	list->next->next = NULL;
	return (list->next + 1);
}

void	*malloc(size_t size)
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
