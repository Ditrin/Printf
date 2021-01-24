/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdanette <cdanette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 00:37:10 by cdanette          #+#    #+#             */
/*   Updated: 2020/12/09 00:41:44 by cdanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t s;

	s = 0;
	i = 0;
	while (dest[i] && i < size)
		i++;
	while (src[s] != '\0' && (s + 1 + i) < size)
	{
		dest[i + s] = src[s];
		s++;
	}
	if (i != size)
		dest[i + s] = '\0';
	return (ft_strlen(src) + i);
}
