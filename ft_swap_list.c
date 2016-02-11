/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscariot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 12:05:09 by lscariot          #+#    #+#             */
/*   Updated: 2016/02/11 07:47:50 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_swap_cpy(t_files *dest, t_files *src, int l)
{
	dest->name = ft_strdup(src->name);
	if (l)
	{
		dest->modes = ft_strdup(src->modes);
		dest->links = ft_strdup(src->links);
		dest->user = ft_strdup(src->user);
		dest->group = ft_strdup(src->group);
		dest->size = ft_strdup(src->size);
		dest->month = ft_strdup(src->month);
		dest->number = ft_strdup(src->number);
		dest->hour = ft_strdup(src->hour);
	}
}

void	ft_swap_list(t_files *f, t_files *s, int l)
{
	t_files	*tmp;

	if (!f && !s)
		return ;
	tmp = (t_files*)malloc(sizeof(t_files));
	ft_swap_cpy(tmp, s, l);
	ft_free_one(s, l);
	ft_swap_cpy(s, f, l);
	ft_free_one(f, l);
	ft_swap_cpy(f, tmp, l);
	ft_free_one(tmp, l);
	free(tmp);
}
