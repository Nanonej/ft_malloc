/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 12:29:30 by aridolfi          #+#    #+#             */
/*   Updated: 2018/04/20 16:10:30 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_malloc.h"

static void	free_alloc(t_map *start, void *ptr)
{
	t_map *list;

	list = start;
	while (list->next)
	{
		if (ptr == (list->next + 1))
		{
			list->next = list->next->next;
			return ;
		}
		list = list->next;
	}
}

static void	free_large(void *ptr)
{
	t_map *list;
	t_map *tmp;

	list = init_zone()->large;
	while (list->next)
	{
		if (ptr == (list->next + 1))
		{
			tmp = list->next->next;
			munmap(list->next, (char *)list->next->end - (char *)list->next);
			list->next = tmp;
			return ;
		}
		list = list->next;
	}
}

void		free(void *ptr)
{
	void *addr;

	pthread_mutex_lock(&g_lock);
	if (!ptr)
	{
		pthread_mutex_unlock(&g_lock);
		return ;
	}
	addr = init_zone()->tiny;
	if (addr < ptr && ptr < (addr + TINY_ZONE))
	{
		free_alloc(addr, ptr);
		pthread_mutex_unlock(&g_lock);
		return ;
	}
	addr = init_zone()->small;
	if (addr < ptr && ptr < (addr + SMALL_ZONE))
	{
		free_alloc(addr, ptr);
		pthread_mutex_unlock(&g_lock);
		return ;
	}
	free_large(ptr);
	pthread_mutex_unlock(&g_lock);
}
