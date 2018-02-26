/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 23:42:33 by aridolfi          #+#    #+#             */
/*   Updated: 2016/11/11 23:48:04 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memswap(void *a, void *b)
{
	unsigned char tmp;

	tmp = *(unsigned char*)a;
	*(unsigned char*)a = *(unsigned char*)b;
	*(unsigned char*)b = tmp;
}
