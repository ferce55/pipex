/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsarri-c <rsarri-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 12:25:08 by rsarri-c          #+#    #+#             */
/*   Updated: 2021/10/17 19:34:22 by rsarri-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static int	ft_errormsg(char *str)
{
	ft_putstr_fd(str, 0);
	exit(1);
}

int	ft_error(int ecode)
{
	if (ecode == 1)
		ft_errormsg("** ERROR **\nEl numero de argumentos es erroneo");
	else if (ecode == 2)
		ft_errormsg("** ERROR **\nError al abrir el fichero origen");
	else if (ecode == 3)
		ft_errormsg("** ERROR **\nError al abrir el fichero destino");
	return (0);
}
