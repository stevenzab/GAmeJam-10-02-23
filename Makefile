##
## EPITECH PROJECT, 2023
## GAmeJam-10-02-23
## File description:
## Makefile
##

SRC	= main.cpp

NAME	=	GameJam

OBJ	=	$(SRC:.cpp=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	@g++ -o $(NAME) $(SRC) -Llib/my -lmy -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

clean:
	@make clean -C lib/my

fclean:	clean

re:	fclean all