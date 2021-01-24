/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdanette <cdanette@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/11 21:52:58 by cdanette          #+#    #+#             */
/*   Updated: 2020/12/20 00:26:42 by cdanette         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(const char *str, char ch)
{
	size_t	size;

	size = 0;
	while (*str)
	{
		while (*str == ch && *str)
			str++;
		if (*str)
			size++;
		while (*str != ch && *str)
			str++;
	}
	return (size);
}

static size_t	ft_num_string(char const *s, char ch, unsigned int *p)
{
	size_t	i;

	i = 0;
	while (*s == ch)
	{
		s++;
		(*p)++;
	}
	while (*s && *s != ch)
	{
		i++;
		s++;
	}
	return (i);
}

static void		*ft_free(char **mas, size_t i)
{
	while (i)
		free(mas[i--]);
	free(mas);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	char			**mas;
	size_t			i;
	unsigned int	p;
	size_t			num;
	size_t			nums;

	i = 0;
	if (!s)
		return (NULL);
	num = ft_count_words(s, c);
	if (!(mas = malloc(sizeof(char *) * (num + 1))))
		return (NULL);
	while (num)
	{
		p = 0;
		nums = ft_num_string(s, c, &p);
		if (!(mas[i] = ft_substr(s, p, nums)))
			return (ft_free(mas, i));
		s += p + nums;
		i++;
		num--;
	}
	mas[i] = 0;
	return (mas);
}
