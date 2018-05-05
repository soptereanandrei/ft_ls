/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoptere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 16:26:26 by asoptere          #+#    #+#             */
/*   Updated: 2018/01/21 16:35:47 by asoptere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*nod1;
	t_list	*nod2;

	if (*alst)
	{
		nod1 = *alst;
		while (nod1)
		{
			nod2 = nod1->next;
			del(nod1->content, nod1->content_size);
			free(nod1);
			nod1 = nod2;
		}
		*alst = 0;
	}
}
