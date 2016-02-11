/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maxlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscariot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 15:40:37 by lscariot          #+#    #+#             */
/*   Updated: 2016/02/11 08:00:42 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_declare(t_lenmax *max)
{
	max->name = 0;
	max->links = 0;
	max->user = 0;
	max->group = 0;
	max->size = 0;
	max->month = 0;
	max->number = 0;
	max->hour = 0;
}

t_lenmax	ft_maxlen(t_files *files)
{
	t_lenmax	max;

	ft_declare(&max);
	while (files != NULL)
	{
		if (ft_strlen(files->name) > max.name)
			max.name = ft_strlen(files->name);
		if (ft_strlen(files->links) > max.links)
			max.links = (ft_strlen(files->links) + 1);
		if (ft_strlen(files->user) > max.user)
			max.user = ft_strlen(files->user);
		if (ft_strlen(files->group) > max.group)
			max.group = (ft_strlen(files->group) + 1);
		if (ft_strlen(files->size) > max.size)
			max.size = (ft_strlen(files->size) + 1);
		if (ft_strlen(files->month) > max.month)
			max.month = ft_strlen(files->month);
		if (ft_strlen(files->number) > max.number)
			max.number = ft_strlen(files->number);
		if (ft_strlen(files->hour) > max.hour)
			max.hour = ft_strlen(files->hour);
		files = files->next;
	}
	return (max);
}
