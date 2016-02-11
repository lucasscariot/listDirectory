/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readdir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscariot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 05:02:06 by lscariot          #+#    #+#             */
/*   Updated: 2016/02/11 09:16:25 by lscariot         ###   ########.fr       */
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
	ft_tri_files(files, args);
	ft_show_recursive(filename, files, args);
	chemin = ft_strjoin(args.link[args.i], "/");
	tmp = ft_strjoin(filename, "/");
	while (files != NULL)
	{
		next = files->next;
		chemin = ft_strjoin(tmp, files->name);
		if ((i = ft_isdir(chemin))
				&& ft_strcmp(".", files->name)
				&& ft_strcmp("..", files->name))
		{
			ft_recursive(chemin, args);
		}
		//ft_free_list(files, args);
		files = next;
	}
	return (0);
}

t_files		*ft_readdir(t_args args)
{
	DIR				*folder;
	struct dirent	*file;
	t_files			*files;
	char			*tmp;

	files = NULL;
	folder = opendir(args.link[args.i]);
	if (!folder)
		return (NULL);
	tmp = ft_strjoin(args.link[args.i], "/");
	while (((file = readdir(folder)) != NULL))
	{
		//tmp = ft_strcat(tmp, " ");
		if (file->d_name[0] != '.' || args.a)
		{
			if (args.l == 1)
				files = ft_list_big_bot(files, file->d_name, args);
			else
				files = ft_list_simple_bot(files, file->d_name);
		}
	}
	free(tmp);
	free(file);
	closedir(folder);
	return (files);
}

t_files		*ft_readdirr(char *filename, t_args args)
{
	DIR				*folder;
	struct dirent	*file;
	t_files			*files;
	char			*tmp;

	files = NULL;
	folder = opendir(filename);
	if (!folder)
		return (NULL);
	while (((file = readdir(folder)) != NULL))
	{
		//tmp = ft_strjoin(args.link[args.i], files->name);
		if (file->d_name[0] != '.' || args.a)
		{
			if (args.l == 1)
				files = ft_list_big_bot(files, file->d_name, args);
			else
				files = ft_list_simple_bot(files, file->d_name);
		}
	}
	free(file);
	closedir(folder);
	return (files);
}
