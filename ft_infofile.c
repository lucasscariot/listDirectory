/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_infofile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lscariot <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 05:42:05 by lscariot          #+#    #+#             */
/*   Updated: 2016/02/07 17:24:32 by lscariot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_m_0(char *m, int mode)
{
	if (S_ISDIR(mode))
		*m = 'd';
	else if (S_ISLNK(mode))
		*m = 'l';
	else if (S_ISCHR(mode))
		*m = 'c';
	else
		*m = '-';
}

char	*ft_show_modes(int mode)
{
	char	*m;

	m =  malloc(sizeof(char) * 11);
	ft_m_0(&m[0], mode);
	m[1] = (mode & S_IRUSR) ? 'r' : '-';
	m[2] = (mode & S_IWUSR) ? 'w' : '-';
	m[3] = (mode & S_IXUSR) ? 'x' : '-';
	m[4] = (mode & S_IRGRP) ? 'r' : '-';
	m[5] = (mode & S_IWGRP) ? 'w' : '-';
	m[6] = (mode & S_IXGRP) ? 'x' : '-';
	m[7] = (mode & S_IROTH) ? 'r' : '-';
	m[8] = (mode & S_IWOTH) ? 'w' : '-';
	m[9] = (mode & S_IXOTH) ? 'x' : '-';
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

t_files	*ft_infofile(t_files *file)
{
	struct stat		state;
	struct passwd	user;
	struct group	group;

	lstat(file->name, &state);
	if (!state.st_dev)
		return (NULL);
	file->namelen = ft_strlen(file->name);
	file->modes = ft_show_modes(state.st_mode);
	file->links = ft_itoa(state.st_nlink);
	file->linkslen = ft_strlen(file->links);
	file->user = ft_strdup(ft_get_uname(state.st_uid, &user));
	file->userlen = ft_strlen(file->user);
	file->group = ft_strdup(ft_get_group(state.st_gid, &group));
	file->grouplen = ft_strlen(file->group);
	file->size = ft_itoa(state.st_size);
	file->sizelen = ft_strlen(file->size);
	file->date = ft_print_time(&state.st_mtime);
	file->nb_blocks = state.st_blocks;
	file->next = NULL;
	return (file);
}
