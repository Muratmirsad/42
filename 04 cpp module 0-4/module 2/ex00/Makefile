# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/22 15:03:00 by mdiraga           #+#    #+#              #
#    Updated: 2023/12/22 15:04:32 by mdiraga          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = program
FLAGS = -Wall -Wextra -Werror -std=c++98
SRCS = main.cpp Fixed.cpp

all: $(NAME)

$(NAME): $(SRCS)
	@c++ $(FLAGS) $(SRCS) -o $(NAME)
	@clear
	@echo "program created."

clean:
	@rm -rf $(NAME)
	@echo "program cleaned."

fclean: clean

re: clean all