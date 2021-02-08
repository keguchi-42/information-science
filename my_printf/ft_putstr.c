#include "ft_printf.h"

void	ft_puts2(char *str, t_flags *elements, int count, int width)
{
	if (elements->minus)
	{
		ft_putstr(str, count);
		ft_putspace(width - count);
	}
	else if (elements->zero)
	{
		ft_putzero(width - count);
		ft_putstr(str, count);
	}
	else
	{
		ft_putspace(width - count);
		ft_putstr(str, count);
	}
}

int		ft_puts(char *str, t_flags *elements)
{
	int count;
	int width;

	count = 0;
	width = 0;
	if (str == NULL)
		str = "(null)";
	if (elements->width == INT_MAX)
		return (-1);
	count = ft_strlen(str);
	if (elements->precision == 0)
	{
		ft_putspace(elements->width);
		return (elements->width);
	}
	if (elements->precision < 0)
		elements->precision = 0;
	if (elements->precision > 0 && elements->precision < count)
		count = elements->precision;
	width = MAX(elements->width, count);
	ft_puts2(str, elements, count, width);
	return (width);
}
