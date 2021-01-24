/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdanette <cdanette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 20:47:15 by cdanette          #+#    #+#             */
/*   Updated: 2020/12/20 00:25:32 by cdanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*res;
	unsigned int	i;
	size_t			nub;

	i = 0;
	if (!s)
		return (NULL);
	res = (char *)malloc(sizeof(char) * len + 1);
	nub = ft_strlen(s);
	if (!res)
		return (NULL);
	while (len && start < nub)
	{
		res[i] = s[start];
		i++;
		start++;
		len--;
	}
	res[i++] = '\0';
	return ((char *)res);
}
