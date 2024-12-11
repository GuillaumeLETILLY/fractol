NAME = fractol
CC = cc
RM = rm -f
CLONE = git clone --depth=1
CFLAGS = -Wall -Wextra -Werror -O3
MLXFLAGS = -L$(MLX) -lmlx -L/usr/lib -lXext -lX11
CLINKS = -lm
MLX = minilibx
LIBMLX = $(MLX)/libmlx.a
PRINTF = printf
LIBPRINTF = $(PRINTF)/libftprintf.a

SRC = main.c \
	utils.c \
	atof.c \
	colorpixel.c \
	exitfractal.c \
	mousehook.c \
	keypress.c \
	strncmp.c \
	burning.c 

OBJ = $(SRC:.c=.o)
INC = -I $(MLX) -I $(PRINTF)

all: $(NAME)

$(NAME): $(LIBMLX) $(LIBPRINTF) $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(MLXFLAGS) $(CLINKS) -L$(PRINTF) -lftprintf

$(LIBMLX):
	@if [ ! -d "$(MLX)" ]; then \
		$(CLONE) https://github.com/42Paris/minilibx-linux.git $(MLX); \
	fi
	$(MAKE) -C $(MLX)

$(LIBPRINTF):
	@if [ ! -d "$(PRINTF)" ]; then \
		$(CLONE) https://github.com/GuillaumeLETILLY/printf.git $(PRINTF); \
	fi
	$(MAKE) -C $(PRINTF)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	$(RM) $(OBJ)
	@if [ -d "$(MLX)" ]; then \
		$(MAKE) clean -C $(MLX); \
	fi
	@if [ -d "$(PRINTF)" ]; then \
		$(MAKE) clean -C $(PRINTF); \
	fi

fclean: clean
	$(RM) $(LIBMLX)
	$(RM) $(LIBPRINTF)
	$(RM) $(NAME)
	$(RM) -rf $(MLX)
	$(RM) -rf $(PRINTF)

re: fclean all

.PHONY: all clean fclean re