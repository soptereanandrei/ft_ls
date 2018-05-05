/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoptere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 11:55:50 by asoptere          #+#    #+#             */
/*   Updated: 2018/01/24 11:56:01 by asoptere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	i;
	char	*ptr;

	if (!(ptr = (char*)malloc(size)))
		return (NULL);
	i = 0;
	while (i < size)
		*(ptr + i++) = 0;
	return (ptr);
}
