/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tri.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscariot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 17:21:32 by lscariot          #+#    #+#             */
/*   Updated: 2016/02/08 14:28:26 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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
			if (args->r)
			{
				if (ft_strcmp(args->link[i], args->link[i + 1]) < 0)
				{
					ft_strswap(&args->link[i], &args->link[i + 1]);
					fail = 1;
				}
			}
			else if (ft_strcmp(args->link[i], args->link[i + 1]) > 0)
			{
				ft_strswap(&args->link[i], &args->link[i + 1]);
				fail = 1;
			}
			i++;
		}
		if (fail == 1)
			i = 0;
	}
}

void	ft_tri_time(t_files *files, t_args args)
{
	t_files *nfiles;
	t_files *base;
	int     fail;
	int     i;

	if (!files)
		return ;
	base = files;
	nfiles = files->next;
	i = 0;
	fail = 1;
	while (fail > 0)
	{
		fail = 0;
		while (nfiles != NULL)
		{
			if (args.r)
			{
				if (ft_revtimecomp(files->name, nfiles->name))
				{
					fail = 1;
					ft_swap_list(nfiles, files, args.l);
				}
			}
			else if (ft_timecomp(files->name, nfiles->name))
			{
				fail = 1;
				ft_swap_list(files, nfiles, args.l);
			}
			nfiles = nfiles->next;
			files = files->next;
		}
		if (fail == 1)
		{
			nfiles = base->next;
			files = base;
		}
	}
}

void	ft_tri_files(t_files *files, t_args args)
{
	t_files	*nfiles;
	t_files	*base;
	int		fail;
	int		i;

	if (!files)
		return ;
	base = files;
	nfiles = files->next;
	i = 0;
	fail = 1;
	while (fail > 0)
	{
		fail = 0;
		while (nfiles != NULL)
		{
			if (args.r)
			{
				if (ft_strcmp(files->name, nfiles->name) < 0)
				{
					fail = 1;
					ft_swap_list(files, nfiles, args.l);
				}
			}
			else if (ft_strcmp(files->name, nfiles->name) > 0)
			{
				fail = 1;
				ft_swap_list(files, nfiles, args.l);
			}
			nfiles = nfiles->next;
			files = files->next;
		}
		if (fail == 1)
		{
			nfiles = base->next;
			files = base;
		}
	}
}
