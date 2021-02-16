CC =			gcc

FLAGS =			-Wall -Wextra -Werror

RM =			rm -rf

DIR_HEADERS =	./includes/

DIR_SRCS =		./srcs/

DIR_OBJS =		./

LIBMLX =		libmlx.dylib \
				libmlx.a\
				libft.a

SAVE =			-fsanitize=address

SRC =			MiniRT.c \
				Construct.c\
				vect_math.c

SRCS =			$(addprefix $(DIR_SRCS), $(SRC))

COMPIL =		$(FLAGS) $(SAVE)

OBJS =			$(SRCS:.c=.o)

NAME =			miniRT

all:			$(NAME)

$(NAME) :		$(OBJS)
				@make -C ./minilibx_mms
				@make -C ./minilibx_opengl
				@make -C ./Libft
				@cp ./minilibx_mms/libmlx.dylib libmlx.dylib
				@cp ./minilibx_opengl/libmlx.a libmlx.a
				@cp ./Libft/libft.a libft.a
				$(CC) $(COMPIL) -I $(DIR_HEADERS) $(LIBMLX) -framework MetalKit $(OBJS) -o $(NAME)

%.o: %.c
				@gcc $(FLAGS) -I $(DIR_HEADERS) -c $< -o $@
				@echo "Compiled "$<" successfully!"

bonus:

norme:
				norminette $(DIR_SRCS)
				norminette $(DIR_HEADERS)

clean:
				$(RM) $(OBJS)

fclean:			clean
				@make clean -C ./minilibx_mms
				@make clean -C ./minilibx_opengl
				$(RM) libmlx.dylib
				$(RM) libmlx.a
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all, clean, fclean, re, bonus
