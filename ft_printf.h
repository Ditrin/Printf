/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdanette <cdanette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 01:53:25 by cdanette          #+#    #+#             */
/*   Updated: 2021/01/27 00:22:13 by cdanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct	s_hole
{
	int minus;
	int zero;
	int width;
	int prec;
}				t_hole;

int				ft_printf(char *str, ...);
int				ft_fun_c(int symbol, t_hole *hole, int len);
int				ft_fun_d(int n, t_hole hole);
int				ft_fun_s(va_list ap, t_hole hole);
int				ft_fun_p(unsigned long long n, t_hole hole);
int				ft_fun_u(unsigned int i, t_hole hole);
int				ft_fun_x(unsigned int n, t_hole hole, char c, int count);
int				ft_putnchar(char c, int n);
t_hole			side_hole(t_hole hole);

#endif
