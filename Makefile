NAME = push_swap.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -MMD -MP
AR = ar rcs
RM = rm -f
# SRCS =	srcs/algorithms/adaptive.c srcs/algorithms/complex.c srcs/algorithms/medium.c srcs/algorithms/simple.c \
# 		srcs/operations/push.c srcs/operations/swap.c srcs/operations/rotate.c srcs/operations/rev_rotate.c \
		srcs/stack/stack_add_back.c srcs/stack/stack_utils.c
SRCS =	srcs/parsing/parsing.c srcs/parsing/parsing_utils.c srcs/parsing/ft_atoi.c srcs/parsing/ft_bzero.c \
		srcs/parsing/ft_calloc.c srcs/parsing/ft_isdigit.c srcs/parsing/ft_itoa.c srcs/parsing/ft_printf_utils.c \
		srcs/parsing/ft_printf.c srcs/parsing/ft_split.c srcs/parsing/ft_strlcpy.c srcs/parsing/ft_strlen.c \
		srcs/parsing/ft_strncmp.c main.c \

OBJS = $(SRCS:.c=.o)
DEPS = $(OBJS:.o=.d)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS) $(DEPS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus

-include $(DEPS)
