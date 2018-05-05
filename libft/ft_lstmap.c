/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoptere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 17:17:00 by asoptere          #+#    #+#             */
/*   Updated: 2018/01/24 11:31:14 by asoptere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*lista;
	t_list	*nod;
	t_list	*precedent;

	if (!(lista = (t_list*)malloc(sizeof(t_list))))
		return (0);
	lista = (*f)(lst);
	precedent = lista;
	lst = lst->next;
	while (lst)
	{
		if (!(nod = (t_list*)malloc(sizeof(t_list))))
			return (0);
		nod = (*f)(lst);
		precedent->next = nod;
		precedent = nod;
		lst = lst->next;
	}
	return (lista);
}
