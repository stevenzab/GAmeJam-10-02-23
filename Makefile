##
## EPITECH PROJECT, 2023
## GAmeJam-10-02-23
## File description:
## Makefile
##

SRC	=		main.cpp	\
			src/Core.cpp	\
			src/Window.cpp	\
			src/SceneManager.cpp	\
			src/Menu.cpp	\
			src/Player.cpp	\
			src/Sprite.cpp	\

NAME	=	GameJam

OBJ		=	$(SRC:.cpp=.o)

INC		=	-I./include

RM		=	rm -f

all:	$(NAME)

$(NAME):	$(OBJ)
	g++ -o $(NAME) $(SRC) -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio $(INC) -g3

clean:
	$(RM) $(OBJ)

fclean:	clean
		$(RM) $(NAME)

re:	fclean all