/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 18:29:18 by aridolfi          #+#    #+#             */
/*   Updated: 2017/03/31 14:41:13 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include "ft_printf.h"

void			init_opt(t_form *f)
{
	f->arg = NULL;
	f->szarg = 0;
	f->minus = 0;
	f->sign = 0;
	f->zero = 0;
	f->hash = 0;
	f->len = -1;
	f->prec = -1;
	f->mod = 0;
	f->conv = '\0';
}

void			init_clear(t_form **f)
{
	va_end((*f)->ap);
	if ((*f)->arg)
		free((*f)->arg);
	init_opt(*f);
	free(*f);
	*f = NULL;
}

static void		init_array(t_array *p)
{
	p[0] = ft_conv_s;
	p[1] = ft_conv_s;
	p[2] = ft_conv_x;
	p[3] = ft_conv_d;
	p[4] = ft_conv_d;
	p[5] = ft_conv_d;
	p[6] = ft_conv_o;
	p[7] = ft_conv_o;
	p[8] = ft_conv_u;
	p[9] = ft_conv_u;
	p[10] = ft_conv_x;
	p[11] = ft_conv_x;
	p[12] = ft_conv_c;
	p[13] = ft_conv_c;
	p[14] = ft_conv_b;
	p[15] = ft_conv_b;
	p[18] = ft_conv_pct;
}

t_form			*init_form(t_form *f)
{
	f = (t_form *)malloc(sizeof(t_form));
	check_alloc(f);
	f->szbuff = 0;
	init_array(f->p);
	init_opt(f);
	return (f);
}
