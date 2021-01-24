/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdanette <cdanette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 20:53:40 by cdanette          #+#    #+#             */
/*   Updated: 2020/12/04 01:30:32 by cdanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	if (ch == 0)
		return ((char *)str + i);
	while (i--)
	{
		if (str[i] == ch)
			return ((char *)str + i);
	}
	return (NULL);
}
