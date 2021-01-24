/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdanette <cdanette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 21:54:32 by cdanette          #+#    #+#             */
/*   Updated: 2020/12/15 23:27:13 by cdanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	char	*cl;
	int		i;

	if (!s)
		return (NULL);
	cl = (char *)s;
	i = 0;
	if (!(str = (char *)malloc(sizeof(char) * (ft_strlen(cl) + 1))))
		return (NULL);
	while (cl[i] != '\0')
	{
		str[i] = f(i, cl[i]);
		i++;
	}
	str[i++] = '\0';
	return (str);
}
