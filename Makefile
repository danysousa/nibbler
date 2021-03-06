# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/03 13:29:20 by dsousa            #+#    #+#              #
#    Updated: 2015/03/11 16:55:16 by nschilli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

export	CC	=	g++

NAME		=	nibbler

CFLAGS		= -Wall -Wextra -Werror

INC			+=	-I includes

INC_DIR		=	includes/

INC_FILES	=	CoreEngine.hpp\
				AGameObject.hpp\
				GameEngine.hpp\
				Snake.hpp\
				BodyBlock.hpp\
				RenderEngine.hpp\
				Food.hpp\
				IGraphicLib.hpp

INC_SRC		=	$(addprefix $(INC_DIR), $(INC_FILES))

SRC_DIR		=	srcs/

FILES		=	main.cpp\
				CoreEngine.cpp\
				AGameObject.cpp\
				GameEngine.cpp\
				Snake.cpp\
				BodyBlock.cpp\
				RenderEngine.cpp\
				Food.cpp\

SRC			=	$(addprefix $(SRC_DIR), $(FILES))

OBJ			=	$(SRC:.cpp=.o)


all:			$(NAME)

$(NAME):		$(OBJ)
	@make -C lib/ncurses
	@make -C lib/opengl
	@make -C lib/sdl
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ)
	@echo ""
	@echo "\033[33m"compilation of $(NAME) : "\033[32m"Success"\033[0m"

$(OBJ):			$(INC_SRC)

%.o:			%.cpp $(INC_SRC)
	@echo -n .
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

clean:
	@make clean -C lib/ncurses
	@make clean -C lib/opengl
	@make clean -C lib/sdl
	@/bin/rm -f $(OBJ)
	@echo "\033[31m"Objects of $(NAME) : deleted"\033[0m"

fclean:			clean
	@make fclean -C lib/ncurses
	@make clean -C lib/opengl
	@make clean -C lib/sdl
	@/bin/rm -f $(NAME)
	@echo "\033[31m"$(NAME) : deleted"\033[0m"
re:				fclean all

.PHONY:			all clean fclean re

