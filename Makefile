##
## EPITECH PROJECT, 2023
## GAmeJam-10-02-23
## File description:
## Makefile
##

SRC	=		main.cpp	\
			Src/Window.cpp	\

NAME	=	GameJam

OBJ		=	$(SRC:.cpp=.o)

INC		=	-I ./Include

RM		=	rm -f

all:	$(NAME)

$(NAME):	$(OBJ)
	g++ -o $(NAME) $(SRC) -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio $(INC)

clean:
	$(RM) $(OBJ)

fclean:	clean
		$(RM) $(NAME)

re:	fclean all