/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdanette <cdanette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 02:32:26 by cdanette          #+#    #+#             */
/*   Updated: 2020/12/09 01:57:28 by cdanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	unsigned char	*fir;
	unsigned char	*sec;
	size_t			i;

	i = 0;
	if (!n)
		return (0);
	fir = (unsigned char *)str1;
	sec = (unsigned char *)str2;
	while ((fir[i] || sec[i]) && i < n)
	{
		if (fir[i] != sec[i])
			return (fir[i] - sec[i]);
		i++;
	}
	return (0);
}
