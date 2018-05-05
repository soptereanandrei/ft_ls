/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoptere <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/15 19:44:15 by asoptere          #+#    #+#             */
/*   Updated: 2018/02/15 19:44:19 by asoptere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	get_size_errorhandling(t_size *size, t_elem *cur)
{
	if (getpwuid(cur->st_uid))
		size->userspace = (int)ft_strlen(getpwuid(cur->st_uid)->pw_name) \
			> size->userspace ? (int)ft_strlen(getpwuid(cur->st_uid)->pw_name) \
			: size->userspace;
	else
		size->userspace = (int)ft_strlen(ft_itoa(cur->st_uid)) \
			> size->userspace ? (int)ft_strlen(ft_itoa(cur->st_uid)) \
			: size->userspace;
	if (getgrgid(cur->st_gid))
		size->groupspace = (int)ft_strlen(getgrgid(cur->st_gid)->gr_name) \
			> size->groupspace ? \
			(int)ft_strlen(getgrgid(cur->st_gid)->gr_name) : size->groupspace;
	else
		size->groupspace = (int)ft_strlen(ft_itoa(cur->st_gid)) \
			> size->groupspace ? (int)ft_strlen(ft_itoa(cur->st_gid)) \
			: size->groupspace;
}

void	get_size_quick(t_size *size, t_elem *cur)
{
	size->linkspace = (int)ft_strlen(ft_itoa(cur->st_nlink)) > \
		size->linkspace ? (int)ft_strlen(ft_itoa(cur->st_nlink)) \
		: size->linkspace;
	size->maj = (int)ft_strlen(ft_itoa(major(cur->st_rdev))) > size->maj \
		? (int)ft_strlen(ft_itoa(major(cur->st_rdev))) : size->maj;
	size->min = (int)ft_strlen(ft_itoa(minor(cur->st_rdev))) > size->min ? \
		(int)ft_strlen(ft_itoa(minor(cur->st_rdev))) : size->min;
	size->size = (int)ft_strlen(ft_itoa(cur->st_size)) > size->size ? \
		(int)ft_strlen(ft_itoa(cur->st_size)) : size->size;
	size->total += cur->st_blocks;
}

t_size	get_size(t_opt arg, t_elem *files)
{
	t_elem	*cur;
	t_size	size;

	size = (t_size){0, 0, 0, 0, 0, 0, 0};
	cur = files;
	while (cur)
	{
		if (!(arg.a == 0 && cur->name[0] == '.'))
		{
			get_size_quick(&size, cur);
			get_size_errorhandling(&size, cur);
		}
		cur = cur->next;
	}
	return (size);
}

void	do_recursion(t_opt arg, char *path)
{
	t_elem	*files;
	DIR		*dir;

	files = NULL;
	ft_putchar('\n');
	ft_putstr(path);
	ft_putstr(":\n");
	if ((dir = opendir(path)) != NULL)
	{
		while (elemget(&files, readdir(dir), \
					ft_strjoin(path, "/"), arg) != 0)
			;
		closedir(dir);
		if (files)
			display_file(arg, files, 1);
		files = NULL;
	}
	else
		basicerror("ft_ls: ", path, 0);
}

void	recursion(t_opt arg, t_elem *files)
{
	t_elem	*cur;

	cur = files;
	while (cur)
	{
		if (cur->name && cur->path && \
				S_ISDIR(cur->st_mode) && \
				ft_strcmp(".", cur->name) && \
				ft_strcmp("..", cur->name) && \
				!(arg.a == 0 && cur->name[0] == '.'))
			do_recursion(arg, cur->path);
		cur = cur->next;
	}
}
