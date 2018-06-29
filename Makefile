# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbrazas <vbrazas@student.unit.ua>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/28 19:24:02 by vbrazas           #+#    #+#              #
#    Updated: 2018/06/29 14:03:32 by vbrazas          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_gkrellm

SRC_PATH = classes/
MODULES_PATH = modules/
INC_PATH = includes/
OBJ_PATH = obj/

C = clang++
WFLAGS = -Wall -Werror -Wextra -std=c++98 -pedantic -pedantic-errors
IFLAGS = -I $(INC_PATH)
LFLAGS = -lncurses

CLASSES = CursesDisplay
MODULES = module Name OS Time CPU RAM Network
FILES = main

SRCS = $(addprefix $(SRC_PATH), $(addsuffix .cpp, $(CLASSES)))
SRCS += $(addprefix $(SRC_PATH)$(MODULES_PATH), $(addsuffix .cpp, $(MODULES)))
SRCS += $(addsuffix .cpp, $(FILES))
OBJ = $(addprefix $(OBJ_PATH), $(SRCS:%.cpp=%.o))


all: $(NAME)

$(NAME): $(OBJ)
	$(C) $(WFLAGS) $(LFLAGS) $(IFLAGS) $(OBJ) -o $(NAME)

$(OBJ): | $(OBJ_PATH)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)$(SRC_PATH)$(MODULES_PATH)

$(OBJ_PATH)%.o: %.cpp
	$(C) $(WFLAGS) $(IFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean:
	rm -f $(OBJ) $(NAME)
	rm -rf $(OBJ_PATH)

re: fclean all

.PHONY: all clean fclean re
