/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readdir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscariot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 05:02:06 by lscariot          #+#    #+#             */
/*   Updated: 2016/02/26 13:51:31 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_recursive(char *filename, t_args args, int *err)
{
	t_files		*files;
	t_files		*next;
	char		*chemin;
	char		*tmp;

	files = NULL;
	tmp = NULL;
	files = ft_readdirr(filename, args, err);
	ft_tri(files, args);
	ft_show_files(filename, files, args, *err);
	chemin = ft_strjoin(args.link[args.i], "/");
	tmp = ft_strjoin(filename, "/");
	free(chemin);
	next = files;
	args.rec++;
	while (files != NULL)
	{
		chemin = ft_strjoin(tmp, files->name);
		if (ft_dir_recursive(chemin, files->name))
			ft_recursive(chemin, args, err);
		free(chemin);
		files = files->next;
	}
	free(tmp);
	ft_free_list(next, args);
}

t_files		*ft_readdirr(char *filename, t_args args, int *err)
{
	DIR				*folder;
	struct dirent	*file;
	t_files			*files;

	files = NULL;
	folder = opendir(filename);
	if (!folder)
	{
		ft_check_errors(filename, args, err);
		return (NULL);
	}
	while (((file = readdir(folder)) != NULL))
	{
		files = ft_norme_read(filename, file->d_name, files, args);
	}
	free(file);
	closedir(folder);
	return (files);
}
