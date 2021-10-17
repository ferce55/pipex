/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsarri-c <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 11:10:39 by rsarri-c          #+#    #+#             */
/*   Updated: 2021/08/08 20:16:57 by rsarri-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*t;

	if (!s1 || !s2)
		return (0);
	t = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!t)
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		t[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		t[i] = s2[j];
		j++;
		i++;
	}
	t[i] = '\0';
	return (t);
}
