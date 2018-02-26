/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_tab_bubble.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 23:55:26 by aridolfi          #+#    #+#             */
/*   Updated: 2016/11/11 23:58:12 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_int_tab_bubble(int *tab, size_t n)
{
	int			tmp;
	size_t		i;
	size_t		j;

	i = -1;
	while (++i < n)
	{
		j = i;
		while (++j < n)
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
	}
}
