/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_norme.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscariot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 15:18:04 by lscariot          #+#    #+#             */
/*   Updated: 2016/02/27 10:44:44 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_no_link(t_args *args)
{
	args->link = (char **)malloc(sizeof(char*));
	args->link[0] = ft_strdup(".");
	args->fns = 1;
}

int			ft_dir_recursive(char *chemin, char *filename)
{
	if (ft_isdir(chemin) && ft_strcmp("..", filename)
			&& ft_strcmp(".", filename))
		return (1);
	return (0);
}

t_files		*ft_norme_read(char *fname, char *n, t_files *files, t_args args)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_strjoin(fname, "/");
	tmp2 = ft_strjoin(tmp, n);
	if (n[0] != '.' || args.a)
	{
		if (args.l == 1)
			files = ft_list_big_bot(files, tmp2, n);
		else
			files = ft_list_simple_bot(files, n);
	}
	free(tmp);
	free(tmp2);
	return (files);
}

void		ft_file_name_norme(char *fl, t_args args, int *i, int err)
{
	if (!i)
		*i = 0;
	if ((args.fns > 1 || args.br) && !err)
	{
		if (*i > 0)
			ft_putchar('\n');
		ft_putstr(fl);
		ft_putendl(":");
	}
}

time_t  ft_get_utime(char *file)
{
	struct stat state;

	lstat(file, &state);
	if (!state.st_mtime)
		return (0);
	return (state.st_mtimespec.tv_nsec);
}
