/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 18:30:34 by aridolfi          #+#    #+#             */
/*   Updated: 2017/03/31 14:40:58 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			check_alloc(void *ptr)
{
	if (!ptr)
	{
		ft_putendl("Memory Allocation Failed.");
		exit(EXIT_FAILURE);
	}
}

int				check_conv(char c)
{
	if (ft_strfind("sSpdDioOuUxXcCbBfF%", c) == -1)
		return (0);
	return (1);
}

void			check_conv_mod(t_form *form, char *mod)
{
	if (ft_strlen(mod) == 1)
		form->mod = ft_strfind("ahlLjz", *mod);
	else if (ft_strlen(mod) == 2 && ft_strequ("ll", mod))
		form->mod = LL;
	else if (ft_strlen(mod) == 2 && ft_strequ("hh", mod))
		form->mod = HH;
	else
		form->mod = J;
}

int				check_wchar(wchar_t c)
{
	if (c <= 0x10FFFF)
	{
		if (c <= 0x7F)
			return (1);
		else if (c < 0x7FF)
			return (2);
		else if (c < 0xFFFF)
			return (3);
		else
			return (3);
	}
	return (-1);
}

void			check_before_format(t_form *f)
{
	int			i;

	i = 0;
	if (ft_strfind("dDi", f->conv) != -1 && f->sign)
		i = 1;
	if (ft_strfind("cCsS%", f->conv) != -1)
	{
		f->prec = -1;
		f->hash = 0;
		f->sign = 0;
	}
	else if ((f->conv == 'x' || f->conv == 'X') && !ft_strlen(f->arg))
		f->hash = 0;
	else if ((f->conv == 'x' || f->conv == 'X') && ft_strlen(f->arg) && f->hash)
		f->hash = 2;
	if (!f->minus && f->prec == -1 && f->zero)
		f->prec = f->len - f->hash - i;
}
