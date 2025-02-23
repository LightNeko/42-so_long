NAME = so_long
BNAME = so_long_bonus

CC = gcc
CFLAGS = -I/usr/include -Imlx_linux -O3 -g -Werror -Wextra -Wall 

SRC_DIR = src
SRCS = main.c map.c checks.c player.c keys.c hooks.c img.c draw.c items.c exit.c movement.c error.c bfs.c free.c

BSRC_DIR = bonus
BSRCS = main.c map.c checks.c player.c keys.c hooks.c img.c draw.c items.c exit.c movement.c error.c bfs.c free.c digits.c ui.c enemy.c enemy_movement.c

OBJS = $(addprefix $(SRC_DIR)/, $(SRCS:.c=.o))
BOBJS = $(addprefix $(BSRC_DIR)/, $(BSRCS:.c=.o))

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

INCLUDES = -I $(LIBFT_DIR)/includes -I includes

all: $(NAME)

bonus: $(BNAME)

$(BNAME) : $(BOBJS) $(LIBFT)
	$(CC) $(BOBJS) $(LIBFT) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(BNAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(OBJS) $(LIBFT) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS) $(BOBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) $(BNAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus
