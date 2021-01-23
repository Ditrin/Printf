#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>

int	ft_fun_s(char *str, t_hole hole)
{
	char *symbol;
	int len;

	len= 0;
	if (!str)
		return (0);
	len = ft_strlen(str);
	if(hole.prec >= 0 && hole.prec > len )
		hole.prec = len;
	if (hole.minus == 1)
	{
		if(hole.prec >= 0)
			hole.width + len

	}
	if else()

	return (len);
}
