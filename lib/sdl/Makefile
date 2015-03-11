# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nschilli <nschilli@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/04 14:25:16 by dsousa            #+#    #+#              #
#    Updated: 2015/03/11 17:57:24 by nschilli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

export	CC	=	g++

NAME		=	SdlLib.so

CFLAGS		=	-Wall -Wextra -Werror

INC			=	-I includes -I ../../includes/\
				-I ~/Library/Frameworks/SDL2.framework/Headers/

INC_DIR		=	includes/

INC_FILES	=	SdlLib.hpp

INC_SRC		=	$(addprefix $(INC_DIR), $(INC_FILES))

INC_SRC		+=	../../includes/IGraphicLib.hpp

SRC_DIR		=	srcs/

FILES		=	SdlLib.cpp\
				maker.cpp

SRC			=	$(addprefix $(SRC_DIR), $(FILES))

SRC			+=	../../srcs/IGraphicLib.cpp

OBJ			=	$(SRC:.cpp=.o)


all:			$(NAME)

$(NAME):		$(OBJ)
	@$(CC) $(CFLAGS) -shared -o $(NAME) $(OBJ) -F ~/Library/Frameworks/ -framework SDL2
	@echo ""
	@echo "\033[33m"compilation of $(NAME) : "\033[32m"Success"\033[0m"

$(OBJ):			$(INC_SRC)

install:
	@brew update
	@~/.brew/bin/brew install sdl
	@cp -r ~/.brew/Cellar/sdl/ ~/Library/Frameworks/

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
