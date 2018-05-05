/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoptere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 17:05:59 by asoptere          #+#    #+#             */
/*   Updated: 2018/01/24 18:43:15 by asoptere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*nod;

	if (lst)
	{
		nod = lst;
		while (nod)
		{
			(*f)(nod);
			nod = nod->next;
		}
	}
}
