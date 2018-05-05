/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoptere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 19:45:16 by asoptere          #+#    #+#             */
/*   Updated: 2018/02/15 19:45:18 by asoptere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_elem	*sort_elem(t_elem *list, t_opt arg)
{
	t_elem	*new;

	if (!list)
		return (NULL);
	new = list;
	if (arg.f == 0)
	{
		sort(&new, cmp_alpha);
		(arg.t == 1 || arg.u == 1) ? sort(&new, cmp_time) : NULL;
		arg.r == 1 ? reversesort(&new) : NULL;
	}
	return (new);
}

void	elem_cpy(t_elem **src, t_elem *cpy)
{
	(*src)->name = cpy->name;
	(*src)->path = cpy->path;
	(*src)->date = cpy->date;
	(*src)->st_mode = cpy->st_mode;
	(*src)->st_nlink = cpy->st_nlink;
	(*src)->st_uid = cpy->st_uid;
	(*src)->st_gid = cpy->st_gid;
	(*src)->st_size = cpy->st_size;
	(*src)->st_blocks = cpy->st_blocks;
}

void	swap_elem(t_elem **a, t_elem **b)
{
	t_elem	tmp;

	tmp = **a;
	elem_cpy(a, *b);
	elem_cpy(b, &tmp);
}

void	sort(t_elem **list, int (*cmp)(t_elem *elem1, t_elem *elem2))
{
	t_elem	*a;
	t_elem	*b;

	a = *list;
	while (a)
	{
		b = a->next;
		while (b)
		{
			if (cmp(a, b) > 0)
				swap_elem(&a, &b);
			b = b->next;
		}
		a = a->next;
	}
}

void	reversesort(t_elem **list)
{
	t_elem	*p;
	t_elem	*q;
	t_elem	*r;

	p = *list;
	q = NULL;
	while (p)
	{
		r = q;
		q = p;
		p = p->next;
		q->next = r;
	}
	*list = q;
}
