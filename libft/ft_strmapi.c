/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoptere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 13:54:57 by asoptere          #+#    #+#             */
/*   Updated: 2018/01/28 15:47:52 by asoptere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		size;
	char	*ptr;

	if (s && f)
	{
		size = ft_strlen(s);
		if (!(ptr = (char*)malloc(size + 1)))
			return (0);
		i = 0;
		while (i < size)
		{
			*(ptr + i) = f(i, *(s + i));
			i++;
		}
		*(ptr + i) = '\0';
		return (ptr);
	}
	return (0);
}
