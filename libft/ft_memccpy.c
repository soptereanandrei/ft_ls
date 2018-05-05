/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoptere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 11:56:30 by asoptere          #+#    #+#             */
/*   Updated: 2018/01/24 19:42:49 by asoptere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*((unsigned char*)(src + i)) == (unsigned char)c)
		{
			*((unsigned char*)(dst + i)) = *((unsigned char*)(src + i));
			return ((unsigned char*)dst + i + 1);
		}
		*((unsigned char*)(dst + i)) = *((unsigned char*)(src + i));
		i++;
	}
	return (NULL);
}
