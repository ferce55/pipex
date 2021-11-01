/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsarri-c <rsarri-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 12:25:08 by rsarri-c          #+#    #+#             */
/*   Updated: 2021/11/01 13:17:07 by rsarri-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static int	ft_errormsg(char *str)
{
	ft_putstr_fd(str, 0);
	exit(1);
}

void	ft_freepipe(t_pipex *pipex)
{
	free(pipex->first_cmd);
	free(pipex->sec_cmd);
	free(pipex);
}

void	ft_freematrix(char **matrix)
{
	int	i;

	i = -1;
	while (matrix[++i])
		free (matrix[i]);
	free (matrix);
}

void	ft_init_pipe(char **argv, t_pipex *pipex)
{
	int	fdin;
	int	fdout;

	fdin = ft_openfile(argv[1], 0, pipex);
	fdout = ft_openfile(argv[4], 1, pipex);
	pipex->fdin = fdin;
	pipex->fdout = fdout;
	pipex->first_cmd = ft_strdup(argv[2]);
	pipex->sec_cmd = ft_strdup(argv[3]);
}

int	ft_error(int ecode, t_pipex *pipex)
{
	ft_freepipe(pipex);
	if (ecode == 1)
		ft_errormsg("** ERROR **\nEl numero de argumentos es erroneo\n");
	else if (ecode == 2)
		ft_errormsg("** ERROR **\nError al abrir el fichero origen\n");
	else if (ecode == 3)
		ft_errormsg("** ERROR **\nError al abrir el fichero destino\n");
	return (0);
}
