NAME 	= 	libftprintf.a
CC 		= 	gcc
CFLAGS 	= 	-Wall -Wextra -Werror
RM 		= 	rm -f

SRCS =		ft_format.c			\
			ft_printf.c			\
			ft_printf_utils.c	\
			ft_printf_utils2.c	\
			ft_putc.c			\
			ft_putnbr.c			\
			ft_putnbr_largex.c	\
			ft_putnbr_smallx.c	\
			ft_putnbr_u.c		\
			ft_putptr.c			\
			ft_putstr.c			\
			ft_putpercent.c		\

OBJS	=	$(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
	ar rcs $(NAME) $(OBJS)

clean:

	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
