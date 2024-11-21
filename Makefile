NAME = cub3d

CC = cc
CFLAGS += -Wall -Wextra -Werror --std=c99 -g
#CFLAGS += -fsanitize=address
MINILIBX = -L minilibx-linux -lmlx -lXext -lX11
LIBS = -lm
FILES = src/*.c
OBJS = obj/*.o
RM = rm -fr
MINILIBX_FOLDER = minilibx-linux

all: $(NAME)

test: $(NAME)
	./$(NAME) maps/subject.cub

$(NAME): $(MINILIBX_FOLDER) $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) $(MINILIBX) $(LIBS) -o $(NAME)

$(MINILIBX_FOLDER):
	@wget https://cdn.intra.42.fr/document/document/25858/minilibx-linux.tgz > /dev/null 2>&1
	@tar -xvf minilibx-linux.tgz > /dev/null 2>&1
	@rm minilibx-linux.tgz > /dev/null 2>&1

$(OBJS): $(FILES)
	@make -sC minilibx-linux -s > /dev/null 2>&1
	@mkdir -p obj
	@$(CC) $(CFLAGS) -c $(FILES)
	@mv *.o obj/

clean:
	@$(RM) $(OBJS) obj
	@make clean -sC minilibx-linux

fclean:
	@$(RM) $(OBJS) $(NAME) obj $(MINILIBX_FOLDER)

re: fclean all

.PHONY: all clean fclean re test
