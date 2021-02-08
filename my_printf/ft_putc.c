#include "ft_printf.h"

int		ft_putc(int i, t_flags *elements)
{
	int		count;

	count = 0;
	count = elements->width;
	if (elements->width == 0)
	{
		count = 1;
		ft_putchar(i);
	}
	else if (elements->minus)
	{
		ft_putchar(i);
		ft_putspace(count - 1);
	}
	else if (elements->zero)
	{
		ft_putzero(count - 1);
		ft_putchar(i);
	}
	else
	{
		ft_putspace(count - 1);
		ft_putchar(i);
	}
	return (count);
}
