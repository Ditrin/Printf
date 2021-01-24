/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdanette <cdanette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 03:22:30 by cdanette          #+#    #+#             */
/*   Updated: 2020/12/16 23:37:38 by cdanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;

	if (s1 == 0 || set == 0)
		return (NULL);
	while (*s1 != '\0' && ft_strchr(set, *s1))
		s1++;
	str = (char *)s1 + ft_strlen(s1) - 1;
	if (str < s1)
		return (ft_strdup(""));
	while (ft_strchr(set, *str))
		str--;
	return (ft_substr(s1, 0, str - s1 + 1));
}
