/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tri.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscariot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 17:21:32 by lscariot          #+#    #+#             */
/*   Updated: 2016/02/27 12:13:50 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_tri(t_files *files, t_args args)
{
	ft_tri_files(files, args);
	if (args.t)
		ft_tri_time(files, args);
}

void	ft_tri_links(t_args *ar)
{
	int	fail;
	int	i;

	i = -1;
	fail = 1;
	while (fail > 0)
	{
		fail = 0;
		while (ar->fns > ++i + 1)
		{
			if (ar->r && ft_strcmp(ar->link[i], ar->link[i + 1]) < 0)
			{
				ft_strswap(&ar->link[i], &ar->link[i + 1]);
				fail = 1;
			}
			else if (!ar->r && ft_strcmp(ar->link[i], ar->link[i + 1]) > 0)
			{
				ft_strswap(&ar->link[i], &ar->link[i + 1]);
				fail = 1;
			}
		}
		if (fail == 1)
			i = 0;
	}
	ft_error_tri(ar);
}

void	ft_tri_time(t_files *files, t_args args)
{
	t_files *base;
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
			if (args.r
				&& (ft_rtp(args.link[args.i], files->time, files->next->time)))
				ft_swap_list(files, files->next, args.l, &fail);
			else if (!args.r
				&& (ft_tcp(args.link[args.i], files->time, files->next->time)))
				ft_swap_list(files, files->next, args.l, &fail);
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
				ft_swap_list(files, files->next, args.l, &fail);
			else if (!args.r && ft_strcmp(files->name, files->next->name) > 0)
				ft_swap_list(files, files->next, args.l, &fail);
			files = files->next;
		}
		if (fail == 1)
			files = base;
	}
}
