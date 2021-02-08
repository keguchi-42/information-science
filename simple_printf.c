#include <unistd.h>
#include <stdarg.h>

#define MAX(a, b) ((a) < (b)) ? (b) : (a)

typedef struct	s_flags
{
	int precision;
	int width;
	int pre_on;
	int sign;
}				t_flags;

void ft_struct_init(t_flags *ele)
{
	ele->precision = -1;
	ele->width = 0;
	ele->pre_on = 0;
	ele->sign = 0;
}

void ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putstr(char *str, int len)
{
	int i;
	
	i = 0;
	while (i < len)
	{
		ft_putchar(str[i]);
		i++;
	}
}

void ft_putspace(int i)
{
	while (i > 0)
	{
		ft_putchar(' ');
		i--;
	}
}
void ft_putzero(int i)
{
	while (i > 0)
	{
		ft_putchar('0');
		i--;
	}
}

int ft_strlen(char *str)
{
	int i;
	
	i = 0;
	while (str[i])
		i++;
	return (i);
}

int ft_numlen(unsigned long num, int base)
{
	int count;

	count = 0;
	while (num >= base)
	{
		num /= base;
		count++;
	}
	return (count + 1);
}

void ft_putnum(long num, int sign, int precision)
{
	char c;

	if (sign == -1)
		ft_putchar('-');
	if (precision > 0)
		ft_putzero(precision);
	if (num >= 10)
		ft_putnum(num / 10, 0, -1);
	c = num % 10 + '0';
	write(1, &c, 1);
}

void ft_putnum_x(unsigned long num, int sign, int precision)
{
	char c;

	if (sign == -1)
		ft_putchar('-');
	if (precision > 0)
		ft_putzero(precision);
	if (num >= 10)
		ft_putnum(num / 10, 0, -1);
	if (num % 16 < 10)
	{
		c = num % 16 + '0';
		write(1, &c, 1);
	}
	else
	{
		c = num % 16 + '0' + 39;
		write(1, &c, 1);
	}
}

int ft_puts(char *str, t_flags *ele)
{
	int count;

	if (str == NULL)
		str = "(null)";
	count = ft_strlen(str);
	if (ele->pre_on && ele->precision < count)
		count = ele->precision;
	ft_putspace(ele->width - count);
	ft_putstr(str, count);
	return MAX(ele->width, count);
}

int ft_putd(long num, t_flags *ele)
{
	int count;
	int width;
	int precision;

	if (num < 0)
	{
		ele->sign = -1;
		num *= -1;
	}
	count = ft_numlen(num, 10);
	width = MAX(ele->width, count);
	precision = ele->precision;
	if (ele->pre_on)
	{
		if (ele->precision <= 0)
		{
			ft_putspace(ele->width);
			return (ele->width);
		}
		precision -= count;
		if (precision < 0)
			precision = 0;
		ft_putspace(width - precision - count + ele->sign);
		ft_putnum(num, ele->sign, precision);
	}
	else
	{
		ft_putspace(width - count + ele->sign);
		ft_putnum(num, ele->sign, -1);
	}
	if (ele->sign == -1)
	{
		ele->precision++;
		count++;
	}
	return MAX(ele->width, MAX(ele->precision, count));
}

int ft_putx(unsigned long num, t_flags *ele)
{

	int count;
	int width;
	int precision;

	if (num < 0)
	{
		ele->sign = -1;
		num *= -1;
	}
	count = ft_numlen(num, 16);
	width = MAX(ele->width, count);
	precision = ele->precision;
	if (ele->pre_on)
	{
		if (ele->precision <= 0)
		{
			ft_putspace(ele->width);
			return (ele->width);
		}
		precision -= count;
		if (precision < 0)
			precision = 0;
		ft_putspace(width - precision - count + ele->sign);
		ft_putnum_x(num, ele->sign, precision);
	}
	else
	{
		ft_putspace(width - count + ele->sign);
		ft_putnum_x(num, ele->sign, -1);
	}
	if (ele->sign == -1)
	{
		ele->precision++;
		count++;
	}
	return MAX(ele->width, MAX(ele->precision, count));
}

int ft_format(t_flags *ele, const char **format, va_list args)
{
	int nb;

	nb = 0;
	while (**format >= '0' && **format <= '9')
	{
		nb = nb * 10 + (**format - '0');
		*format += 1;
	}
	ele->width = nb;
	nb = 0;
	if (**format == '.')
	{
		ele->pre_on = 1;
		*format += 1;
		while (**format >= '0' && **format <= '9')
		{
			nb = nb * 10 + (**format - '0');
			*format += 1;
		}
		ele->precision = nb;
	}
	if (**format == 's')
		return (ft_puts((va_arg(args, char *)), ele));
	else if (**format == 'd')
		return (ft_putd((va_arg(args, int)), ele));
	else if (**format == 'x')
		return (ft_putx((va_arg(args, unsigned long)), ele));
	return (0);
}

int ft_printf(const char *format, ...)
{
	va_list args;
	t_flags ele;
	int count;

	count = 0;
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			ft_struct_init(&ele);
			count += ft_format(&ele, &format, args);
			if (*format == '\0')
				break ;
			format++;
		}
		else
		{
			write(1, format, 1);
			format++;
			count++;
		}
	}
	va_end(args);
	return (count);
}
