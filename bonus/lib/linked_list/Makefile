##
## EPITECH PROJECT, 2020
## Blib
## File description:
## Makefile
##

SRC		=	src/add_node.c				\
			src/remove_node.c			\
			src/create_node.c			\
			src/create_list.c			\
			src/add_node.c				\
			src/destroy_list.c			\
			src/destroy_node.c			\

OBJ		=	$(SRC:.c=.o)

CFLAGS	=	-I include -I ../blib/include -L ../ -lblib -W

NAME	=	liblinked_list.a

$(NAME):	$(OBJ)
	@ar rc $(NAME) $(OBJ)
	@cp -r include/ ../../
	@cp $(NAME) ../

all:	$(NAME)

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)
	@rm -f ../$(NAME)

re:	fclean all
