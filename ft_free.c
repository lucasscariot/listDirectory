/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscariot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 16:40:02 by lscariot          #+#    #+#             */
/*   Updated: 2016/02/27 11:16:10 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>

void	ft_free_one(t_files *files, int l)
{
	free(files->name);
	if (l)
	{
		free(files->time);
		free(files->modes);
		free(files->links);
		free(files->user);
		free(files->group);
		free(files->size);
		free(files->month);
		free(files->number);
		free(files->hour);
	}
}

void	ft_free_args(t_args *args)
{
	int i;

	i = 0;
	while (args->fns > i)
	{
		free(args->link[i++]);
	}
	free(args->link);
}

void	ft_free_list(t_files *files, t_args args)
{
	t_files		*next;

	while (files != NULL)
	{
		next = files->next;
		ft_free_one(files, args.l);
		free(files);
		files = next;
	}
}

void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}
