#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>

char	*ft_zero(char *str, t_hole hole, int len)
{
	char *new_str;
	int i;

	i = 0;
	if(!(new_str = ft_calloc(sizeof(char), hole.prec + 1)))
		return (NULL);
	if (str[i] == '-' && len--)
		new_str[i++] = '-';
	ft_memset(new_str + i, '0', hole.prec - len);
	ft_memcpy(new_str + ft_strlen(new_str), str, len);
	free(str);
	return (new_str);
}

char	*ft_space(char *str, t_hole hole, int len)
{
	char *new_str;
	//int i;

	//i = 0;
	if(!(new_str = ft_calloc(sizeof(char), hole.width + 1)))
		return (NULL);
	if (hole.minus > 0)
	{
		//new_str[i++] = '-';
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
	int		count;

	count = 0;
	number = ft_itoa(n);
	len = ft_strlen(number);
	if (hole.prec > len)
		number = ft_zero(number, hole, len);
	len = ft_strlen(number);
	if(hole.width > len)
		number = ft_space(number, hole, len);

//
//	if (hole.width)
//		hole.width++;
	write(1, number, ft_strlen(number));
	free(number);
	return (hole.width > len ? hole.width : len);
}

