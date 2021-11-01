/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardo <ricardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 12:25:11 by rsarri-c          #+#    #+#             */
/*   Updated: 2021/10/24 10:02:20 by ricardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	bye(void)
{
	system("leaks -q pipex");
}

void	take_paths(t_pipe *pipe, char *envp[])
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			pipe->path = ft_split(ft_strchr(envp[i], '/'), ':');
		i++;
	}
}

int	main(int argc, char **argv, char *envp[])
{
	t_pipe	*pipe;
	int		fdin;
	int		fdout;

	atexit(bye);
	pipe = ft_calloc(sizeof(t_pipe), 1);
	if (argc != 5)
		ft_error(1, pipe);
	fdin = ft_openfile(argv[1], 0, pipe);
	fdout = ft_openfile(argv[4], 1, pipe);
	pipe->fdin = fdin;
	pipe->fdout = fdout;
	take_paths(pipe, envp);
	ft_freepipe(pipe);
	return (0);
}
