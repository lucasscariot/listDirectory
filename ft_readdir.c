/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readdir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscariot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 05:02:06 by lscariot          #+#    #+#             */
/*   Updated: 2016/02/26 11:38:46 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ft_recursive(char *filename, t_args args, int *err)
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
	char			*tmp;
	char			*tmp2;

	files = NULL;
	folder = opendir(filename);
	if (!folder)
	{
		ft_check_errors(filename, args, err);
		return (NULL);
	}
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
