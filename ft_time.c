/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscariot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 01:12:12 by lscariot          #+#    #+#             */
/*   Updated: 2016/02/26 20:50:47 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_revtimecomp(char *file1, char *file2)
{
	if (ft_get_time(file1) > ft_get_time(file2))
		return (1);
	return (0);
}

int		ft_timecomp(char *file1, char *file2)
{
	if (ft_get_time(file1) < ft_get_time(file2))
		return (1);
	else if (ft_get_time(file1) == ft_get_time(file2))
		return (0);
	return (0);
}

int		ft_mn(char *month)
{
	if (!ft_strcmp("Jan", month))
		return (1);
	else if (!ft_strcmp("Feb", month))
		return (2);
	else if (!ft_strcmp("Mar", month))
		return (3);
	else if (!ft_strcmp("Apr", month))
		return (4);
	else if (!ft_strcmp("May", month))
		return (5);
	else if (!ft_strcmp("Jun", month))
		return (6);
	else if (!ft_strcmp("Jul", month))
		return (7);
	else if (!ft_strcmp("Aug", month))
		return (8);
	else if (!ft_strcmp("Sep", month))
		return (9);
	else if (!ft_strcmp("Oct", month))
		return (10);
	else if (!ft_strcmp("Nov", month))
		return (11);
	else if (!ft_strcmp("Dec", month))
		return (12);
	return (0);
}

int		ft_dn(char *day)
{
	if (!ft_strcmp("Mon", day))
		return (1);
	if (!ft_strcmp("Tue", day))
		return (2);
	if (!ft_strcmp("Wed", day))
		return (3);
	if (!ft_strcmp("Thu", day))
		return (4);
	if (!ft_strcmp("Fri", day))
		return (5);
	if (!ft_strcmp("Sat", day))
		return (6);
	if (!ft_strcmp("Sun", day))
		return (7);
	return (0);
}
