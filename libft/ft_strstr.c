/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoptere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:33:16 by asoptere          #+#    #+#             */
/*   Updated: 2018/01/24 16:53:31 by asoptere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	len;
	size_t	i;
	size_t	j;

	len = 0;
	while (*(little + len))
		len++;
	if (len == 0)
		return ((char*)(big));
	i = 0;
	while (big[i])
	{
		j = 0;
		if (big[i] == little[0])
		{
			while (big[i + j] == little[j] && big[i + j])
				j++;
			if (j == len)
				return ((char*)(big + i));
		}
		i++;
	}
	return (NULL);
}
