/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdanette <cdanette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/30 21:07:45 by cdanette          #+#    #+#             */
/*   Updated: 2021/01/26 23:50:39 by cdanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *mem1, const void *mem2, size_t count)
{
	size_t i;

	i = 0;
	while (i < count)
	{
		((unsigned char *)mem1)[i] = ((unsigned char *)mem2)[i];
		i++;
	}
	return (mem1);
}
