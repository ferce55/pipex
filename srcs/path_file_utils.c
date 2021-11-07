/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_file_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsarri-c <rsarri-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 13:09:37 by rsarri-c          #+#    #+#             */
/*   Updated: 2021/11/07 12:37:51 by rsarri-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	ft_openfile(char *file, int mode, t_pipex *pipex)
{
	int		fd;

	if (mode == 0)
	{
		fd = open(file, O_RDONLY);
		if (fd == -1)
			ft_error(2, pipex, 0);
	}
	else if (mode == 1)
	{
		fd = open(file, O_WRONLY);
		if (fd == -1)
			ft_error(3, pipex, 0);
	}
	return (fd);
}

char	*path_cmd(t_pipex *pipex, char **envp, char *cmd, int pid)
{
	ssize_t	i;
	char	*path;
	char	*tmp;

	if (access(cmd, X_OK) == 0)
	{
		cmd = ft_strchr(cmd, '/');
		cmd++;
	}
	i = -1;
	while (envp[++i])
		if (ft_strncmp("PATH=", envp[i], 5) == 0)
			pipex->path = ft_split(ft_strchr(envp[i], '/'), ':');
	i = 0;
	while (pipex->path[i])
	{
		tmp = ft_strjoin(pipex->path[i], "/");
		path = ft_strjoin(tmp, ft_split(cmd, ' ')[0]);
		free(tmp);
		if (access(path, R_OK) == 0)
			return (path);
		i++;
	}
	ft_error(4, pipex, pid);
	return (0);
}
