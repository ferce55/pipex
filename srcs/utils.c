/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ricardo <ricardo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 12:25:08 by rsarri-c          #+#    #+#             */
/*   Updated: 2021/10/24 10:04:45 by ricardo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static int	ft_errormsg(char *str)
{
	ft_putstr_fd(str, 0);
	exit(1);
}

void	ft_freepipe(t_pipe *pipe)
{
	int	i;

	i = -1;
	printf("libera");
	while (pipe->path[++i])
		free(pipe->path[i]);
	printf("liberado");
	free(pipe->path);
	free(pipe->first_cmd);
	free(pipe->sec_cmd);
	free(pipe);
}

int	ft_error(int ecode, t_pipe *pipe)
{
	ft_freepipe(pipe);
	if (ecode == 1)
		ft_errormsg("** ERROR **\nEl numero de argumentos es erroneo\n");
	else if (ecode == 2)
		ft_errormsg("** ERROR **\nError al abrir el fichero origen\n");
	else if (ecode == 3)
		ft_errormsg("** ERROR **\nError al abrir el fichero destino\n");
	return (0);
}
