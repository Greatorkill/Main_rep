NAME = libftprintf.a
SRCS = ft_apply_flags.c\
		ft_c.c\
		ft_d.c\
		ft_flag_accur.c\
		ft_flag_width.c\
		ft_i.c\
		ft_isdigit.c\
		ft_itoa_base.c\
		ft_itoa.c\
		ft_p.c\
		ft_parse_form.c\
		ft_printf.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_s.c\
		ft_strchr.c\
		ft_strlen.c\
		ft_u.c\
		ft_x.c\
		ft_xx.c\
		ft_pct.c\
		ft_o.c\
		ft_strdup.c\
		ft_accur_apply.c

OBJS = $(SRCS:.c=.o)
HEADR = ft_printf.h
CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror

all:	$(NAME)
$(NAME):	$(OBJS) $(HEADR)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(FLAGS) -g -c $<

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re:		fclean all

.PHONY: all, clean, fclean, re
