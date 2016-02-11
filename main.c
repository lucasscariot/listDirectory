/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscariot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 01:31:25 by lscariot          #+#    #+#             */
/*   Updated: 2016/02/11 06:42:59 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	main(int ac, char **av)
{
	t_args		args;
	t_files		*files;
	t_lenmax	max;

	files = NULL;
	args.i = 0;
	ft_check_args(ac, av, &args);
	ft_tri_links(&args);
	while (args.i < args.fns)
	{
		if (args.br)
		{
			ft_recursive(args.link[args.i], args);
		}
		else
		{
			files = ft_readdir(args);
			if (args.t)
				ft_tri_time(files, args);
			else
				ft_tri_files(files, args);
			if (args.l)
			max = ft_maxlen(files);
			ft_show_files(files, args, max);
			ft_free_list(files, args);
		}
		args.i++;
	}
	ft_free_args(&args);
	return (0);
}
