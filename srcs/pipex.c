/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsarri-c <rsarri-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 12:25:11 by rsarri-c          #+#    #+#             */
/*   Updated: 2021/11/01 13:17:44 by rsarri-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	bye(void)
{
	system("leaks -q pipex");
}

static void	take_paths(t_pipex *pipex, char *envp[])
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			pipex->path = ft_split(ft_strchr(envp[i], '/'), ':');
		i++;
	}
}

static void	ft_exec_cmd(int exec, t_pipex *pipex, char *envp[], int fd[2])
{
	if (exec == 1)
	{
		close(fd[READ_END]);
		dup2(pipex->fdin, STDIN_FILENO);
		close(pipex->fdin);
		dup2(fd[WRITE_END], STDOUT_FILENO);
		close(fd[WRITE_END]);
		ft_exec(1, pipex, envp);
	}
	else if (exec == 2)
	{
		dup2(fd[READ_END], STDIN_FILENO);
		close(fd[READ_END]);
		dup2(pipex->fdout, STDOUT_FILENO);
		close(pipex->fdout);
		ft_exec(2, pipex, envp);
	}
}

static void	ft_pid_checker(t_pipex *pipex, char *envp[], int	fd[2])
{
	int	pid;

	pid = fork();
	if (pid == 0)
		ft_exec_cmd(1, pipex, envp, fd);
	else
	{
		close(fd[WRITE_END]);
		pid = fork();
		if (pid == 0)
			ft_exec_cmd(2, pipex, envp, fd);
		else
			close(fd[READ_END]);
	}
}

int	main(int argc, char **argv, char *envp[])
{
	t_pipex	*pipex;
	int		fd[2];
	int		status;

	atexit(bye);
	pipex = ft_calloc(sizeof(t_pipex), 1);
	if (argc != 5)
		ft_error(1, pipex);
	ft_init_pipe(argv, pipex);
	take_paths(pipex, envp);
	pipe(fd);
	ft_pid_checker(pipex, envp, fd);
	wait(&status);
	wait(&status);
	ft_freematrix(pipex->path);
	ft_freepipe(pipex);
	return (0);
}
