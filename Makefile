##
## EPITECH PROJECT, 2026
## MyPrintf
## File description:
## Makefile
##

SRC	=	src/my_printf.c \
		src/utils.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

CPPFLAGS	=	-I./include

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all