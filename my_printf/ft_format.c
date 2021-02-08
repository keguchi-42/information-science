#include "ft_printf.h"

void	ft_check_precision2(t_flags *elements,
			const char **format, int nb)
{
	if (**format == '-')
	{
		elements->preswitch = 0;
		elements->precision = -1;
		while ((**format >= '0' && **format <= '9') || **format == '-')
			*format += 1;
		return ;
	}
	while (**format == 0)
		*format += 1;
	while (**format >= '0' && **format <= '9')
	{
		nb = nb * 10 + (**format - '0');
		*format += 1;
	}
	elements->precision = nb;
}

void	ft_check_flag(t_flags *elements, const char **format)
{
	while (**format == '0' || **format == '-')
	{
		if (**format == '0' && elements->zero == 0)
			elements->zero = 1;
		if (**format == '-' && elements->minus == 0)
			elements->minus = 1;
		*format += 1;
	}
}

void	ft_check_width(t_flags *elements, const char **format, va_list args)
{
	int	nb;

	nb = 0;
	if (**format == '*')
	{
		nb = va_arg(args, int);
		if (nb < 0)
		{
			elements->minus = 1;
			nb *= -1;
		}
		elements->width = nb;
		*format += 1;
	}
	else
	{
		while (**format >= '0' && **format <= '9')
		{
			nb = nb * 10 + (**format - '0');
			*format += 1;
		}
		elements->width = nb;
	}
}

void	ft_check_precision(t_flags *elements, const char **format, va_list args)
{
	int nb;

	nb = 0;
	if (**format == '.')
	{
		elements->preswitch = 1;
		*format += 1;
		if (**format == '*')
		{
			nb = va_arg(args, int);
			elements->precision = nb;
			if (nb < 0)
			{
				elements->precision = -1;
				elements->preswitch = 0;
			}
			*format += 1;
		}
		else if ((**format >= '0' && **format <= '9') || **format == '-')
			ft_check_precision2(elements, format, nb);
		else
			elements->precision = 0;
	}
}

int		ft_check_alpha(t_flags *e, const char **format, va_list args)
{
	if (**format == 'c')
		return (ft_putc((va_arg(args, int)), e));
	else if (**format == 's')
		return (ft_puts((va_arg(args, char *)), e));
	else if (**format == 'p')
		return (ft_putptr(((void *)va_arg(args, unsigned long)), e));
	else if (**format == 'd' || **format == 'i')
		return (ft_putnbr((va_arg(args, int)), e));
	else if (**format == 'u')
		return (ft_putnbr_u((va_arg(args, unsigned int)), e));
	else if (**format == 'x')
		return (ft_putnbr_smallx((va_arg(args, unsigned long)), e));
	else if (**format == 'X')
		return (ft_putnbr_largex((va_arg(args, unsigned int)), e));
	else if (**format == '%')
		return (ft_putpercent(e));
	return (0);
}
