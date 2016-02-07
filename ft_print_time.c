/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_time.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscariot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 14:10:31 by lscariot          #+#    #+#             */
/*   Updated: 2016/02/07 01:13:23 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_dy(char *month, char *hour, char *year)
{
	time_t	local;
	char	**now;
	int		a;
	int		b;

	local = time(NULL);
	now = ft_strsplit(ctime(&local), ' ');
	a = ft_mn(now[1]);
	b = -1 * ft_mn(month) + (ft_atoi(now[4]) - ft_atoi(year)) * 12;
	if (b + a >= 6)
		return (ft_strndup(year, 4));
	else
		return (ft_strndup(hour, 5));
	return ("shit");
}

char	*ft_print_time(time_t *time)
{
	char	**modif;
	char	*date;
	char	*tmp;

	date = (char*)malloc(sizeof(char) * 13);
	modif = ft_strsplit(ctime(time), ' ');
	ft_strcat(date, modif[1]);
	ft_strcat(date, "  ");
	ft_strcat(date, modif[2]);
	ft_strcat(date, " ");
	tmp = ft_dy(modif[1], modif[3], modif[4]);
	if (ft_strlen(tmp) == 4)
		ft_strcat(date, " ");
	ft_strcat(date, tmp);
	return (date);
}
