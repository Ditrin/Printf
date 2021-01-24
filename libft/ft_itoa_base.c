/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdanette <cdanette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 05:42:24 by cdanette          #+#    #+#             */
/*   Updated: 2021/01/24 05:47:13 by cdanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base(uintmax_t val, uintmax_t base)
{
	unsigned long long	n;
	char				*s;
	int					i;

	i = 1;
	n = val;
	while ((n /= base) >= 1)
		i++;
	s = (char*)malloc(sizeof(char) * (i + 1));
	s[i] = '\0';
	while (i-- > 0)
	{
		s[i] = (val % base < 10) ? val % base + '0' : val % base + 'a' - 10;
		val /= base;
	}
	return (s);
}
