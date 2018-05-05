/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max_arr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoptere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/23 17:04:54 by asoptere          #+#    #+#             */
/*   Updated: 2018/01/23 17:04:55 by asoptere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_max_arr(int *arr, size_t size)
{
	int		max;
	size_t	i;

	i = 0;
	max = arr[0];
	while (i < size)
	{
		if (arr[i] > max)
			max = arr[i];
		i++;
	}
	return (max);
}
