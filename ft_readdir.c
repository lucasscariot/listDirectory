/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readdir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscariot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 05:02:06 by lscariot          #+#    #+#             */
/*   Updated: 2016/02/24 19:02:12 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ft_recursive(char *filename, t_args args)
{
	t_files		*files;
	t_files		*next;
	int			i;
	char		*chemin;
	char		*tmp;

	files = NULL;
	tmp = NULL;
	files = ft_readdirr(filename, args);
	ft_tri(files, args);
	ft_show_files(filename, files, args);
	chemin = ft_strjoin(args.link[args.i], "/");
	tmp = ft_strjoin(filename, "/");
	free(chemin);
	next = files;
	args.rec++;
	while (files != NULL)
	{
		chemin = ft_strjoin(tmp, files->name);
		if ((i = ft_isdir(chemin))
				&& ft_strcmp(".", files->name)
				&& ft_strcmp("..", files->name))
			ft_recursive(chemin, args);
		free(chemin);
		files = files->next;
	}
	free(tmp);
	ft_free_list(next, args);
	return (0);
}

t_files		*ft_readdirr(char *filename, t_args args)
{
	DIR				*folder;
	struct dirent	*file;
	t_files			*files;
	char			*tmp;
	char			*tmp2;

	files = NULL;
	folder = opendir(filename);
	if (ft_check_errors(filename, args))
		return (NULL);
	while (((file = readdir(folder)) != NULL))
	{
		tmp = ft_strjoin(filename, "/");
		tmp2 = ft_strjoin(tmp, file->d_name);
		if (file->d_name[0] != '.' || args.a)
		{
			if (args.l == 1)
				files = ft_list_big_bot(files, tmp2, file->d_name);
			else
				files = ft_list_simple_bot(files, file->d_name);
		}
		free(tmp);
		free(tmp2);
	}
	free(file);
	closedir(folder);
	return (files);
}
