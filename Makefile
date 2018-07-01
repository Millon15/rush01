# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/28 19:24:02 by vbrazas           #+#    #+#              #
#    Updated: 2018/07/01 11:37:47 by vbrazas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_gkrellm

SRC_PATH = classes/
MODULES_PATH = modules/
INC_PATH = includes/
OBJ_PATH = obj/

C = clang++
WFLAGS = -Wall -Werror -Wextra -Wno-error=unused-command-line-argument
IFLAGS = -I $(INC_PATH)
LFLAGS = -lncurses
GFLAGS = `pkg-config --cflags --libs gtk+-2.0`

CLASSES = CursesDisplay GUIDisplay
MODULES = ACursesModule AGUIModule Name OS Time CPU RAM NetworkThro NetworkInfo Cat
FILES = main utils

SRCS = $(addprefix $(SRC_PATH), $(addsuffix .cpp, $(CLASSES)))
SRCS += $(addprefix $(SRC_PATH)$(MODULES_PATH), $(addsuffix .cpp, $(MODULES)))
SRCS += $(addsuffix .cpp, $(FILES))
OBJ = $(addprefix $(OBJ_PATH), $(SRCS:%.cpp=%.o))


all: $(NAME)

$(NAME): $(OBJ)
	$(C) $(WFLAGS) $(GFLAGS) $(LFLAGS) $(IFLAGS) $(OBJ) -o $(NAME)

$(OBJ): | $(OBJ_PATH)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)$(SRC_PATH)$(MODULES_PATH)

$(OBJ_PATH)%.o: %.cpp
	$(C) $(WFLAGS) $(GFLAGS) $(IFLAGS) -c $< -o $@

# gui:
# 	$(C) $(WFLAGS) -c $(SRC_PATH)GUIDisplay.cpp -o $(OBJ_PATH)GUIDisplay.o

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(OBJ) $(NAME)
	rm -rf $(OBJ_PATH)

re: fclean all

.PHONY: all clean fclean re
