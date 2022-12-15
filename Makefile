NAME		= fdf.a

SRCS		=	*.c\
				*/*.c

OBJS		= $(SRCS:.c=.o)

INCS		=	*.h\
				*/*.h

FLAGS		= -Wall -Werror -Wextra

all: $(NAME)

.o : .c $(INCS)
	cc $(FLAGS) -c $<

$(NAME):$(OBJS)
	ar rc $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)
	
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean bonus