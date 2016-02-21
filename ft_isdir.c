/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscariot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/06 10:41:05 by lscariot          #+#    #+#             */
/*   Updated: 2016/02/21 11:35:12 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_isdir(char *filename)
{
	DIR	*folder;

	folder = opendir(filename);
	if (!folder)
		return (0);
	free(folder);
	return (1);
}
