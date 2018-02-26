/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 22:17:55 by aridolfi          #+#    #+#             */
/*   Updated: 2016/12/14 10:57:08 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_fd		*new_elem(const int fd, char *buff, t_fd **lfd)
{
	t_fd			*new;

	if (!(new = (t_fd *)malloc(sizeof(t_fd))))
		return (NULL);
	new->fd = fd;
	new->buff = ft_strdup(buff);
	if (!(new->buff))
		return (NULL);
	new->next = *lfd;
	*lfd = new;
	return (new);
}

static t_fd		*fd_tracker(const int fd, t_fd *lfd)
{
	while (lfd)
	{
		if (lfd->fd == fd)
			return (lfd);
		lfd = lfd->next;
	}
	return (NULL);
}

static int		check_elem(const int fd, char *buff, t_fd **lfd)
{
	t_fd			*elem;
	char			*tmp;

	elem = fd_tracker(fd, *lfd);
	if (!elem)
	{
		if (!(elem = new_elem(fd, buff, lfd)))
			return (ERROR);
	}
	else
	{
		if (!(tmp = ft_strjoin(elem->buff, buff)))
			return (ERROR);
		free(elem->buff);
		elem->buff = tmp;
	}
	if (ft_strfind(elem->buff, '\n') != ERROR)
		return (1);
	return (0);
}

static char		*line_tracker(const int fd, t_fd *lfd)
{
	t_fd			*elem;
	char			*tmp;
	char			*get;
	int				ret;

	get = NULL;
	if (!(elem = fd_tracker(fd, lfd)) || !elem->buff)
		return (NULL);
	if ((ret = ft_strfind(elem->buff, '\n')) != ERROR)
	{
		if (!(get = ft_strsub(elem->buff, 0, ret)))
			return (NULL);
		if (!(tmp = ft_strdup(elem->buff + ret + 1)))
			return (NULL);
		free(elem->buff);
		elem->buff = tmp;
	}
	else
	{
		if (ft_strlen(elem->buff) != 0 && !(get = ft_strdup(elem->buff)))
			return (NULL);
		free(elem->buff);
		elem->buff = NULL;
	}
	return (get);
}

int				get_next_line(const int fd, char **line)
{
	static t_fd	*lfd;
	char		buff[BUFF_SIZE + 1];
	int			ret;
	int			back;

	if (fd < 0 || line == NULL)
		return (ERROR);
	while ((ret = read(fd, buff, BUFF_SIZE)) != 0)
	{
		if (ret < 0)
			return (ERROR);
		buff[ret] = '\0';
		if ((back = check_elem(fd, buff, &lfd)) == 1)
		{
			*line = line_tracker(fd, lfd);
			return (1);
		}
		if (back == ERROR)
			return (ERROR);
	}
	if ((*line = line_tracker(fd, lfd)) != NULL)
		return (1);
	return (0);
}
