/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   realloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 12:30:44 by aridolfi          #+#    #+#             */
/*   Updated: 2018/04/20 16:21:41 by aridolfi         ###   ########.fr       */
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
			pthread_mutex_unlock(&g_lock);
			if (!(ptr = malloc(size)))
			{
				pthread_mutex_lock(&g_lock);
				return (NULL);
			}
			pthread_mutex_lock(&g_lock);
			if ((long)size > (char*)list->next->end - (char *)list->next)
				size = (char *)list->next->end - (char *)list->next;
			ft_memcpy(ptr, list->next + 1, size);
			pthread_mutex_unlock(&g_lock);
			free(list->next);
			pthread_mutex_lock(&g_lock);
			return (ptr);
		}
		list = list->next;
	}
	return (NULL);
}

void		*realloc(void *ptr, size_t size)
{
	void	*addr;
	void	*new;

	if (!ptr || !size)
		return (!ptr ? malloc(size) : NULL);
	pthread_mutex_lock(&g_lock);
	addr = init_zone()->tiny;
	if (addr < ptr && ptr < (addr + TINY_ZONE))
	{
		new = realloc_alloc(addr, ptr, size);
		pthread_mutex_unlock(&g_lock);
		return (new);
	}
	addr = init_zone()->small;
	if (addr < ptr && ptr < (addr + SMALL_ZONE))
	{
		new = realloc_alloc(addr, ptr, size);
		pthread_mutex_unlock(&g_lock);
		return (new);
	}
	new = realloc_alloc(init_zone()->large, ptr, size);
	return (new);
}
