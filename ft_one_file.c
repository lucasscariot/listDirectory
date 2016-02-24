/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_one_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscariot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 12:36:09 by lscariot          #+#    #+#             */
/*   Updated: 2016/02/24 19:00:12 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_show_one(t_files *files, t_args args)
{
	t_files		*tmp;
	t_lenmax	max;

	if (files == NULL)
		return ;
	if (args.l)
		max = ft_maxlen(files);
	while (files != NULL)
	{
		if (args.l)
			ft_show_l(files, max);
		ft_putendl(files->name);
		tmp = files;
		files = files->next;
	}
}

void	ft_one_file(char *filename, t_args args)
{
	t_files *files;

	files = NULL;
	if (args.l)
		files = ft_list_big_bot(files, filename, filename);
	else
		files = ft_list_simple_bot(files, filename);
	ft_show_one(files, args);
	free(files);
}
