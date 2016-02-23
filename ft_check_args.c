/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscariot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 22:54:07 by lscariot          #+#    #+#             */
/*   Updated: 2016/02/23 17:55:47 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_init_args(t_args *args)
{
	args->l = 0;
	args->a = 0;
	args->br = 0;
	args->r = 0;
	args->t = 0;
	args->i = 0;
	args->rec = 0;
}

int			ft_qqchose(char *arg, t_args *args)
{
	int			i;

	i = 1;
	while (arg[i] != '\0')
	{
		if (arg[i] == 'l')
			args->l = 1;
		else if (arg[i] == 'R')
			args->br = 1;
		else if (arg[i] == 'a')
			args->a = 1;
		else if (arg[i] == 'r')
			args->r = 1;
		else if (arg[i] == 't')
			args->t = 1;
		else if (arg[i] == '-' && arg[i + 1] == '\0')
			return (1);
		else
			ft_error_opt(arg[i]);
		i++;
	}
	return (0);
}

int			ft_check_args(int ac, char **av, t_args *args)
{
	int		i;
	int		f;
	int		l;

	i = 1;
	l = 1;
	f = 0;
	ft_init_args(args);
	while (i < ac && l)
	{
		if (av[i][0] == '-')
		{	if (ft_qqchose(av[i++], args))
				break;
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
