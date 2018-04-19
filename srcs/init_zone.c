/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_zone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 13:58:55 by aridolfi          #+#    #+#             */
/*   Updated: 2018/04/19 16:44:28 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_malloc.h"

t_data *g_zone = NULL;

t_data	*init_zone(void)
{
	if (g_zone)
		return (g_zone);
	g_zone = mmap(NULL, sizeof(t_data) + TINY_ZONE + SMALL_ZONE, \
				PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
	g_zone->large = (t_map *)(g_zone + 1);
	g_zone->large->next = NULL;
	g_zone->tiny = (t_map *)(g_zone->large + 1);
	g_zone->tiny->end = g_zone->tiny + 1;
	g_zone->tiny->next = NULL;
	g_zone->small = (t_map *)((char *)g_zone->tiny + TINY_ZONE);
	g_zone->small->end = g_zone->small + 1;
	g_zone->small->next = NULL;
	g_zone->large->end = (t_map *)((char *)g_zone->small + SMALL_ZONE);
	return (g_zone);
}
