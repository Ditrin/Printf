/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fun_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdanette <cdanette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 00:46:12 by cdanette          #+#    #+#             */
/*   Updated: 2021/01/19 05:24:54 by cdanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>

void	ft_fun_c(t_hole *hole, va_list ap)
{
	char symbol;
	int digit;

	digit = 0;
	symbol = (char)va_arg(ap, int);
	if (hole->width && hole->minus == 0)
	{
		digit = hole->width - 1;
		while (digit--  > 0)
		{
			write(1, " ", 1);
		}
		write(1, &symbol, 1);
	}
	else if (hole->width && hole->minus == 1)
	{
		digit = hole->width - 1;
		write(1, &symbol, 1);
		while (digit--  > 0)
		{
			write(1, " ", 1);
		}
	}
	else
		write(1, &symbol, 1);
}
