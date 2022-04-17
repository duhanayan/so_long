CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
RM = rm -f
HDR = ./ft_printf.h
SRCS = ft_printf.c utils.c ft_printhexa.c ft_printp.c utils2.c

OBJS		= 	$(SRCS:.c=.o)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

all:	$(NAME)

%.o: %.c $(HDR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) *.out

fclean:	clean
		$(RM) $(NAME)

re:		fclean all

.PHONY: all clean re fclean
