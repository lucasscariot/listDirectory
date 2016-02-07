/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_files.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscariot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 08:41:44 by lscariot          #+#    #+#             */
/*   Updated: 2016/02/07 15:57:49 by lscariot         ###   ########.fr       */
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

void	ft_show_l(t_files *files)
{
	ft_putstr(files->modes);
	ft_putspace(3, files->links);
	ft_putspace(8, files->user);
	ft_putspace(11, files->group);
	ft_putspace(7, files->size);
	ft_putspace(12, files->date);
	ft_putstr(" ");
}

void	ft_show_files(t_files *files, t_args args)
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
			ft_show_l(files);
		ft_putendl(files->name);
		tmp = files;
		files = files->next;
	}
}

void	ft_show_recursive(char *filename, t_files *files, t_args args)
{
	t_files		*tmp;
	static int	i;

	if (!i)
		i = 0;
	if (i > 0)
	{
		ft_putchar('\n');
		ft_putstr(filename);
		ft_putendl(":");
	}
	while (files != NULL)
	{
		if (args.l)
			ft_show_l(files);
		ft_putendl(files->name);
		tmp = files;
		files = files->next;
	}
	i++;
}
