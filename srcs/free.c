/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 12:29:30 by aridolfi          #+#    #+#             */
/*   Updated: 2018/04/17 15:05:46 by aridolfi         ###   ########.fr       */
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
	if (!ptr)
		return ;
	if (init_zone()->tiny < ptr && ptr < (init_zone()->tiny + TINY_ZONE))
		free_alloc(init_zone()->tiny, ptr);
	else if (init_zone()->small < ptr && ptr < (init_zone()->small + SMALL_ZONE))
		free_alloc(init_zone()->small, ptr);
	else
		free_alloc(init_zone()->large, ptr);
}
