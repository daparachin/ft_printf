CC 		:= 	clang
FLAGS 	:= 	-Wall -Wextra -Werror
RM		:=	rm -f
LIBFT		= libft

NAME	:= libftprintf.a

SRCS 	:= ft_printf.c int_to_hex.c print_pointer_hex.c

OBJS	:= $(SRCS:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJS)
				@make -C $(LIBFT)
				@cp libft/libft.a .
				@mv libft.a $(NAME)
				ar -rcs $(NAME) $(OBJS)

.c.o:
			$(CC) $(FLAGS) -c $< -o $(<:.c=.o)
clean:
			$(RM) $(OBJS)

fclean: 	clean
			$(RM) $(NAME)
	
re:		fclean all
