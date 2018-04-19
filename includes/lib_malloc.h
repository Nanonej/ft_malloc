/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_malloc.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 12:06:56 by aridolfi          #+#    #+#             */
/*   Updated: 2018/04/19 18:33:31 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_MALLOC_H
# define LIB_MALLOC_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <sys/mman.h>

# define TINY_MAX 2 * getpagesize()
# define TINY_ZONE 128 * TINY_MAX

# define SMALL_MAX 254 * getpagesize()
# define SMALL_ZONE 128 * SMALL_MAX

typedef struct	s_map
{
	struct s_map		*end;
	struct s_map		*next;
}				t_map;

typedef struct	s_data {
	t_map				*tiny;
	t_map				*small;
	t_map				*large;
}				t_data;

void			free(void *ptr);
t_data			*init_zone(void);
void			*malloc(size_t size);
void			*realloc(void *ptr, size_t size);
void			show_alloc_mem(void);

#endif
