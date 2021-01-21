/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdanette <cdanette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 02:00:19 by cdanette          #+#    #+#             */
/*   Updated: 2021/01/19 05:21:59 by cdanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdio.h>
#include <stdarg.h>
#include <string.h>

void	ft_putxnbr_fd(unsigned int n, int fd)
{
	if (n >= 16)
		ft_putxnbr_fd(n / 16, fd);
	ft_putchar_fd(n % 16 + (n % 16 > 9 ? 'A' - 10 : '0'), fd);
}

t_hole	init_hole(t_hole hole)
{
	hole.minus = 0;
	hole.zero = 0;
	hole.width = 0;
	hole.prec = -1;
	return (hole);
}

int ft_type(char **str, va_list ap, t_hole hole)
{
	char	*specif;
	int		count;

	specif = "cspdiuxX%";
	count = 0;
	if (ft_strchr(specif, **str))
	{
		if ((**str == 'c') && ++*str)
			ft_fun_c(&hole, ap);
		else if (**str == 's')
			ft_putstr_fd(va_arg(ap, char *), 1);
		else if (**str == 'p')
		//написать функцию на вывод адреса
			ft_putnbr_fd(va_arg(ap, size_t), 1);
		else if ((**str == 'd' || **str == 'i') && ++*str)
			count = ft_fun_d(va_arg(ap, int), hole);
		else if (**str == 'u')
			ft_putnbr_fd(va_arg(ap, unsigned int), 1); //редить функцию
		else if (**str == 'x')
			ft_putxnbr_fd(va_arg(ap, unsigned int), 1); //редить функцию
		else if (**str == 'X')
			ft_putnbr_fd(va_arg(ap, unsigned int), 1); //редить функцию
		else if (**str == '%')
			ft_putchar_fd('%', 1);
	}
	return (count);
}

int ft_parser(char **str, va_list ap, t_hole hole)
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
	return (ft_type(str, ap, hole));
}

int	ft_printf(char *str, ...)
{
	va_list	ap;
	t_hole	hole;
	int		nbr;

	nbr = 0;
	va_start(ap, str);
	if (!str)
		return (-1);
	while (*str != '\0') // my = %.c\n
	{
		if (*str && *str == '%')
		{
			str++;
			hole = init_hole(hole);
			if (*str)
				nbr += ft_parser(&str, ap, hole);
		}

		else if (*str && *str != '%')
		{
			write(1, &*str, 1);
			nbr += 1;
			str += 1;
		}
		//str += 1;
	}
	va_end(ap);
	return (nbr);
}
