#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

# define MIN(a, b) ((a) < (b) ? (a) : (b))
# define MAX(a, b) ((a) < (b) ? (b) : (a))

typedef struct {
	int				zero;
	int				minus;
	int				width;
	int				precision;
	int				preswitch;
	int				sign;
}					t_flags;

int					ft_printf(const char *format, ...);
void				ft_struct_init(t_flags *elements);
void				ft_check_flag (t_flags *elements, const char **format);
void				ft_check_width (t_flags *elements,
									const char **format, va_list args);
void				ft_check_precision(t_flags *elements,
									const char **format, va_list args);
void				ft_check_precision2(t_flags *elements,
									const char **format, int nb);
int					ft_check_alpha(t_flags *e, const char **format,
									va_list args);
int					ft_putc(int i, t_flags *elements);
int					ft_puts(char *str, t_flags *elements);
void				ft_puts2(char *str, t_flags *elements,
									int count, int width);
int					ft_putnbr(int nb, t_flags *elements);
int					ft_putnbr_u(unsigned int nb, t_flags *elements);
int					ft_putnbr_smallx(unsigned int nb, t_flags *elements);
int					ft_putnbr_largex(unsigned int nb, t_flags *elements);
int					ft_putptr(void *ptr, t_flags *elements);
int					ft_putpercent(t_flags *elements);
void				str_null_check(char *str);
void				ft_putchar(char c);
int					ft_strlen(char *s);
void				ft_putspace(int i);
void				ft_putzero(int i);
void				ft_putstr(char *str, int count);
unsigned int		ft_check_sign(unsigned long num, t_flags *elements);
void				ft_put0x(void);
int					ft_numlen(long num);
void				ft_putoutnbr(long num, int sign, int precision);
void				ft_putnumpre(long num, t_flags *elements, int count);
void				ft_putnumnopre(long num, t_flags *elements, int count);
int					ft_numlen_u(unsigned int num);
void				ft_putoutnbr_u(unsigned int num, int sign, int precision);
void				ft_putnumpre_u(unsigned int num,
									t_flags *elements, int count);
void				ft_putnumnopre_u(long num, t_flags *elements, int count);
int					ft_putnbr_u(unsigned int nb, t_flags *elements);
int					ft_numlen_x(unsigned long num);
void				ft_putoutnbr_x(unsigned long num, int sign, int precision);
void				ft_putnumpre_x(unsigned int num,
									t_flags *elements, int count);
void				ft_putnumnopre_x(unsigned int num,
									t_flags *elements, int count);
int					ft_numlen_lx(unsigned int num);
void				ft_putoutnbr_lx(unsigned int num, int sign, int precision);
void				ft_putnumpre_lx(unsigned int num,
									t_flags *elements, int count);
void				ft_putnumnopre_lx(unsigned int num,
									t_flags *elements, int count);
int					ft_putnbr_smallx(unsigned int nb, t_flags *elements);
void				ft_putnumpre_p(unsigned long num,
									t_flags *elements, int count);
void				ft_putnumpre_p2(unsigned long num, t_flags *elements,
						int width, int precision);
void				ft_putnumnopre_p(unsigned long num,
						t_flags *elements, int count);
int					ft_putnbr_smallx_p(unsigned long nb, t_flags *elements);
int					ft_putptr(void *ptr, t_flags *elements);

#endif
