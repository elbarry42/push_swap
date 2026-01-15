NAME = push_swap.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -MMD -MP -I./include
OBJDIR = .objects
PARSING = srcs/parsing/
ALGO = srcs/algorithms/
OPS = srcs/operations/
STACK = srcs/stack/
INDEX = srcs/index/
AR = ar rcs
RM = rm -f

VPATH = $(ALGO) $(INDEX) $(OPS) $(PARSING) $(STACK)
SRCS =	$(ALGO)adaptive.c $(ALGO)complex.c $(ALGO)medium.c $(ALGO)simple.c \
		$(INDEX)index.c \
		$(OPS)push.c $(OPS)swap.c $(OPS)rotate.c $(OPS)rev_rotate.c \
		$(PARSING)parsing.c $(PARSING)parsing_flags.c $(PARSING)parsing_number.c $(PARSING)ft_atoi.c $(PARSING)ft_bzero.c \
		$(PARSING)ft_calloc.c $(PARSING)ft_isdigit.c $(PARSING)ft_itoa.c $(PARSING)printf_utils.c \
		$(PARSING)ft_printf.c $(PARSING)ft_split.c $(PARSING)ft_strlcpy.c $(PARSING)ft_strlen.c \
		$(PARSING)ft_strncmp.c \
		$(STACK)stack.c \
		main.c

OBJS = $(addprefix $(OBJDIR)/,$(notdir $(SRCS:.c=.o)))
DEPS = $(addprefix $(OBJDIR)/,$(notdir $(SRCS:.c=.d)))

all: $(NAME)

$(NAME): $(OBJS) | Makefile
	$(AR) $(NAME) $(OBJS)

$(OBJDIR)/%.o:%.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR) :
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus

-include $(DEPS)
