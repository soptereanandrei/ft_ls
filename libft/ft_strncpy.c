/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoptere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 14:12:22 by asoptere          #+#    #+#             */
/*   Updated: 2018/01/24 18:47:35 by asoptere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t i;

	i = 0;
	while (*(src + i++) && i - 1 < len)
		*(dst + i - 1) = *(src + i - 1);
	i--;
	while (i++ < len)
		*(dst + i - 1) = '\0';
	return (dst);
}
