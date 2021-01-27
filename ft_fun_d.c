/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fun_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdanette <cdanette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 05:51:49 by cdanette          #+#    #+#             */
/*   Updated: 2021/01/27 00:28:29 by cdanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_zero(char *str, int len, int kk)
{
	char	*new_str;
	int		i;
	char	*tmp;

	i = 0;
	if (!(new_str = ft_calloc(sizeof(char), kk + 1)))
		return (NULL);
	tmp = str;
	if (str[i] == '-')
	{
		len--;
		str++;
		new_str[i++] = '-';
	}
	ft_memset(new_str + i, '0', kk - len);
	ft_strlcpy(new_str + ft_strlen(new_str), str, len + 1);
	free(tmp);
	return (new_str);
}

char	*ft_zero2(char *str, int len, int kk)
{
	char	*new_str;
	int		i;
	char	*tmp;

	i = 0;
	if (!(new_str = ft_calloc(sizeof(char), kk)))
		return (NULL);
	tmp = str;
	if (str[i] == '-')
	{
		len--;
		str++;
		new_str[i++] = '-';
	}
	ft_memset(new_str + i, '0', kk - len - i);
	ft_strlcpy(new_str + ft_strlen(new_str), str, len + 1);
	free(tmp);
	return (new_str);
}

char	*ft_space(char *str, t_hole hole, int len)
{
	char	*new_str;
	int		i;

	i = 0;
	if (!(new_str = ft_calloc(sizeof(char), hole.width + 1)))
		return (NULL);
	if (hole.minus)
	{
		ft_memset(new_str + len, ' ', hole.width - len);
		ft_memcpy(new_str, str, len);
	}
	else
	{
		ft_memset(new_str, ' ', hole.width - len);
		ft_memcpy(new_str + ft_strlen(new_str), str, len);
	}
	free(str);
	return (new_str);
}

int		ft_fun_d(int n, t_hole hole)
{
	char	*number;
	int		len;

	number = ft_itoa(n);
	len = (!hole.prec && !n ? 0 : ft_strlen(number));
	if (hole.prec == 0 && (ft_atoi(number) == 0 || hole.width > len))
		number = ft_space(number, hole, len);
	if (hole.prec >= len)
		number = ft_zero(number, len, hole.prec);
	len = ft_strlen(number);
	if (hole.width > len)
	{
		if (hole.prec == 0)
			number = ft_space(number, hole, len);
		else if (hole.zero > 0 && hole.prec < 0 && hole.minus > 0)
			return (-1);
		else if (hole.zero > 0 && hole.prec < 0)
			number = ft_zero2(number, len, hole.width);
		else
			number = ft_space(number, hole, len);
	}
	len = ft_strlen(number);
	write(1, number, len);
	free(number);
	return (len);
}
