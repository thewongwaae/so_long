NAME		= so_long
CC			= gcc
RM 			= rm -rf
CFLAGS		= -Wall -Wextra -Werror -fsanitize=address -g3 -I includes/

GAME		= main
UTILS		= gnl strings

SRCS 		= $(addsuffix .c, $(addprefix src/game/, $(GAME))) \
				$(addsuffix .c, $(addprefix src/utils/, $(UTILS))) \

OBJS = $(SRCS:c=o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\n"
	@echo "\033[0;32;1mCompiling so_long..."
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "\n\033[0mDone !"

%.o: %.c
	@printf "\033[0;33;1mGenerating so_long objects... %-33.33s\r" $@
	@${CC} ${CFLAGS} -c $< -o $@

clean:
	@echo "\033[38;5;160;1m\nRemoving objects..."
	@$(RM) $(OBJS)
	@echo "\033[0m"

fclean: clean
	@echo "\033[38;5;196;1m\nDeleting so_long..."
	@$(RM) $(NAME)
	@echo "\033[0m"

test: re
	make clean