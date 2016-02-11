/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maxlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscariot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/10 15:40:37 by lscariot          #+#    #+#             */
/*   Updated: 2016/02/11 06:45:56 by lscariot         ###   ########.fr       */
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
	max->date = 0;
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
			max.links = ft_strlen(files->links);
		if (ft_strlen(files->user) > max.user)
			max.user = ft_strlen(files->user);
		if (ft_strlen(files->group) > max.group)
			max.group = ft_strlen(files->group);
		if (ft_strlen(files->size) > max.size)
			max.size = ft_strlen(files->size);
		if (ft_strlen(files->date) > max.date)
			max.date = ft_strlen(files->date);
		files = files->next;
	}
	printf("%d | %d | %d | %d\n", max.name, max.links, max.user, max.group);
	return (max);
}
