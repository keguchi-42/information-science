#include "ft_printf.h"

int		ft_putpercent(t_flags *elements)
{
	int		width;

	width = 1;
	if (elements->width)
		width = elements->width;
	if (elements->minus)
	{
		ft_putchar('%');
		ft_putspace(width - 1);
	}
	else if (elements->zero)
	{
		ft_putzero(width - 1);
		ft_putchar('%');
	}
	else
	{
		ft_putspace(width - 1);
		ft_putchar('%');
	}
	return (width);
}
