/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_n.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 17:31:24 by aridolfi          #+#    #+#             */
/*   Updated: 2017/03/31 14:41:07 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_conv_d(t_form *f)
{
	intmax_t	nb;

	nb = ft_conv_intmax(f);
	if (nb == 0 && f->prec == 0)
		check_alloc((f->arg = ft_strnew(0)));
	else
	{
		f->sign = (nb >= 0 ? f->sign : 1);
		nb = (nb >= 0 ? nb : -nb);
		check_alloc((f->arg = ft_itoa_base(nb, 10, 0)));
	}
	return (ft_strlen(f->arg));
}

int				ft_conv_u(t_form *f)
{
	uintmax_t	nb;

	nb = ft_conv_uintmax(f);
	if (nb == 0 && f->prec == 0)
		check_alloc((f->arg = ft_strnew(0)));
	else
		check_alloc((f->arg = ft_itoa_base(nb, 10, 0)));
	if (f->prec == -1 && f->zero == 1 && !f->minus)
		f->prec = f->len;
	return (ft_strlen(f->arg));
}

intmax_t		ft_conv_intmax(t_form *f)
{
	f->hash = 0;
	if (!f->mod && (f->conv == 'd' || f->conv == 'i'))
		return (va_arg(f->ap, int));
	else if (!f->mod && f->conv == 'D')
		return (va_arg(f->ap, long int));
	else if (f->mod == HH)
		return ((signed char)va_arg(f->ap, int));
	else if (f->mod == H)
		return ((short)va_arg(f->ap, int));
	else if (f->mod == Z)
		return (va_arg(f->ap, size_t));
	else if (f->mod == L)
		return (va_arg(f->ap, long int));
	else if (f->mod == LL)
		return (va_arg(f->ap, long long int));
	return (va_arg(f->ap, intmax_t));
}

uintmax_t		ft_conv_uintmax(t_form *f)
{
	f->sign = 0;
	if (!f->mod && ft_strfind("OU", f->conv) != -1)
		return (va_arg(f->ap, unsigned long int));
	else if (!f->mod && ft_strfind("ouxXb", f->conv) != -1)
		return (va_arg(f->ap, unsigned int));
	else if (f->mod == HH)
		return ((unsigned char)va_arg(f->ap, unsigned int));
	else if (f->mod == H && f->conv != 'U')
		return ((unsigned short)va_arg(f->ap, unsigned int));
	else if (f->mod == Z)
		return (va_arg(f->ap, size_t));
	else if (f->mod == L)
		return (va_arg(f->ap, unsigned long int));
	else if (f->mod == LL)
		return (va_arg(f->ap, unsigned long long int));
	return (va_arg(f->ap, uintmax_t));
}
