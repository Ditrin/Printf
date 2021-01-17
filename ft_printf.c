/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdanette <cdanette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 02:00:19 by cdanette          #+#    #+#             */
/*   Updated: 2021/01/18 01:56:14 by cdanette         ###   ########.fr       */
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
	hole.wight = 0;
	hole.pers = -1;
	return(hole);
}

void ft_type(char *str, va_list ap, t_hole hole)
{
	char *specif;

	specif = "cspdiuxX%";
	while (ft_strchr(specif, *str))
	{
		if (*str == 'c' && str++)
			ft_putchar_fd(va_arg(ap, int), 1);
		else if (*str == 's')
			ft_putstr_fd(va_arg(ap, char *), 1);
		else if (*str == 'p')
		//написать функцию на вывод адреса
			ft_putnbr_fd(va_arg(ap, size_t), 1);
		else if (*str == 'd' || *str == 'i')
			ft_putnbr_fd(va_arg(ap, int), 1);
		else if (*str == 'u')
			ft_putnbr_fd(va_arg(ap, unsigned int), 1); //редить функцию
		else if (*str == 'x')
			ft_putxnbr_fd(va_arg(ap, unsigned int), 1); //редить функцию
		else if (*str == 'X')
			ft_putnbr_fd(va_arg(ap, unsigned int), 1); //редить функцию
		else if (*str == '%')
			ft_putchar_fd('%', 1);
	}
}

void ft_parser(char *str, va_list ap, t_hole hole)
{
	while (*str == '-' || *str == '.' || *str == '*' || ft_isdigit(*str))
	{
		if (*str == '-' && str++)
			hole.minus = 1;
		else if (*str == '0' && str++)
			hole.zero = 1;
		else if (ft_isdigit(*str))
		{
			hole.wight = ft_atoi(str);
			while (ft_isdigit(*str))
				str++;
		}
		else if (*str == '*' && str++)
			hole.wight = va_arg(ap, int);
		else if (*str == '.' && *(str + 1) == '*' && (str += 2))
			hole.pers = va_arg(ap, int);
		else if (*str == '.' && str++)
		{
			hole.pers = ft_atoi(str);
			while (ft_isdigit(*str))
				str++;
		}
	}
	ft_type(str, ap, hole);
}

int	ft_printf(char *str, ...)
{
	va_list	ap;
	t_hole	hole;
	int		nbr;

	va_start(ap, str);
	if (!str)
		return (-1);
	while (*str != '\0')
	{
		if (*str && *str != '%')
		{
			write(1, &*str, 1);
			nbr += 1;
		}
		else if (*str && *str == '%')
		{
			str++;
			hole = init_hole(hole);
			if (*str)
				ft_parser(str, ap, hole);
		}
		str += 1;
	}
	va_end(ap);
	return (nbr);
}


int	main()
{
	char *s;
	// int slong;

	s = "dlfskdf";
	// slong = -2147483648;
	// ft_printf("my own: %d", s);
	// printf("%zu\n", ft_strlen(s));
	// printf("not: %.*s\n", -10, NULL);
	printf("|%015.3s|\n", "Hello");
	//ft_printf("not: %c\n", 'a');
	// printf("not: %d\n", slong);
	// printf("Not mine: %20d|%20d|\n", slong, slong);
	//  printf("Not mine: %1.0u| %5.u| %0u| %u|\n", 0, 0, 0, 0);
	//ft_putxnbr_fd(255, 1);

	return (0);
}

