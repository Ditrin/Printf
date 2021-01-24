/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdanette <cdanette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 02:06:36 by cdanette          #+#    #+#             */
/*   Updated: 2020/12/20 00:48:00 by cdanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	c;

	i = 0;
	if (*little == '\0' || big == little)
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		c = 0;
		while (big[i] != '\0' && little[c] != '\0' &&
		big[i] == little[c] && i < len)
		{
			i++;
			c++;
		}
		if (little[c] == '\0' && i - c < len)
			return ((char *)big + (i - c));
		i = i - c;
		i++;
	}
	return (NULL);
}
