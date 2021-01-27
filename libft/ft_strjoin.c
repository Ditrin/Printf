/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdanette <cdanette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/09 03:45:50 by cdanette          #+#    #+#             */
/*   Updated: 2021/01/27 00:25:58 by cdanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char		*conc;
	size_t		i;

	i = 0;
	if (s1 == 0 || s2 == 0)
		return (NULL);
	if (!(conc = (char *)malloc(sizeof(*conc) * (ft_strlen(s1) +
	ft_strlen(s2) + 1))))
		return (NULL);
	while (*s1 != '\0')
		conc[i++] = *s1++;
	while (*s2 != '\0')
		conc[i++] = *s2++;
	conc[i] = '\0';
	return (conc);
}
