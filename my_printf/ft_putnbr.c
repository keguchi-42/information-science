#include "ft_printf.h"

int		ft_numlen(long num)
{
	int		count;

	count = 0;
	while (num >= 10)
	{
		count++;
		num /= 10;
	}
	return (count + 1);
}

void	ft_putoutnbr(long num, int sign, int precision)
{
	char c;

	if (sign == -1)
		ft_putchar('-');
	if (precision != -1)
		ft_putzero(precision);
	if (num >= 10)
		ft_putoutnbr(num / 10, 1, -1);
	c = num % 10 + '0';
	write(1, &c, 1);
}

void	ft_putnumpre(long num, t_flags *elements, int count)
{
	int		width;
	int		precision;

	width = 0;
	precision = 0;
	width = MAX(elements->width, count);
	precision = elements->precision;
	precision -= count;
	if (precision < 0)
		precision = 0;
	if (elements->minus)
	{
		ft_putoutnbr(num, elements->sign, precision);
		ft_putspace(width - precision - count + elements->sign);
	}
	else
	{
		ft_putspace(width - precision - count + elements->sign);
		ft_putoutnbr(num, elements->sign, precision);
	}
}

void	ft_putnumnopre(long num, t_flags *elements, int count)
{
	int		width;

	width = 0;
	width = MAX(elements->width, count);
	if (elements->minus)
	{
		ft_putoutnbr(num, elements->sign, -1);
		ft_putspace(width - count + elements->sign);
	}
	else if (elements->zero)
	{
		if (elements->sign == -1)
			ft_putchar('-');
		ft_putzero(width - count + elements->sign);
		ft_putoutnbr(num, 1, -1);
	}
	else
	{
		ft_putspace(width - count + elements->sign);
		ft_putoutnbr(num, elements->sign, -1);
	}
}

int		ft_putnbr(int nb, t_flags *elements)
{
	long	num;
	int		count;

	num = (long)nb;
	count = 0;
	if (num == 0 && elements->precision == 0)
	{
		ft_putspace(elements->width);
		return (elements->width);
	}
	if (num < 0)
		num = ft_check_sign(num, elements);
	count = ft_numlen(num);
	if (elements->preswitch == 1)
		ft_putnumpre(num, elements, count);
	else
		ft_putnumnopre(num, elements, count);
	if (elements->sign == -1)
	{
		count += 1;
		elements->precision += 1;
	}
	return (MAX(elements->precision, MAX(count, elements->width)));
}
