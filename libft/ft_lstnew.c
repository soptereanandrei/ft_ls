/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoptere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 15:24:25 by asoptere          #+#    #+#             */
/*   Updated: 2018/01/24 19:10:12 by asoptere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*nod;

	if (!(nod = (t_list*)malloc(sizeof(t_list))))
		return (0);
	if (!content)
	{
		nod->content = 0;
		nod->content_size = 0;
		nod->next = 0;
	}
	else
	{
		nod->content = ft_memalloc(content_size);
		nod->content = ft_memcpy(nod->content, content, content_size);
		nod->content_size = content_size;
		nod->next = 0;
	}
	return (nod);
}
