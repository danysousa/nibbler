# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/04 14:25:16 by dsousa            #+#    #+#              #
#    Updated: 2015/03/04 15:23:59 by dsousa           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

export	CC	=	g++

NAME		=	NcursesLib.so

CFLAGS		=	-Wall -Wextra -Werror

INC			=	-I includes -I ../../includes/

INC_DIR		=	includes/

INC_FILES	=	NcursesLib.hpp

INC_SRC		=	$(addprefix $(INC_DIR), $(INC_FILES))

INC_SRC		+=	../../includes/IGraphicLib.hpp

SRC_DIR		=	srcs/

FILES		=	NcursesLib.cpp\
				maker.cpp

SRC			=	$(addprefix $(SRC_DIR), $(FILES))

SRC			+=	../../srcs/IGraphicLib.cpp

OBJ			=	$(SRC:.cpp=.o)


all:			$(NAME)

$(NAME):		$(OBJ)
	@$(CC) $(CFLAGS) -shared -o $(NAME) $(OBJ) -lncurses
	@echo ""
	@echo "\033[33m"compilation of $(NAME) : "\033[32m"Success"\033[0m"

$(OBJ):			$(INC_SRC)

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
