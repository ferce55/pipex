/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsarri-c <rsarri-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 12:25:11 by rsarri-c          #+#    #+#             */
/*   Updated: 2021/12/04 13:01:32 by rsarri-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static void	bye(void)
{
	system("leaks -q pipex");
}

static void	ft_exec_cmd(t_pipex *pipex, char *cmd, char *envp[])
{
	char	*path;
	char	**excmd;

	excmd = ft_split(cmd, ' ');
	if (ft_strchr(excmd[0], '/'))
	{
		path = excmd[0];
		if (access(path, X_OK) == -1)
		{
			ft_error(4, pipex, excmd[0]);
			return ;
		}
	}
	else
		path = path_cmd(pipex, envp, excmd[0]);
	execve(path, excmd, envp);
}

static void	ft_fd_handler(int exec, t_pipex *pipex, char *envp[], int fd[2])
{
	char	*path;
	char	**cmd;

	if (exec == 1)
	{
		close(fd[READ_END]);
		dup2(pipex->fdin, STDIN_FILENO);
		close(pipex->fdin);
		dup2(fd[WRITE_END], STDOUT_FILENO);
		close(fd[WRITE_END]);
		ft_exec_cmd(pipex, pipex->first_cmd, envp);
	}
	else if (exec == 2)
	{
		dup2(fd[READ_END], STDIN_FILENO);
		close(fd[READ_END]);
		dup2(pipex->fdout, STDOUT_FILENO);
		close(pipex->fdout);
		ft_exec_cmd(pipex, pipex->sec_cmd, envp);
	}
}

static void	ft_pid_checker(t_pipex *pipex, char *envp[], int fd[2])
{
	int	pid;

	pid = fork();
	if (pid == 0)
		ft_fd_handler(1, pipex, envp, fd);
	else
	{
		close(fd[WRITE_END]);
		pid = fork();
		if (pid == 0)
			ft_fd_handler(2, pipex, envp, fd);
		else
			close(fd[READ_END]);
	}
}

int	main(int argc, char **argv, char *envp[])
{
	t_pipex	*pipex;
	int		fd[2];
	int		status;

	pipex = ft_calloc(sizeof(t_pipex), 1);
	if (argc != 5)
		ft_error(1, pipex, "");
	ft_init_pipe(argv, pipex);
	pipe(fd);
	ft_pid_checker(pipex, envp, fd);
	wait(&status);
	wait(&status);
	ft_freepipe(pipex);
	atexit(bye);
	return (0);
}
