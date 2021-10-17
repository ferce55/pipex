/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsarri-c <rsarri-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 12:25:05 by rsarri-c          #+#    #+#             */
/*   Updated: 2021/10/17 19:35:38 by rsarri-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include <sys/types.h>
# include <fcntl.h>

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

int		ft_error(int ecode);
int		ft_openfile(char *file, int mode);

#endif
