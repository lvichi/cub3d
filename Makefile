NAME = parsing

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MINILIBX = -L minilibx-linux -lmlx -lXext -lX11
LIBS = -lm
FILES = src/*.c
OBJS = obj/*.o
RM = rm -fr

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(MINILIBX) $(LIBS) -o $(NAME)

$(OBJS): $(FILES)
	@make -sC minilibx-linux -s > /dev/null 2>&1
	@mkdir -p obj
	@$(CC) $(CFLAGS) -c $(FILES)
	@mv *.o obj/

clean:
	@$(RM) $(OBJS) obj
	@make clean -sC minilibx-linux

fclean:
	@$(RM) $(OBJS) $(NAME) obj
	@make clean -sC minilibx-linux

re: fclean all

.PHONY: all clean fclean re
