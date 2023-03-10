##
## EPITECH PROJECT, 2023
## GAmeJam-10-02-23
## File description:
## Makefile
##

SRC	=		main.cpp	\
			src/Background.cpp	\
			src/Core.cpp	\
			src/Window.cpp	\
			src/SceneManager.cpp	\
			src/Menu.cpp	\
			src/Player.cpp	\
			src/Game.cpp	\
			src/Sprite.cpp	\
			src/MenuBackground.cpp	\
			src/Life.cpp	\
			src/Button.cpp	\
			src/Music.cpp	\
			src/Sound.cpp	\
			src/bat.cpp     \
			src/Layer.cpp 	\
			src/Panel.cpp	\

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