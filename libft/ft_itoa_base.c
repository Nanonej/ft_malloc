/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 18:56:19 by aridolfi          #+#    #+#             */
/*   Updated: 2017/01/17 14:33:01 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_ndigit_to_alloc(uintmax_t n, int base)
{
	int ret;

	ret = 0;
	while (n)
	{
		n /= base;
		ret++;
	}
	return (ret);
}

char			*ft_itoa_base(uintmax_t n, int base, char sign)
{
	char	*new;
	char	tab[16];
	size_t	dc;
	size_t	i;

	if (n == 0)
		return (ft_strdup("0"));
	dc = 0;
	i = 1;
	ft_strcpy(tab, "0123456789abcdef");
	dc = ft_ndigit_to_alloc(n, base) + sign;
	if (!(new = ft_strnew(dc)))
		return (NULL);
	while (n)
	{
		new[dc - i++] = tab[n % base];
		n /= base;
	}
	if (sign)
		new[0] = '-';
	return (new);
}
