/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 18:56:19 by aridolfi          #+#    #+#             */
/*   Updated: 2017/02/12 18:41:38 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*new;
	size_t	i;
	size_t	k;

	i = 0;
	k = 1;
	if (n == 0 || n == -2147483648)
		return (n == 0 ? ft_strdup("0") : ft_strdup("-2147483648"));
	new = ft_strnew(ft_digitcount(n));
	if (n < 0)
	{
		n = -n;
		new[i++] = '-';
	}
	while (n / k)
		k *= 10;
	k /= 10;
	while (k > 0)
	{
		new[i++] = (n / k % 10 + 48);
		k /= 10;
	}
	new[i] = '\0';
	return (new);
}
