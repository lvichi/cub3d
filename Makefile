NAME = parsing

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
MINILIBX = -L minilibx-linux -lmlx -lXext -lX11
FILES = src/*.c
OBJS = obj/*.o
BONUS_FILES = src_bonus/*_bonus.c
BONUS_OBJS = obj_bonus/*_bonus.o
RM = rm -fr

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(MINILIBX) -o $(NAME)

$(OBJS): $(FILES)
	@make -C minilibx-linux -s
	@mkdir -p obj
	@$(CC) $(CFLAGS) -c $(FILES)
	@mv *.o obj/

clean:
	@$(RM) $(OBJS) obj obj_bonus
	@make clean -C minilibx-linux -s

fclean:
	@$(RM) $(OBJS) $(NAME) obj
	@make clean -C minilibx-linux -s

re: fclean all

.PHONY: all clean fclean re bonus