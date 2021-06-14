# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kgeorgia <kgeorgia@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/13 13:41:14 by kgeorgia          #+#    #+#              #
#    Updated: 2021/04/16 17:16:06 by kgeorgia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	libasm.a

SRC			=	ft_strlen.s\
 				ft_strcmp.s\
				ft_strcpy.s\
				ft_write.s\
				ft_read.s\
				ft_strdup.s

SRCS		= 	$(addprefix ./srcs/, $(SRC))
OBJS		=	$(SRCS:.s=.o)
BONUS_SRC	=	ft_atoi_base_bonus.s\
				ft_list_size_bonus.s\
				ft_list_push_front_bonus.s\
				ft_list_remove_if_bonus.s\
				ft_list_sort_bonus.s

BONUS_SRCS	=	$(addprefix ./b_srcs/, $(BONUS_SRC))

BONUS_OBJS	=	$(BONUS_SRCS:.s=.o)

NA			=	nasm
NA_FLAGS	=	-f macho64
FLAGS 		=	-Wall -Werror -Wextra

TEST		=	test
TEST_BONUS	=	test_bonus

%.o:			%.s
				$(NA) $(NA_FLAGS) $<

all:			$(NAME)

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS)

clean:
				rm -rf $(OBJS) $(BONUS_OBJS)

fclean:			clean
				rm -rf $(NAME) $(BONUS) $(TEST) $(TEST_BONUS)

re:				fclean $(NAME)

test:			$(NAME)
				gcc $(FLAGS) -L. -lasm -o $(TEST) main.c
				./$(TEST) < Makefile

bonus:			$(OBJS) $(BONUS_OBJS)
				ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

test_bonus:		bonus
				gcc $(FLAGS) -L. -lasm -o $(TEST_BONUS) main_bonus.c
				./$(TEST_BONUS)

.PHONY:			clean fclean re test bonus test_bonus
