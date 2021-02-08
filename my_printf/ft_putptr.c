#include "ft_printf.h"

void	ft_putnumpre_p2(unsigned long num, t_flags *elements,
						int width, int precision)
{
	if (elements->minus)
	{
		ft_put0x();
		ft_putoutnbr_x(num, elements->sign, precision);
		ft_putspace(width);
	}
	else if (elements->zero)
	{
		if (elements->sign == -1)
			ft_putchar('-');
		ft_put0x();
		ft_putzero(width);
		ft_putoutnbr_x(num, 1, precision);
	}
	else
	{
		ft_putspace(width);
		ft_put0x();
		ft_putoutnbr_x(num, elements->sign, precision);
	}
}

void	ft_putnumpre_p(unsigned long num, t_flags *elements, int count)
{
	int		width;
	int		precision;

	width = 0;
	precision = 0;
	width = MAX(elements->width, count);
	precision = elements->precision;
	precision -= count;
	width = width - precision - count + elements->sign;
	ft_putnumpre_p2(num, elements, width, precision);
}

void	ft_putnumnopre_p(unsigned long num, t_flags *elements, int count)
{
	int		width;

	width = 0;
	width = MAX(elements->width, count);
	if (elements->minus)
	{
		ft_put0x();
		ft_putoutnbr_x(num, elements->sign, -1);
		ft_putspace(width - count + elements->sign);
	}
	else if (elements->zero)
	{
		if (elements->sign == -1)
			ft_putchar('-');
		ft_put0x();
		ft_putzero(width - count + elements->sign);
		ft_putoutnbr_x(num, 1, -1);
	}
	else
	{
		ft_putspace(width - count + elements->sign);
		ft_put0x();
		ft_putoutnbr_x(num, elements->sign, -1);
	}
}

int		ft_putnbr_smallx_p(unsigned long nb, t_flags *elements)
{
	unsigned long	num;
	int				count;

	num = nb;
	count = 0;
	if (elements->precision == 0)
	{
		count = elements->width - 2;
		ft_putspace(count);
		ft_put0x();
		if (num == 0 && elements->width == 0)
			elements->width += 2;
		return (elements->width);
	}
	count = ft_numlen_x(num) + 2;
	if (elements->precision > count)
	{
		ft_putnumpre_p(num, elements, count - 2);
		count = elements->precision + 2;
	}
	else
		ft_putnumnopre_p(num, elements, count);
	return (MAX(count, elements->width));
}

int		ft_putptr(void *ptr, t_flags *elements)
{
	unsigned long	add;

	add = (unsigned long)ptr;
	return (ft_putnbr_smallx_p(add, elements));
}
