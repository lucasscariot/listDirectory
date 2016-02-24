/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_infofile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscariot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 05:42:05 by lscariot          #+#    #+#             */
/*   Updated: 2016/02/24 18:26:49 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_show_modes(int mode)
{
	char	*m;

	m = malloc(sizeof(char) * 11);
	ft_m_0(&m[0], mode);
	m[1] = (mode & S_IRUSR) ? 'r' : '-';
	m[2] = (mode & S_IWUSR) ? 'w' : '-';
	ft_m_3(&m[3], mode);
	m[4] = (mode & S_IRGRP) ? 'r' : '-';
	m[5] = (mode & S_IWGRP) ? 'w' : '-';
	ft_m_6(&m[6], mode);
	m[7] = (mode & S_IROTH) ? 'r' : '-';
	m[8] = (mode & S_IWOTH) ? 'w' : '-';
	ft_m_9(&m[9], mode);
	m[10] = '\0';
	return (m);
}

char	*ft_get_uname(int uid, struct passwd *user)
{
	user = getpwuid(uid);
	return (user->pw_name);
}

char	*ft_get_group(int gid, struct group *group)
{
	group = getgrgid(gid);
	return (group->gr_name);
}

t_files	*ft_infofile(t_files *file, char *adress)
{
	struct stat		state;
	struct passwd	user;
	struct group	groupe;
	char			*boeuf;

	boeuf = ft_strnew(1024);
	lstat(adress, &state);
	if (readlink(adress, boeuf, 1024) > 0)
		file->name = ft_readlink(file->name, boeuf);
	if (!state.st_dev)
		return (NULL);
	file->modes = ft_show_modes(state.st_mode);
	file->links = ft_itoa(state.st_nlink);
	file->user = ft_strdup(ft_get_uname(state.st_uid, &user));
	file->group = ft_strdup(ft_get_group(state.st_gid, &groupe));
	if (file->modes[0] == 'c')
		file->size = ft_s(major(state.st_rdev), minor(state.st_rdev));
	else
		file->size = ft_itoa(state.st_size);
	ft_print_time(&state.st_mtime, file);
	file->nb_blocks = state.st_blocks;
	file->next = NULL;
	free(boeuf);
	return (file);
}
