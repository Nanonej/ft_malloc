/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/12 00:00:27 by aridolfi          #+#    #+#             */
/*   Updated: 2017/03/31 14:41:10 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		format_len(t_form *f)
{
	char		*tmp;
	int			i;

	if (f->szarg < f->len)
	{
		i = f->len - f->szarg;
		check_alloc((tmp = ft_strnew(i)));
		tmp = (char *)ft_memset(tmp, ' ', i);
		if (!f->minus)
		{
			free_swap(&(f->arg), ft_memcat(tmp, f->arg, i, f->szarg));
			check_alloc(f->arg);
		}
		else
		{
			free_swap(&(f->arg), ft_memcat(f->arg, tmp, f->szarg, i));
			check_alloc(f->arg);
		}
		f->szarg += i;
		free(tmp);
	}
}

static void		format_hash(t_form *f)
{
	char		*tmp;

	if (ft_strfind("oOxX", f->conv) != -1 && f->hash)
	{
		check_alloc((tmp = ft_strnew(f->hash)));
		if (f->conv == 'o' || f->conv == 'O')
			tmp[0] = '0';
		else if (f->conv == 'x' || f->conv == 'X')
			ft_strcpy(tmp, "0x");
		free_swap(&(f->arg), ft_strjoin(tmp, f->arg));
		free(tmp);
		f->szarg += f->hash;
	}
	if (f->conv == 'X')
		ft_strupper(f->arg);
	format_len(f);
}

static void		format_sign_d(t_form *f)
{
	char		*tmp;

	if (ft_strfind("dDi", f->conv) != -1 && f->sign)
	{
		check_alloc((tmp = ft_strnew(1)));
		if (f->sign == 1)
			tmp[0] = '-';
		else if (f->sign == 2)
			tmp[0] = '+';
		else
			tmp[0] = ' ';
		free_swap(&(f->arg), ft_strjoin(tmp, f->arg));
		free(tmp);
		f->szarg += 1;
	}
	format_hash(f);
}

static void		format_prec_str(t_form *f)
{
	char		*tmp;

	if (f->prec != -1 && f->szarg > f->prec)
	{
		check_alloc((tmp = ft_strnew(f->prec)));
		ft_memcpy(tmp, f->arg, f->prec);
		free(f->arg);
		f->arg = tmp;
		f->szarg = f->prec;
	}
}

void			format_prec(t_form *f)
{
	char		*tmp;

	if (f->conv == 's' || f->conv == 'S')
		format_prec_str(f);
	check_before_format(f);
	if (f->prec > f->szarg)
	{
		f->prec -= f->szarg;
		check_alloc((tmp = ft_strnew(f->prec)));
		tmp = (char *)ft_memset(tmp, '0', f->prec);
		free_swap(&(f->arg), ft_memcat(tmp, f->arg, f->prec, f->szarg));
		check_alloc(f->arg);
		f->szarg += f->prec;
		free(tmp);
	}
	format_sign_d(f);
}
