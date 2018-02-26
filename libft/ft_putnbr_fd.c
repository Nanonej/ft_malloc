/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 22:05:38 by aridolfi          #+#    #+#             */
/*   Updated: 2017/01/10 15:17:45 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	int		dc;
	char	*tmp;

	i = 1;
	if (n == 0 || n == -2147483648)
	{
		(n == 0 ? ft_putstr_fd("0", fd) : ft_putstr_fd("-2147483648", fd));
		return ;
	}
	dc = ft_digitcount(n);
	if (!(tmp = ft_strnew(dc)))
		return ;
	if (n < 0)
	{
		n = -n;
		tmp[0] = '-';
	}
	while (n)
	{
		tmp[dc - i++] = (n % 10 + 48);
		n /= 10;
	}
	ft_putstr_fd(tmp, fd);
	free(tmp);
}
