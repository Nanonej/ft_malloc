/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 22:23:14 by aridolfi          #+#    #+#             */
/*   Updated: 2016/11/11 22:36:25 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *lst;

	if ((lst = (t_list*)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	if (content == NULL)
	{
		lst->content = NULL;
		lst->content_size = 0;
		lst->next = NULL;
		return (lst);
	}
	if ((lst->content = malloc(content_size)) == NULL)
		return (NULL);
	ft_memcpy(lst->content, content, content_size);
	lst->content_size = content_size;
	return (lst);
}
