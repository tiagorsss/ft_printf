SRCS	=	ft_printf.c

OBJS	=	$(SRCS:.c=.o)

CC		=	cc
RM		=	rm -f
CFLAGS	=	-Wall -Werror -Wextra

NAME	=	ft_printf.a

all:	$(NAME)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean $(NAME)