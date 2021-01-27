/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fun_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdanette <cdanette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 00:46:12 by cdanette          #+#    #+#             */
/*   Updated: 2021/01/27 00:28:34 by cdanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_fun_c(int symbol, t_hole *hole, int len)
{
	int	digit;

	digit = 0;
	if (hole->width && hole->minus == 0)
	{
		digit = hole->width - 1;
		if (hole->zero == 0)
			while (digit-- > 0)
				len += write(1, " ", 1);
		else if (hole->zero != 0)
			while (digit-- > 0)
				len += write(1, "0", 1);
		len += write(1, &symbol, 1);
	}
	else if (hole->width && hole->minus == 1)
	{
		digit = hole->width - 1;
		len += write(1, &symbol, 1);
		while (digit-- > 0)
			len += write(1, " ", 1);
	}
	else
		len += write(1, &symbol, 1);
	return (hole->width > 0 ? hole->width : 1);
}
