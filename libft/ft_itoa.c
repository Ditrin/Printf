/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdanette <cdanette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 21:53:51 by cdanette          #+#    #+#             */
/*   Updated: 2020/12/20 00:08:36 by cdanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(int num)
{
	int				i;
	unsigned int	unum;

	i = 0;
	if (num < 0)
	{
		unum = num * -1;
		i++;
	}
	else if (num == 0)
		return (1);
	else
		unum = num;
	while (unum > 0)
	{
		unum = unum / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	char			*str;
	int				i;
	unsigned int	unum;

	i = ft_count(n);
	if (!(str = malloc(sizeof(char) * i + 1)))
		return (NULL);
	str[i] = '\0';
	if (n < 0)
		unum = n * -1;
	else
		unum = n;
	while (i != 0)
	{
		i--;
		str[i] = unum % 10 + '0';
		unum = unum / 10;
	}
	if (n < 0)
		str[i] = '-';
	return (str);
}
