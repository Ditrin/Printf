/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdanette <cdanette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 22:54:56 by cdanette          #+#    #+#             */
/*   Updated: 2020/12/02 00:55:55 by cdanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	unsigned char	*src;
	size_t			i;

	i = 0;
	src = ((unsigned char *)arr);
	while (i < n && src[i] != (unsigned char)c)
		i++;
	{
		if (i == n)
			return (NULL);
	}
	return (src + i);
}
