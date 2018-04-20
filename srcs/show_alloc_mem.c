/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_alloc_mem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 12:43:34 by aridolfi          #+#    #+#             */
/*   Updated: 2018/04/20 15:32:53 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_malloc.h"

static void	print_hex(long hex, int prefix)
{
	int	i;

	if (prefix)
		write(1, "0x", 2);
	if (hex >= 16)
		print_hex(hex / 16, 0);
	i = hex % 16;
	if (i >= 10)
		ft_putchar(i - 10 + 'a');
	else
		ft_putchar(i + '0');
}

static int	print_addresses(t_map *list)
{
	size_t	bytes;
	size_t	total;

	total = 0;
	while (list->next && (list = list->next))
	{
		print_hex((long)list + 1, 1);
		write(1, " - ", 3);
		print_hex((long)list->end, 1);
		bytes = (char *)list->end - (char *)list - sizeof(t_map);
		write(1, " : ", 3);
		ft_putnbr(bytes);
		write(1, " octets\n", 8);
		total += bytes;
	}
	return (total);
}

void		show_alloc_mem(void)
{
	t_map	*list;
	size_t	total;

	pthread_mutex_lock(&g_lock);
	total = 0;
	list = init_zone()->tiny;
	write(1, "TINY : ", 7);
	print_hex((long)list, 1);
	write(1, "\n", 1);
	total += print_addresses(list);
	list = init_zone()->small;
	write(1, "SMALL : ", 8);
	print_hex((long)list, 1);
	write(1, "\n", 1);
	total += print_addresses(list);
	list = init_zone()->large;
	write(1, "LARGE : ", 8);
	print_hex((long)list, 1);
	write(1, "\n", 1);
	total += print_addresses(list);
	write(1, "Total : ", 8);
	ft_putnbr(total);
	write(1, " octets\n", 8);
	pthread_mutex_unlock(&g_lock);
}
