/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoptere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 12:00:09 by asoptere          #+#    #+#             */
/*   Updated: 2018/01/28 13:39:12 by asoptere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*mem;

	if (!(mem = (char*)malloc(len)))
		return (0);
	i = 0;
	while (i < len)
	{
		*(mem + i) = *((char*)(src + i));
		i++;
	}
	i = 0;
	while (i < len)
	{
		*((char*)(dst + i)) = *(mem + i);
		i++;
	}
	free(mem);
	return (dst);
}
