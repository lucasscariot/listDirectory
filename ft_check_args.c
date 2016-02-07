/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscariot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 22:54:07 by lscariot          #+#    #+#             */
/*   Updated: 2016/02/04 13:58:12 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ft_check_args(int ac, char **av, t_args *args)
{
	int		i;
	int		f;
	int		l;

	args->l = 0;
	args->a = 0;
	args->br = 0;
	args->r = 0;
	args->t = 0;
	args->i = 0;
	i = 1;
	l = 1;
	f = 0;
	while (i < ac && l)
	{
		if (av[i][0] == '-')
		{
			if (ft_strchr(av[i], 'l'))
				args->l = 1;
			if (ft_strchr(av[i], 'R'))
				args->br = 1;
			if (ft_strchr(av[i], 'a'))
				args->a = 1;
			if (ft_strchr(av[i], 'r'))
				args->r = 1;
			if (ft_strchr(av[i], 't'))
				args->t = 1;
			i++;
		}
		else
			l = 0;
	}
	if ((ac - i) == 0)
	{
		args->link = (char **)malloc(sizeof(char*));
		args->link[0] = ft_strdup(".");
		args->fns = 1;
	}
	else
	{
		args->link = (char **)malloc(sizeof(char*) * (ac - i));
		while (av[i])
			args->link[f++] = ft_strdup(av[i++]);
		args->fns = f;
	}
	return (0);
}
