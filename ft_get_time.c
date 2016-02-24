/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscariot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/07 00:28:36 by lscariot          #+#    #+#             */
/*   Updated: 2016/02/24 18:23:03 by lscariot         ###   ########.fr       */
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

int		ft_list_len(t_files *files)
{
	int	i;

	i = 0;
	while (files != NULL)
	{
		files = files->next;
		i++;
	}
	return (i);
}

time_t	ft_get_time(char *file)
{
	struct stat	state;

	lstat(file, &state);
	if (!state.st_dev)
		return (0);
	return (state.st_mtimespec.tv_sec);
}

char	*ft_readlink(char *name, char *ln)
{
	char	*tmp;
	char	*tmp2;

	free(name);
	tmp = ft_strjoin(name, " -> ");
	tmp2 = ft_strdup(tmp);
	free(tmp);
	tmp = ft_strjoin(tmp2, ln);
	free(tmp2);
	return (tmp);
}

char	*ft_s(int b, int a)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_strjoin(ft_itoa(b), ", ");
	tmp2 = ft_strdup(tmp);
	free(tmp);
	tmp = ft_strjoin(tmp2, ft_itoa(a));
	free(tmp2);
	return (tmp);
}
