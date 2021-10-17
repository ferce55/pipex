/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsarri-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 11:07:10 by rsarri-c          #+#    #+#             */
/*   Updated: 2021/08/08 12:41:45 by rsarri-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	tsize;
	void	*dst;

	tsize = count * size;
	dst = malloc(tsize);
	if (!(dst))
		return (0);
	ft_memset(dst, 0, tsize);
	return (dst);
}
