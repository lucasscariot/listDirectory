/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_m_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscariot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 14:06:54 by lscariot          #+#    #+#             */
/*   Updated: 2016/02/26 00:37:12 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_m_0(char *m, int mode)
{
	if (S_ISDIR(mode))
		*m = 'd';
	else if (S_ISLNK(mode))
		*m = 'l';
	else if (S_ISCHR(mode))
		*m = 'c';
	else
		*m = '-';
}

void	ft_m_3(char *m, int mode)
{
	if (mode & S_IXUSR)
		*m = 'x';
	else
		*m = '-';
	if (mode & S_ISGID)
	{
		if (mode & 0100)
			*m = 's';
		else
			*m = 'S';
	}
}

void	ft_m_6(char *m, int mode)
{
	if (mode & S_IXGRP)
		*m = 'x';
	else
		*m = '-';
	if (mode & S_ISGID)
	{
		if (mode & 0010)
			*m = 's';
		else
			*m = 'S';
	}
}

void	ft_m_9(char *m, int mode)
{
	if (mode & S_IXOTH)
		*m = 'x';
	else
		*m = '-';
	if (mode & S_ISVTX)
	{
		if (mode & 0100)
			*m = 't';
		else
			*m = 'T';
	}
}
