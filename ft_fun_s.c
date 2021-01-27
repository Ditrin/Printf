/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fun_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdanette <cdanette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 05:53:53 by cdanette          #+#    #+#             */
/*   Updated: 2021/01/27 00:28:19 by cdanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putnchar(char c, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		write(1, &c, 1);
		i++;
	}
	return (i);
}

int		ft_fun_s(va_list ap, t_hole hole)
{
	char	*str;
	int		len;
	int		i;

	str = va_arg(ap, char *);
	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	len = (hole.prec >= 0 && hole.prec < len ? hole.prec : len);
	i = (!hole.minus ? ft_putnchar(' ', hole.width - len) : 0);
	i += write(1, str, len);
	i += (hole.minus ? ft_putnchar(' ', hole.width - len) : 0);
	return (i);
}
