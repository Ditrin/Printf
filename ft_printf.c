/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdanette <cdanette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 02:00:19 by cdanette          #+#    #+#             */
/*   Updated: 2021/01/27 00:29:20 by cdanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_hole	init_hole(t_hole hole)
{
	hole.minus = 0;
	hole.zero = 0;
	hole.width = 0;
	hole.prec = -1;
	return (hole);
}

t_hole	side_hole(t_hole hole)
{
	if (hole.width < 0 && (hole.minus = 1))
		hole.width *= -1;
	if (hole.minus || hole.prec >= 0)
		hole.zero = 0;
	return (hole);
}

int		ft_type(char **str, va_list ap, t_hole hole)
{
	int		count;

	count = 0;
	if (ft_strchr("cspdiuxX%", **str))
	{
		if ((**str == 'c') && ++*str)
			count = ft_fun_c(va_arg(ap, int), &hole, 0);
		else if (**str == 's' && ++*str)
			count = ft_fun_s(ap, hole);
		else if (**str == 'p' && ++*str)
			count = ft_fun_p((unsigned long long)va_arg(ap, void *), hole);
		else if ((**str == 'd' || **str == 'i') && ++*str)
			count = ft_fun_d(va_arg(ap, int), hole);
		else if (**str == 'u' && ++*str)
			count = ft_fun_u((unsigned int)va_arg(ap, unsigned int), hole);
		else if (**str == 'x' || **str == 'X')
		{
			count = ft_fun_x(va_arg(ap, unsigned int), hole, **str, 0);
			++*str;
		}
		else if (**str == '%' && ++*str)
			count = ft_fun_c('%', &hole, 0);
	}
	return (count);
}

int		ft_parser(char **str, va_list ap, t_hole hole)
{
	while (**str == '-' || **str == '.' || **str == '*' || ft_isdigit(**str))
	{
		if (**str == '-' && (*str)++)
			hole.minus = 1;
		else if (**str == '0' && (*str)++)
			hole.zero = 1;
		else if (ft_isdigit(**str))
		{
			hole.width = ft_atoi(*str);
			while (ft_isdigit(**str))
				(*str)++;
		}
		else if (**str == '*' && (*str)++)
			hole.width = va_arg(ap, int);
		else if (**str == '.' && *(*str + 1) == '*' && *(*str += 2))
			hole.prec = va_arg(ap, int);
		else if (**str == '.' && ++(*str))
		{
			hole.prec = ft_atoi(*str);
			while (ft_isdigit(**str))
				(*str)++;
		}
	}
	return (ft_type(str, ap, side_hole(hole)));
}

int		ft_printf(char *str, ...)
{
	va_list	ap;
	t_hole	hole;
	int		nbr;

	nbr = 0;
	va_start(ap, str);
	if (!str)
		return (-1);
	while (*str != '\0')
	{
		if (*str == '%' && ++str)
		{
			hole = init_hole(hole);
			if (*str)
				nbr += ft_parser(&str, ap, hole);
		}
		else if (*str && *str != '%')
		{
			nbr += write(1, &*str, 1);
			str += 1;
		}
	}
	va_end(ap);
	return (nbr);
}
