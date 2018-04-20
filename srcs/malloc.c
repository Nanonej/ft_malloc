/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 12:25:58 by aridolfi          #+#    #+#             */
/*   Updated: 2018/04/20 18:50:05 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_malloc.h"

pthread_mutex_t	g_lock = PTHREAD_MUTEX_INITIALIZER;

static void		*alloc_zone(t_map *start, size_t size, size_t zone_max)
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

static void		*alloc_large(size_t size)
{
	t_map *list;

	list = init_zone()->large;
	while (list->next)
		list = list->next;
	if (!(list->next = mmap(NULL, size, \
					PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0)))
		return (NULL);
	list->next->end = (t_map *)((char *)list->next + size);
	list->next->next = NULL;
	return (list->next + 1);
}

void			*malloc(size_t size)
{
	t_map			*ptr;
	struct rlimit	rlim;

	pthread_mutex_lock(&g_lock);
	ptr = NULL;
	getrlimit(RLIMIT_DATA, &rlim);
	if (!size || (size >= (rlim.rlim_cur - sizeof(t_map))))
	{
		pthread_mutex_unlock(&g_lock);
		return (NULL);
	}
	size += sizeof(t_map);
	if (size <= (size_t)TINY_MAX)
		ptr = alloc_zone(init_zone()->tiny, size, TINY_ZONE);
	else if (size <= (size_t)SMALL_MAX)
		ptr = alloc_zone(init_zone()->small, size, SMALL_ZONE);
	if (!ptr)
		ptr = alloc_large(size);
	pthread_mutex_unlock(&g_lock);
	return (ptr);
}
