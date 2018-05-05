/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoptere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:15:20 by asoptere          #+#    #+#             */
/*   Updated: 2018/01/24 16:54:15 by asoptere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (*(big + i) && i < len)
	{
		j = 0;
		while (*(big + i + j) == *(little + j) && *(little + j) && i + j < len)
			j++;
		if (!*(little + j))
			return ((char*)(big + i));
		i++;
	}
	return (NULL);
}
