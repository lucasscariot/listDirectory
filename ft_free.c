/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscariot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 16:40:02 by lscariot          #+#    #+#             */
/*   Updated: 2016/02/08 13:15:12 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>

void	ft_free_one(t_files *files, int l)
{
	free(files->name);
	if (l)
	{
		free(files->modes);
		free(files->links);
		free(files->user);
		free(files->group);
		free(files->size);
		free(files->date);
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
	//ft_putendl("free");
	while (tab[i])
		free(tab[i++]);
	free(tab);
}
