/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 23:13:11 by aridolfi          #+#    #+#             */
/*   Updated: 2016/11/12 00:10:23 by aridolfi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list*))
{
	t_list	*new;
	t_list	*tmp;
	t_list	*tmp2;

	tmp2 = (*f)(lst);
	if ((new = ft_lstnew(tmp2->content, tmp2->content_size)) == NULL)
		return (NULL);
	tmp = new;
	lst = lst->next;
	while (lst)
	{
		tmp2 = (*f)(lst);
		if ((tmp->next = ft_lstnew(tmp2->content, tmp2->content_size)) == NULL)
			return (NULL);
		tmp = tmp->next;
		lst = lst->next;
	}
	return (new);
}
