/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscariot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 01:31:25 by lscariot          #+#    #+#             */
/*   Updated: 2016/02/26 13:27:06 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	main(int ac, char **av)
{
	t_args		args;
	t_files		*files;
	int			err;

	files = NULL;
	args.i = 0;
	err = 0;
	ft_check_args(ac, av, &args);
	ft_tri_links(&args);
	while (args.i < args.fns)
	{
		if (args.br)
			ft_recursive(args.link[args.i], args, &err);
		else
		{
			files = ft_readdirr(args.link[args.i], args, &err);
			ft_tri(files, args);
			ft_show_files(args.link[args.i], files, args, err);
			ft_free_list(files, args);
		}
		err = 0;
		args.i++;
	}
	ft_free_args(&args);
	return (0);
}
