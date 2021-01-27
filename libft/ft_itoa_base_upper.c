/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_upper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdanette <cdanette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 05:47:06 by cdanette          #+#    #+#             */
/*   Updated: 2021/01/27 00:26:34 by cdanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa_base_upper(intmax_t val, intmax_t base)
{
	long long	n;
	char		*s;
	int			sign;
	int			i;

	n = (val < 0) ? -val : val;
	sign = (val < 0 && base == 10) ? -1 : 0;
	i = (sign == -1) ? 2 : 1;
	while ((n /= base) >= 1)
		i++;
	s = (char*)malloc(sizeof(char) * (i + 1));
	s[i] = '\0';
	n = (val < 0) ? -val : val;
	while (i-- + sign)
	{
		s[i] = (val % base < 10) ? val % base + '0' : val % base + 'A' - 10;
		val /= base;
	}
	(i == 0) ? s[i] = '-' : 0;
	return (s);
}
