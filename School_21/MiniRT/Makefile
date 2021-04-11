#NAME			= 	miniRT
#
#SRCS_LIST		= 	miniRT.c\
#					construct.c\
#					vect_math.c\
#					utils.c\
#					ft_split.c\
#					get_next_line.c\
#					get_next_line_utils.c\
#					parse_obj.c\
#					hit_objects.c
#
#SRCS 			= $(addprefix $(FOLDER), $(SRCS_LIST))
#
#OBJS 			= $(SRCS:.c=.o)
#
#HEADER			= ./includes/
#FOLDER			= ./srcs/
#
#LIBFT 			= libft
#MLX 			= minilibx
#
#CC				= gcc
#CFLAGS 			= -Wall -Wextra -Werror
#LFLAGS			= -L libft -lft
#
#METAL_MLX		= libmlx.dylib -framework Metal -framework AppKit
#
#RM				= rm -f
#
#all:			$(NAME)
#
#$(NAME):		$(OBJS)
#				@$(CC) $(CFLAGS) -I $(HEADER) $(OBJS) -o $(NAME)
#
#%.o: %.c
#				@$(CC) $(CFLAGS) -I $(HEADER) -o $@ -c $<
#
#clean:
#				@$(RM) $(OBJS)
#
#fclean:			clean
#				@$(RM) $(NAME)
#
#re:				fclean all
#
#.PHONY: 		all fclean clean re





#NAME =			miniRT
#
#CC =			gcc
#
#FLAGS =			-Wall -Wextra -Werror
#
#RM =			rm -rf
#
#DIR_HEADERS =	./includes/
#
#DIR_SRCS =		./srcs/
#
#DIR_OBJS =		./
#
#LIBMLX =		libmlx.dylib \
#				libmlx.a\
#				libft.a
#
#SAVE =			-fsanitize=address
#
#SRC =			MiniRT.c \
#				construct.c\
#				vect_math.c\
#				utils.c\
#				ft_split.c\
#				get_next_line.c\
#				get_next_line_utils.c\
#				parse_obj.c
#
#SRCS =			$(addprefix $(DIR_SRCS), $(SRC))
#
#OBJS =			$(SRCS:.c=.o)
#
#all:			$(NAME)
#
#
#$(NAME) :		$(OBJS)
#				$(CC) $(FLAGS) -I $(DIR_HEADERS) $(OBJS) -o $(NAME)
#
#
#%.o: %.c
#				@gcc $(FLAGS) -I $(DIR_HEADERS) -c $< -o $@
#				@echo "Compiled "$<" successfully!"
#
#bonus:
#
#norme:
#				norminette $(DIR_SRCS)
#				norminette $(DIR_HEADERS)
#
#clean:
#				$(RM) $(OBJS)
#
#fclean:			clean
#				@make clean -C ./minilibx_mms
#				@make clean -C ./minilibx_opengl
#				$(RM) libmlx.dylib
#				$(RM) libmlx.a
#				$(RM) $(NAME)
#
#re:				fclean all
#
#.PHONY:			all, clean, fclean, re, bonus

CC =			gcc

FLAGS =			-Wall -Wextra -Werror -g

RM =			rm -rf

DIR_HEADERS =	./includes/

DIR_SRCS =		./srcs/

DIR_OBJS =		./

# LIBMLX =		libmlx.dylib \
# 				libmlx.a

LIBMLX = 		-lmlx \
				libmlx.dylib \
				-framework AppKit \
				-framework OpenGL

SAVE =			-fsanitize=address

SRC =			mini_rt.c\
				construct.c\
				construct_2.c\
				vect_math.c\
				vect_math_2.c\
				utils.c\
				ft_split.c\
				get_next_line.c\
				get_next_line_utils.c\
				parse_obj.c\
				parse_obj_2.c\
				hit_objects.c\
				hit_objects_2.c\
				color_math.c\
				shape_norm.c\
				ft_atoi.c\
				light.c\
				init.c\
				render.c\
				save_file.c\
				list.c\
				key_proc.c


SRCS =			$(addprefix $(DIR_SRCS), $(SRC))

COMPIL =		$(FLAGS)

OBJS =			$(SRCS:.c=.o)

NAME =			miniRT

all:			$(NAME)

$(NAME) :		$(OBJS)
				@make -C ./minilibx_mms
				# @make -C ./minilibx_opengl
				@cp ./minilibx_mms/libmlx.dylib libmlx.dylib
				# @cp ./minilibx_opengl/libmlx.a libmlx.a
				$(CC) $(COMPIL) -I $(DIR_HEADERS) $(LIBMLX) $(OBJS) -o $(NAME)

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
				$(RM) libmlx.dylib
				$(RM) $(NAME)

re:				fclean all

.PHONY:			all, clean, fclean, re, bonus
