/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdanette <cdanette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 23:45:51 by cdanette          #+#    #+#             */
/*   Updated: 2020/12/02 00:47:00 by cdanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *mem1, const void *mem2, size_t num)
{
	size_t			i;
	unsigned char	*fir;
	unsigned char	*sec;

	fir = (unsigned char *)mem1;
	sec = (unsigned char *)mem2;
	i = 0;
	while (i < num)
	{
		if (fir[i] != sec[i])
			return (fir[i] - sec[i]);
		i++;
	}
	return (0);
}
