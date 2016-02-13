/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscariot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 01:31:25 by lscariot          #+#    #+#             */
/*   Updated: 2016/02/13 00:45:00 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	main(int ac, char **av)
{
	t_args		args;
	t_files		*files;

	files = NULL;
	args.i = 0;
	ft_check_args(ac, av, &args);
	ft_tri_links(&args);
	while (args.i < args.fns)
	{
		if (args.br)
			ft_recursive(args.link[args.i], args);
		else
		{
			files = ft_readdirr(args.link[args.i], args);
			if (args.t)
				ft_tri_time(files, args);
			else
				ft_tri_files(files, args);
			ft_show_files(args.link[args.i], files, args);
			ft_free_list(files, args);
		}
		args.i++;
	}
	ft_free_args(&args);
	return (0);
}
