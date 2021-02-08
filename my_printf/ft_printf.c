#include "ft_printf.h"

int		ft_check_format(t_flags *elements, const char **format, va_list args)
{
	int			count;

	count = 0;
	if (**format == '\0')
		return (0);
	ft_check_flag(elements, format);
	if (**format == '\0')
		return (0);
	ft_check_width(elements, format, args);
	if (**format == '\0')
		return (0);
	ft_check_precision(elements, format, args);
	if (**format == '\0')
		return (0);
	count = ft_check_alpha(elements, format, args);
	*format += 1;
	return (count);
}

int		ft_printf(const char *format, ...)
{
	va_list		args;
	t_flags		elements;
	int			count;

	va_start(args, format);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			ft_struct_init(&elements);
			count += ft_check_format(&elements, &format, args);
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
