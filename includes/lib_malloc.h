/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_malloc.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/21 12:06:56 by aridolfi          #+#    #+#             */
/*   Updated: 2018/04/16 17:42:18 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_MALLOC_H
# define LIB_MALLOC_H

# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <sys/mman.h>

# define TINY_RES 16
# define TINY_MAX getpagesize() / 4
# define TINY_ZONE 100 * TINY_MAX

# define SMALL_RES 512
# define SMALL_MAX getpagesize() * 4096
# define SMALL_ZONE 100 * SMALL_MAX

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

// void	show_alloc_mem();

#endif