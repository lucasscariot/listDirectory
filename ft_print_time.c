/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_time.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscariot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 14:10:31 by lscariot          #+#    #+#             */
/*   Updated: 2016/02/11 18:38:18 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_dy(char *month, char *hour, char *year)
{
	time_t	local;
	char	**now;
	int		a;
	int		b;

	local = time(NULL);
	now = ft_strsplit(ctime(&local), ' ');
	a = ft_mn(now[1]);
	b = -1 * ft_mn(month) + (ft_atoi(now[4]) - ft_atoi(year)) * 12;
	ft_free_tab(now);
	if (b + a >= 6)
		return (1);
	return (0);
}

char	*ft_print_time(time_t *time, t_files *file)
{
	char	**modif;

	modif = ft_strsplit(ctime(time), ' ');
	file->month = ft_strdup(modif[1]);
	file->number = ft_strdup(modif[2]);
	if (ft_dy(modif[1], modif[3], modif[4]))
		file->hour = ft_strndup(modif[4], 4);
	else
		file->hour = ft_strndup(modif[3], 5);
	ft_free_tab(modif);
	return (NULL);
}
