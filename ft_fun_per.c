#include "libft/libft.h"
#include "ft_printf.h"
#include <stdarg.h>

int		ft_fun_per(t_hole hole)
{
	int count;
	int i;

	i = 0;
	count = 0;
	if(!hole.width)
		count += write(1, "%", 1);
	if(hole.width)
	{
		if(hole.minus)
			count += write(1, "%", 1);
		while(hole.width - 1 > i)
		{
			if (hole.minus == 1)
				count += write(1, " ", 1);
			else if (hole.zero == 1)
				count += write(1, "0", 1);
			else
				count += write(1, " ", 1);
			i++;
		}
		if(!hole.minus)
			count += write(1, "%", 1);
	}

	return(count);
}