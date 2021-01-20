#include <ntsid.h>
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

void	ft_fun_c(t_hole *hole, va_list ap);



#endif
