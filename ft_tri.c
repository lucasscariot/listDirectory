/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tri.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscariot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 17:21:32 by lscariot          #+#    #+#             */
/*   Updated: 2016/02/23 18:45:52 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_tri(t_files *files, t_args args)
{
	ft_tri_files(files, args);
	if (args.t)
		ft_tri_time(files, args);
}

void	ft_tri_links(t_args *args)
{
	int	fail;
	int	i;

	i = 0;
	fail = 1;
	while (fail > 0)
	{
		fail = 0;
		while (args->fns > i + 1)
		{
			if (args->r && ft_strcmp(args->link[i], args->link[i + 1]) < 0)
			{
				ft_strswap(&args->link[i], &args->link[i + 1]);
				fail = 1;
			}
			else if (!args->r && ft_strcmp(args->link[i], args->link[i + 1]) > 0)
			{
				ft_strswap(&args->link[i], &args->link[i + 1]);
				fail = 1;
			}
			i++;
		}
		if (fail == 1)
			i = 0;
	}
	//ft_error_tri(args);
}

void	ft_tri_time(t_files *files, t_args args)
{
	t_files *base;
	int		fail;
	int		i;
	int		rez;

	if (!files)
		return ;
	base = files;
	i = 0;
	fail = 1;
	rez = 0;
	while (fail > 0)
	{
		fail = 0;
		while (files->next != NULL)
		{
			if (args.r && ft_revtimecomp(files->name, files->next->name))
			{
				fail = 1;
				ft_swap_list(files, files->next, args.l);
			}
			else if (!args.r
					&& (rez = ft_timecomp(files->name, files->next->name)))
			{
				fail = 1;
				ft_swap_list(files, files->next, args.l);
			}
			files = files->next;
		}
		if (fail == 1)
			files = base;
	}
}

void	ft_tri_files(t_files *files, t_args args)
{
	t_files	*base;
	int		fail;
	int		i;

	if (!files)
		return ;
	base = files;
	i = 0;
	fail = 1;
	while (fail > 0)
	{
		fail = 0;
		while (files->next != NULL)
		{
			if (args.r && ft_strcmp(files->name, files->next->name) < 0)
			{
				fail = 1;
				ft_swap_list(files, files->next, args.l);
			}
			else if (!args.r && ft_strcmp(files->name, files->next->name) > 0)
			{
				fail = 1;
				ft_swap_list(files, files->next, args.l);
			}
			files = files->next;
		}
		if (fail == 1)
			files = base;
	}
}
