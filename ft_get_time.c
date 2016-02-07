/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscariot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 00:28:36 by lscariot          #+#    #+#             */
/*   Updated: 2016/02/07 15:09:53 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_count_total(t_files *files)
{
	int	total;

	total = 0;
	while (files != NULL)
	{
		total = total + files->nb_blocks;
		files = files->next;
	}
	ft_putstr("total ");
	ft_putnbr(total);
	ft_putchar('\n');
	return (total);
}

char	*ft_get_time(char *file)
{
	struct stat	state;

	lstat(file, &state);
	if (!state.st_dev)
		return (NULL);
	return (ctime(&state.st_mtime));
}
