/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 12:29:30 by aridolfi          #+#    #+#             */
/*   Updated: 2018/04/17 17:20:15 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_malloc.h"

void	free_alloc(t_map *start, void *ptr)
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

void	free(void *ptr)
{
	void *addr;

	if (!ptr)
		return ;
	addr = init_zone()->tiny;
	if (addr < ptr && ptr < (addr + TINY_ZONE))
		return (free_alloc(addr, ptr));
	addr = init_zone()->small;
	if (addr < ptr && ptr < (addr + SMALL_ZONE))
		return (free_alloc(addr, ptr));
	free_alloc(init_zone()->large, ptr);
}
