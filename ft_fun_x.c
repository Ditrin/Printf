/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fun_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdanette <cdanette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 23:15:55 by cdanette          #+#    #+#             */
/*   Updated: 2021/01/27 00:28:12 by cdanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		unsigned_nbr_len(long long int n, int base)
{
	int		len;

	len = 0;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= base;
		len++;
	}
	return (len);
}

int		left_hex(t_hole hole, int hexlen, char *p)
{
	int		count;

	count = 0;
	while (hole.prec > 0)
	{
		count += write(1, "0", 1);
		hole.prec--;
	}
	count += write(1, p, hexlen);
	while (hole.width > 0)
	{
		count += write(1, " ", 1);
		hole.width--;
	}
	free(p);
	return (count);
}

int		right_hex(t_hole hole, int hexlen, char *p)
{
	char	c;
	int		count;

	count = 0;
	c = (hole.zero ? '0' : ' ');
	while (hole.width > 0)
	{
		count += write(1, &c, 1);
		hole.width--;
	}
	while (hole.prec > 0)
	{
		count += write(1, "0", 1);
		hole.prec--;
	}
	count += write(1, p, hexlen);
	free(p);
	return (count);
}

int		ft_fun_x(unsigned int n, t_hole hole, char c, int count)
{
	char	*p;
	int		hexlen;

	hexlen = unsigned_nbr_len(n, 16);
	if (c == 'x')
		p = ft_itoa_base(n, 16);
	else if (c == 'X')
		p = ft_itoa_base_upper(n, 16);
	if (n == 0)
	{
		hexlen = 1;
		if (hole.prec == 0)
			hexlen = 0;
	}
	if (hole.prec && hole.prec > hexlen)
		hole.prec = hole.prec - hexlen;
	else
		hole.prec = -1;
	hole.width = hole.width - ((hole.prec > 0 ? hole.prec : 0) + hexlen);
	if (hole.minus == 0)
		count += right_hex(hole, hexlen, p);
	else if (hole.minus == 1)
		count += left_hex(hole, hexlen, p);
	return (count);
}
