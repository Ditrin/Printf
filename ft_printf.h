/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdanette <cdanette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/16 01:53:25 by cdanette          #+#    #+#             */
/*   Updated: 2021/01/19 03:20:07 by cdanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <ntsid.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "libft/libft.h"


typedef struct	s_hole
{
	int trash;
	int minus;
	int zero;
	int width;
	int prec;
}				t_hole;

int		ft_printf(char *str, ...);
int		ft_fun_c(t_hole *hole, va_list ap);
int		ft_fun_d(int n, t_hole hole);
int		ft_fun_s(char *str, t_hole hole);
int		ft_fun_p(unsigned long long n, t_hole hole);




#endif
