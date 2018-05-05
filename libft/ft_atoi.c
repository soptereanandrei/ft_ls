/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoptere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/24 11:41:34 by asoptere          #+#    #+#             */
/*   Updated: 2018/01/28 17:17:34 by asoptere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	verif(char c, int start)
{
	return ((c >= '0' && c <= '9')
			|| (!start && (c == ' ' || c == '-' || c == '+'
					|| c == '\n' || c == '\t' || c == '\f'
					|| c == '\v' || c == '\r')));
}

static int	semnul(char c)
{
	if (c == '+')
		return (1);
	else
		return (-1);
}

int			ft_atoi(const char *str)
{
	int		nr;
	size_t	i;
	short	start;
	short	semn;

	i = 0;
	start = 0;
	nr = 0;
	semn = 1;
	if (str)
		while (verif(*(str + i), start))
		{
			if (*(str + i) == '-' || *(str + i) == '+')
			{
				semn = semnul(*(str + i));
				start = 1;
			}
			else if (*(str + i) >= '0' && *(str + i) <= '9')
			{
				nr = nr * 10 + *(str + i) - '0';
				start = 1;
			}
			i++;
		}
	return (nr * semn);
}
