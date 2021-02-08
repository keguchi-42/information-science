#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_putspace(int i)
{
	while (i > 0)
	{
		ft_putchar(' ');
		i--;
	}
}

void	ft_putzero(int i)
{
	while (i > 0)
	{
		ft_putchar('0');
		i--;
	}
}

void	ft_putstr(char *str, int count)
{
	int i;

	i = 0;
	while (count > i)
	{
		ft_putchar(str[i]);
		i++;
	}
}
