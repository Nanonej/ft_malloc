/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 19:31:59 by aridolfi          #+#    #+#             */
/*   Updated: 2016/11/11 16:52:08 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int i;
	int j;
	int sign;

	i = 0;
	j = 0;
	sign = 1;
	while (ft_iswhitespace(str[i]))
		i++;
	if ((str[i] == 45 || str[i] == 43) && (str[i + 1] > 47 && str[i + 1] < 58))
		if (str[i++] == 45)
			sign = -1;
	while (str[i] && ft_isdigit(str[i]))
	{
		j = j + (str[i] - 48);
		if (ft_isdigit(str[i + 1]))
			j = j * 10;
		i++;
	}
	return (sign * j);
}
