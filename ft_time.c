/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscariot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 01:12:12 by lscariot          #+#    #+#             */
/*   Updated: 2016/02/12 17:44:34 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_revtimecomp(char *file1, char *file2)
{
	char	**t1;
	char	**t2;
	char	**h1;
	char	**h2;
	int		i;

	i = 0;
	if (ft_atoi(t1[4]) > ft_atoi(t2[4]))
		return (1);
	if (ft_mn(t1[1]) > ft_mn(t2[1]))
		return (1);
	if (ft_atoi(t1[2]) > ft_atoi(t2[2]))
		return (1);
	if (ft_atoi(h1[0]) > ft_atoi(h2[0]))
		i = 1;
	return (0);
	ft_free_tab(t1);
	ft_free_tab(t2);
}

int		ft_timecomp(char *file1, char *file2)
{
	char	**t1;
	char	**t2;
	char	**h1;
	char	**h2;
	int		i;

	i = 0;
	t1 = ft_strsplit(ft_get_time(file1), ' ');
	t2 = ft_strsplit(ft_get_time(file2), ' ');
	h1 = ft_strsplit(t1[3], ':');
	h2 = ft_strsplit(t2[3], ':');
	if (ft_atoi(t1[4]) < ft_atoi(t2[4]))
		i = 1;
	else if (ft_mn(t1[1]) < ft_mn(t2[1]))
		i = 1;
	else if (ft_atoi(t1[2]) < ft_atoi(t2[2]))
		i = 1;
	ft_free_tab(t1);
	ft_free_tab(t2);
	return (i);
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

int	ft_dn(char	*day)
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
