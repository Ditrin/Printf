/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fun_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdanette <cdanette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 05:53:53 by cdanette          #+#    #+#             */
/*   Updated: 2021/01/24 05:54:35 by cdanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>

int	ft_fun_s(char *str, t_hole hole)
{
	char	abc;
	int		len;
	int		i;

	i = 0;
	len = 0;
	if (hole.zero == 1)
		abc = '0';
	else
		abc = ' ';
	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	if (hole.minus == 1)
	{
		abc = ' ';
		if (hole.prec != -1 && hole.prec < len)
			len = hole.prec;
		write(1, str, len);
		while ((hole.width - len) > 0)
		{
			write(1, &abc, 1);
			hole.width--;
			i++;
		}
	}
	else if (hole.minus == 0)
	{
		if (hole.prec != -1 && hole.prec < len)
			len = hole.prec;
		if (hole.width > len)
		{
			while ((hole.width - len) > 0)
			{
				write(1, &abc, 1);
				hole.width--;
				i++;
			}
		}
		write(1, str, len);
	}
	len += i;
	return (len);
}
