/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscariot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 10:41:05 by lscariot          #+#    #+#             */
/*   Updated: 2016/02/26 21:15:44 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_check_errors(char *filename, t_args args, int *err)
{
	if (!ft_isperm(filename) && ft_isdir(filename))
	{
		*err = 1;
		ft_error_perm(filename, args);
	}
	else if (ft_isfile(filename))
	{
		*err = 1;
		ft_one_file(filename, args);
	}
	else
		*err = 1;
	return (0);
}

int		ft_isopen(char *filename)
{
	DIR	*folder;

	folder = opendir(filename);
	if (!folder)
		return (0);
	closedir(folder);
	return (1);
}

int		ft_isdir(char *filename)
{
	struct stat	stat;

	lstat(filename, &stat);
	if (!stat.st_dev)
		return (0);
	if (S_ISDIR(stat.st_mode))
		return (1);
	return (0);
}

int		ft_isfile(char *filename)
{
	struct stat state;

	if (lstat(filename, &state) == -1)
		return (0);
	return (1);
}

int		ft_isperm(char *filename)
{
	struct stat perm;
	char		*tmp;

	lstat(filename, &perm);
	tmp = ft_show_modes(perm.st_mode);
	if (tmp[1] != 'r')
	{
		free(tmp);
		return (0);
	}
	free(tmp);
	return (1);
}
