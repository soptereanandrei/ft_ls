/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoptere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 11:53:35 by asoptere          #+#    #+#             */
/*   Updated: 2018/01/24 11:54:44 by asoptere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nbrlen(int nbr)
{
	int len;

	if (nbr == 0)
		return (1);
	len = 0;
	while (nbr != 0)
	{
		len++;
		nbr /= 10;
	}
	return (len);
}

char		*ft_itoa(int n)
{
	char	*s;
	int		i;
	short	neg;

	neg = 0;
	i = ft_nbrlen(n);
	if (n < 0)
		neg = 1;
	if (!(s = (char*)malloc(i + neg + 1)))
		return (0);
	*(s + i + neg) = '\0';
	if (neg)
		*s = '-';
	i += neg;
	while (--i >= neg)
	{
		if (n >= 0)
			*(s + i) = n % 10 + '0';
		else
			*(s + i) = -(n % 10) + '0';
		n /= 10;
	}
	return (s);
}
