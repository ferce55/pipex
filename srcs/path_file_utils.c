/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_file_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsarri-c <rsarri-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 13:09:37 by rsarri-c          #+#    #+#             */
/*   Updated: 2021/11/01 13:19:56 by rsarri-c         ###   ########.fr       */
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
			ft_error(2, pipex);
	}
	else if (mode == 1)
	{
		fd = open(file, O_WRONLY);
		if (fd == -1)
			ft_error(3, pipex);
	}
	return (fd);
}

void	ft_exec(int exec, t_pipex *pipex, char *envp[])
{
	
}
