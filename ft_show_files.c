/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscariot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 08:41:44 by lscariot          #+#    #+#             */
/*   Updated: 2016/02/11 06:50:37 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_putspace(int s, char *str)
{
	int len;

	len = (s - ft_strlen(str)) + 1;
	ft_putnchar(' ', len);
	ft_putstr(str);
}

void	ft_show_l(t_files *files, t_lenmax max)
{
	ft_putstr(files->modes);
	ft_putspace(max.links, files->links);
	ft_putspace(max.user, files->user);
	ft_putspace(max.group, files->group);
	ft_putspace(max.size, files->size);
	ft_putspace(max.date, files->date);
	ft_putstr(" ");
}

void	ft_show_files(t_files *files, t_args args, t_lenmax max)
{
	t_files	*tmp;

	if (args.fns > 1)
	{
		if (args.i >= 1)
			ft_putchar('\n');
		ft_putstr(args.link[args.i]);
		ft_putendl(":");
	}
	if (args.l)
		ft_count_total(files);
	while (files != NULL)
	{
		if (args.l)
			ft_show_l(files, max);
		ft_putendl(files->name);
		tmp = files;
		files = files->next;
	}
}

void	ft_show_recursive(char *fl, t_files *files, t_args args, t_lenmax max)
{
	t_files		*tmp;
	static int	i;

	if (!i)
		i = 0;
	if (i > 0)
	{
		ft_putchar('\n');
		ft_putstr(fl);
		ft_putendl(":");
	}
	while (files != NULL)
	{
		if (args.l)
			ft_show_l(files, max);
		ft_putendl(files->name);
		tmp = files;
		files = files->next;
	}
	i++;
}
