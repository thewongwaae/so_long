NAME		= so_long
CC			= gcc
RM 			= rm -rf
CFLAGS		= -Wall -Wextra -Werror -fsanitize=address -g3 
MLX			= -Lmlx -lmlx -framework OpenGL -framework AppKit
MLXA		= mlx/libmlx.a
INCLUDES	= -I includes

GAME		= main move render
UTILS		= check_av check_objs checks gnl itoa split strings

SRCS 		= $(addsuffix .c, $(addprefix srcs/game/, $(GAME))) \
				$(addsuffix .c, $(addprefix srcs/utils/, $(UTILS))) \

OBJS = $(SRCS:c=o)

%.o: %.c
	@printf "\033[0;33;1mGenerating so_long objects... %-33.33s\r" $@
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(NAME): $(OBJS)
	@echo "\n"
	@echo "\033[0;32;1mCompiling so_long..."
	@$(CC) $(CFLAGS) $(MLXA) $(MLX) $(OBJS) -o $(NAME)
	@echo "\n\033[0mDone !"

all: $(NAME)

clean:
	@echo "\033[38;5;160;1m\nRemoving objects..."
	@$(RM) $(OBJS)
	@echo "\033[0m"

fclean: clean
	@echo "\033[38;5;196;1m\nDeleting so_long..."
	@$(RM) $(NAME)
	@echo "\033[0m"

re: fclean all

test: re
	make clean