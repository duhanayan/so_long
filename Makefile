CC = gcc
KOMUT = -Imlx -framework OpenGL -framework Appkit
NAME = so_long.a
OUT = so_long
LIBFTMAKER = libftmaker
MLXMAKER = mlxmaker
FT_PRINTFMAKER = ft_printfmaker
HDR = so_long.h
SRC = so_long.c utils.c utils2.c put_images.c checkMap.c moves.c animation.c
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

all: $(LIBFTMAKER) $(MLXMAKER) $(FT_PRINTFMAKER) $(OUT)

$(OUT): $(NAME)
	$(CC) $(CFLAGS) $(KOMUT) libft/libft.a mlx/libmlx.a ft_printf/libftprintf.a $(NAME) -o $(OUT)

$(NAME): $(OBJ)
		ar rcs $(NAME) $(OBJ)

$(LIBFTMAKER):
		@cd libft && $(MAKE)

$(MLXMAKER):
		@cd mlx && $(MAKE)

$(FT_PRINTFMAKER):
		@cd ft_printf && $(MAKE)

clean:
	$(RM) so_long
	$(RM) $(OBJ)
	cd libft && $(MAKE) clean
	cd ft_printf && $(MAKE) clean
	cd mlx && $(MAKE) clean
	echo cleaned

fclean: clean
	$(RM) $(NAME)
	$(RM) libft/libft.a
	$(RM) mlx/libmlx.a
	$(RM) ft_printf/libftprintf.a
	echo fcleaned

re: fclean all

.PHONY: all clean fclean re
