/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoptere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 11:57:24 by asoptere          #+#    #+#             */
/*   Updated: 2018/01/24 11:58:51 by asoptere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*sir1;
	unsigned char	*sir2;

	if (n == 0)
		return (0);
	sir1 = (unsigned char*)s1;
	sir2 = (unsigned char*)s2;
	i = 0;
	while (i < n)
	{
		if (*(sir1 + i) != *(sir2 + i))
			return (*(sir1 + i) - *(sir2 + i));
		i++;
	}
	i--;
	return (*(sir1 + i) - *(sir2 + i));
}
