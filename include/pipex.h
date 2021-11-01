/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardo <ricardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 12:25:05 by rsarri-c          #+#    #+#             */
/*   Updated: 2021/10/24 10:04:20 by ricardo          ###   ########.fr       */
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

typedef struct s_pipe
{
	char	**path;
	char	*first_cmd;
	char	*sec_cmd;
	int		fdin;
	int		fdout;
}			t_pipe;

int		ft_error(int ecode, t_pipe *pipe);
int		ft_openfile(char *file, int mode, t_pipe *pipe);
void	ft_freepipe(t_pipe *pipe);

#endif
