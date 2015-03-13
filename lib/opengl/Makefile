# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/04 14:25:16 by dsousa            #+#    #+#              #
#    Updated: 2015/03/13 15:01:19 by dsousa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

export	CC	=	g++

NAME		=	OpenglLib.so

CFLAGS		=	-Wall -Wextra -Werror

INC			=	-I includes -I ../../includes/\
				-I ~/.brew/Cellar/glfw3/3.1/include/

INC_DIR		=	includes/

INC_FILES	=	OpenglLib.hpp

INC_SRC		=	$(addprefix $(INC_DIR), $(INC_FILES))

INC_SRC		+=	../../includes/IGraphicLib.hpp

SRC_DIR		=	srcs/

FILES		=	OpenglLib.cpp\
				maker.cpp

SRC			=	$(addprefix $(SRC_DIR), $(FILES))

SRC			+=	../../srcs/IGraphicLib.cpp

OBJ			=	$(SRC:.cpp=.o)


all:			$(NAME)

$(NAME):		$(OBJ)
	@$(CC) $(CFLAGS) -fPIC -shared -o $(NAME) $(OBJ) -L ~/.brew/Cellar/glfw3/3.1/lib/ -lglfw3 -framework OpenGL
	@echo ""
	@echo "\033[33m"compilation of $(NAME) : "\033[32m"Success"\033[0m"

$(OBJ):			$(INC_SRC)

install:
	@brew update
	@~/.brew/bin/brew install homebrew/versions/glfw3

%.o:			%.cpp $(INC_SRC)
	@echo -n .
	@$(CC) $(CFLAGS) -c -fPIC $< -o $@ $(INC)

clean:
	@/bin/rm -f $(OBJ)
	@echo "\033[31m"Objects of $(NAME) : deleted"\033[0m"

fclean:			clean
	@/bin/rm -f $(NAME)
	@echo "\033[31m"$(NAME) : deleted"\033[0m"
re:				fclean all

.PHONY:			all clean fclean re
