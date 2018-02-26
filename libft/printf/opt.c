/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opt.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 19:16:14 by aridolfi          #+#    #+#             */
/*   Updated: 2017/03/31 14:41:17 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		opt_mod(t_form *f, char **format)
{
	char		*tmp;

	tmp = *format;
	f->szarg = 0;
	while (ft_strfind("lhjzL", *tmp) != -1 && ++f->szarg != -1)
		tmp++;
	check_alloc((void *)(tmp = ft_strsub(*format, 0, f->szarg)));
	*format += f->szarg;
	if (ft_strfind("-+0 #123456789.", **format) == -1)
	{
		if (!(check_conv((f->conv = **format))))
		{
			free(tmp);
			return (0);
		}
		if (*tmp)
			check_conv_mod(f, tmp);
	}
	free(tmp);
	(*format)++;
	return (1);
}

static void		opt_prec(t_form *f, char **format)
{
	int			nb;
	int			count;

	(*format)++;
	f->prec = 0;
	if (**format == '*')
	{
		f->prec = va_arg(f->ap, int);
		(*format)++;
	}
	else if (**format >= '0' && **format <= '9')
	{
		count = 1;
		nb = ft_atoi(*format);
		while ((nb /= 10) != 0)
			count++;
		f->prec = ft_atoi(*format);
		*format += count;
	}
}

static void		opt_len(t_form *f, char **format)
{
	int			nb;
	int			count;

	if (**format == '*')
	{
		f->len = va_arg(f->ap, int);
		(*format)++;
	}
	else if (**format >= '0' && **format <= '9')
	{
		count = 1;
		nb = ft_atoi(*format);
		while ((nb /= 10) != 0)
			count++;
		f->len = ft_atoi(*format);
		*format += count;
	}
}

static void		opt_opt(t_form *f, char **format)
{
	while (ft_strfind("-+0 #", **format) != -1)
	{
		if (**format == '-')
			f->minus = 1;
		else if (**format == '+')
			f->sign = 2;
		else if (**format == '0')
			f->zero = 1;
		else if (**format == ' ' && !f->sign)
			f->sign = 3;
		else if (**format == '#')
			f->hash = 1;
		(*format)++;
	}
}

int				fill_opt(t_form *f, char **format)
{
	while (ft_strfind("-+0 #123456789.lhjzL", **format) != -1)
	{
		if (ft_strfind("-+0 #", **format) != -1)
			opt_opt(f, format);
		else if (ft_strfind("123456789", **format) != -1)
			opt_len(f, format);
		else if (**format == '.')
			opt_prec(f, format);
		else
		{
			if (opt_mod(f, format))
				return (1);
		}
	}
	if (!f->conv && check_conv((f->conv = **format)))
	{
		(*format)++;
		return (1);
	}
	return (0);
}
