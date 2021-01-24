/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdanette <cdanette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 20:23:06 by cdanette          #+#    #+#             */
/*   Updated: 2021/01/18 23:42:01 by cdanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	int i;

	i = 0;
	while ((unsigned char)str[i] != (unsigned char)ch)
	{
		if ((unsigned char)str[i] == '\0')
			return (NULL);
		str++;
	}
	return ((char *)str);
}
