/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_norme.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscariot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 15:18:04 by lscariot          #+#    #+#             */
/*   Updated: 2016/02/26 10:16:01 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_no_link(t_args *args)
{
	args->link = (char **)malloc(sizeof(char*));
	args->link[0] = ft_strdup(".");
	args->fns = 1;
}

int	ft_dir_recursive(char *chemin, char *filename)
{
	if (ft_isdir(chemin) && ft_strcmp("..", filename)
		&& ft_strcmp(".", filename))
		return (1);
	return (0);
}
