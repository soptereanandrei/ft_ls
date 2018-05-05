/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoptere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 13:24:11 by asoptere          #+#    #+#             */
/*   Updated: 2018/01/24 19:00:36 by asoptere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (*(s1 + i) && *(s2 + i))
	{
		if (*(s1 + i) != *(s2 + i))
			return (*((unsigned char*)(s1 + i)) - *((unsigned char*)(s2 + i)));
		i++;
	}
	return (*((unsigned char*)(s1 + i)) - *((unsigned char*)(s2 + i)));
}
