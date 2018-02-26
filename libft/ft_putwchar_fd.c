/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 17:16:05 by aridolfi          #+#    #+#             */
/*   Updated: 2016/12/19 11:49:47 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putwchar_fd(wchar_t c, int fd)
{
	char s[5];

	ft_strclr(s);
	if (c <= 0x7F)
		write(fd, &c, 1);
	else if (c < 0x7FF)
	{
		s[0] = (c >> 6) + 0xC0;
		s[1] = (c & 0x3F) + 0x80;
	}
	else if (c < 0xFFFF)
	{
		s[0] = (c >> 12) + 0xE0;
		s[1] = ((c >> 6) & 0x3F) + 0x80;
		s[2] = (c & 0x3F) + 0x80;
	}
	else if (c <= 0x10FFFF)
	{
		s[0] = (c >> 18) + 0xF0;
		s[1] = (c >> 12) & 0x3F;
		s[2] = ((c >> 6) & 0x3F) + 0x80;
		s[3] = (c & 0x3F) + 0x80;
	}
	ft_putstr_fd(s, fd);
}
