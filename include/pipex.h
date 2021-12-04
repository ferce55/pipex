/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsarri-c <rsarri-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 12:25:05 by rsarri-c          #+#    #+#             */
/*   Updated: 2021/12/04 12:55:19 by rsarri-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <sys/types.h>
# include <fcntl.h>
# include <stdio.h>

# define READ_END	0
# define WRITE_END	1

typedef struct s_pipex
{
	char	**path;
	char	*first_cmd;
	char	*sec_cmd;
	int		fdin;
	int		fdout;
}			t_pipex;

int		ft_error(int ecode, t_pipex *pipex, char *cmd);
int		ft_openfile(char *file, int mode, t_pipex *pipex);
void	ft_freepipe(t_pipex *pipex);
void	ft_freematrix(char **matrix);
void	ft_init_pipe(char **argv, t_pipex *pipex);
char	*path_cmd(t_pipex *pipex, char **envp, char *cmd);

#endif
