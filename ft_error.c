/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscariot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/20 12:47:54 by lscariot          #+#    #+#             */
/*   Updated: 2016/02/24 18:24:51 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_error_opt(char c)
{
	ft_putstr("ft_ls: illegal option -- ");
	ft_putchar(c);
	ft_putstr("\nusage: ft_ls [-Ralrt] [file ...]\n");
	exit(0);
}

void	ft_error_file(char *file)
{
	ft_putstr("ft_ls: ");
	ft_putstr(file);
	ft_putendl(": No such file or directory");
}

void	ft_error_perm(char *file, t_args args)
{
	if (args.fns > 1 || (args.br && args.rec > 0))
	{
		if (args.i > 0 || args.rec > 0)
			ft_putchar('\n');
		ft_putstr(file);
		ft_putendl(":");
	}
	ft_putstr("ft_ls: ");
	ft_putstr(file);
	ft_putendl(": Permission denied");
}

void	ft_error_tri(t_args *args)
{
	int i;

	i = 0;
	while (args->fns > i)
	{
		if (!ft_isopen(args->link[i]))
			ft_error_file(args->link[i]);
		i++;
	}
}
