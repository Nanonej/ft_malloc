/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 10:38:24 by aridolfi          #+#    #+#             */
/*   Updated: 2017/01/19 11:36:55 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <wchar.h>
# include <stdint.h>

typedef enum	e_mod
{
	H = 1,
	L,
	UL,
	J,
	Z,
	HH,
	LL,
}				t_mod;

typedef struct	s_form
{
	char		buff[4096];
	char		*arg;
	int			szbuff;
	int			szarg;
	va_list		ap;
	int			(*p[19])(struct s_form *form);
	char		minus;
	char		sign;
	char		zero;
	char		hash;
	int			len;
	int			prec;
	int			mod;
	char		conv;
}				t_form;

typedef int		(*t_array)(t_form *form);

int				ft_printf(const char *format, ...);

void			init_opt(t_form *f);
void			init_clear(t_form **f);
t_form			*init_form(t_form *f);

int				fill_opt(t_form *f, char **format);

int				ft_conv_c(t_form *form);
int				ft_conv_s(t_form *f);
int				ft_conv_pct(t_form *f);
int				ft_conv_d(t_form *f);
int				ft_conv_u(t_form *f);
int				ft_conv_o(t_form *f);
int				ft_conv_x(t_form *f);
int				ft_conv_b(t_form *f);

void			check_alloc(void *ptr);
int				check_conv(char c);
void			check_conv_mod(t_form *form, char *mod);
int				check_wchar(wchar_t c);
void			check_before_format(t_form *f);

void			format_prec(t_form *form);

intmax_t		ft_conv_intmax(t_form *f);
uintmax_t		ft_conv_uintmax(t_form *f);

#endif
