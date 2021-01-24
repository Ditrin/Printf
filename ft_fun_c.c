/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fun_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdanette <cdanette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 00:46:12 by cdanette          #+#    #+#             */
/*   Updated: 2021/01/24 05:53:23 by cdanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>

int	ft_fun_c(t_hole *hole, va_list ap)
{
	char symbol;
	int digit;
	int len;

	len = 0;
	digit = 0;
	symbol = (char)va_arg(ap, int);
	if (hole->width && hole->minus == 0)
	{
		digit = hole->width - 1;
		if (hole->zero == 0)
		{
			while (digit-- > 0)
			{
				write(1, " ", 1);
				len++;
			}
		}
		else if (hole->zero != 0)
		{
			while (digit-- > 0)
			{
				write(1, "0", 1);
				len++;
			}
		}
		write(1, &symbol, 1);
		len++;
	}
	else if (hole->width && hole->minus == 1)
	{
		digit = hole->width - 1;
		write(1, &symbol, 1);
		len++;
		while (digit-- > 0)
		{
			write(1, " ", 1);
			len++;
		}
	}
	else
	{
		write(1, &symbol, 1);
		len++;
	}
//	return (len);
return (hole->width > 0 ? hole->width : 1);
}
