/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fun_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdanette <cdanette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 05:53:31 by cdanette          #+#    #+#             */
/*   Updated: 2021/01/24 06:07:39 by cdanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>

//int		ft_putxnbr(int n, int fd)
//{
//	if (n >= 16)
//		(n / 16, fd);
//	ft_putchar_fd(n % 16 + (n % 16 > 9 ? 'A' - 10 : '0'), fd);
//	return (n);
//}
//

int		ft_left_side(mass, accuracy, i, str)
{
	int count;

	count = 0;
	count += write(1, "0x", 2);
	while(accuracy > 0)
	 {
	 	count+=write(1, "0", 1);
	 	accuracy--;
	 }
	count += write(1, &str, i);
	 while(mass > 0)
	 {
	 	count += write(1, " ", 1);
	 	mass--;
	 }
	 return (count);
}

int		ft_right_side(mass, accuracy, i, str)
{
	int count;

	count = 0;
	while(mass > 0)
	{
		count+=write(1, " ", 1);
		mass--;
	}
	count += write(1, "0x", 2);
	while(accuracy > 0)
	{
		count += write(1, "0", 1);
		accuracy--;
	}
	count += write(1, &str, i);
	return (count);
}

int		ft_fun_p(unsigned long long n, t_hole hole)
{
	int i ;
	int count;
	char *str;
	int accuracy;
	int mass;

	count = 0;
	i = 0;
	while(n / 16)
	{
		n = n / 16;
		i++;
	}
	i += 1;
	str = ft_itoa_base(n, 16);
	accuracy = hole.prec - i;
	mass = hole.width - i - 2;
	if(hole.prec && hole.prec == 0 && n==0)
		mass++;
	if(hole.prec && hole.prec == 0)
		i = 0;
	if(hole.minus)
		count = ft_left_side(mass, accuracy, i, *str);
	else
		count = ft_right_side(mass, accuracy, i, *str);
	free(str);
	return(count);
}
