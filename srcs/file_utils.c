/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardo <ricardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 13:09:37 by rsarri-c          #+#    #+#             */
/*   Updated: 2021/10/18 10:52:18 by ricardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

int	ft_openfile(char *file, int mode, t_pipe *pipe)
{
	int		fd;

	if (mode == 0)
	{
		fd = open(file, O_RDONLY);
		if (fd == -1)
			ft_error(2, pipe);
	}
	else if (mode == 1)
	{
		fd = open(file, O_WRONLY);
		if (fd == -1)
			ft_error(3, pipe);
	}
	return (fd);
}
