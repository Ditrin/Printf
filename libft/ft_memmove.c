/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdanette <cdanette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 22:33:13 by cdanette          #+#    #+#             */
/*   Updated: 2020/12/05 21:49:33 by cdanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *source, size_t n)
{
	unsigned char		*to;
	unsigned char		*src;
	size_t				i;

	src = (unsigned char *)source;
	to = (unsigned char *)dest;
	i = 0;
	if (!dest && !source)
		return (dest);
	if (to < src)
		while (i < n)
		{
			to[i] = src[i];
			i++;
		}
	else
	{
		i = n;
		while (i--)
			to[i] = src[i];
	}
	return (dest);
}
