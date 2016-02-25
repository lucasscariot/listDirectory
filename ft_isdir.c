/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscariot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 10:41:05 by lscariot          #+#    #+#             */
/*   Updated: 2016/02/25 17:23:14 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_check_errors(char *filename, t_args args)
{
	if (!ft_isfile(filename))
	{
		ft_error_file(filename);
		return (1);
	}
	else if (!ft_isperm(filename))
	{
		if (ft_isdir(filename))
			ft_error_perm(filename, args);
		else
			ft_error_file(filename);
		return (1);
	}
	else if (!ft_isopen(filename) && !ft_isdir(filename))
	{
		ft_putcolor("One File", RED);
		ft_one_file(filename, args);
		return (1);
	}
	return (0);
}

int		ft_isopen(char *filename)
{
	DIR	*folder;

	folder = opendir(filename);
	if (!folder)
		return (0);
	free(folder);
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
		return (0);
	return (1);
}
