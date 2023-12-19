# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdiraga <mdiraga@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/22 01:10:39 by mdiraga           #+#    #+#              #
#    Updated: 2023/12/19 18:16:04 by mdiraga          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = phonebook
FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): main.cpp Contact.cpp Phonebook.cpp
	@c++ $(FLAGS) main.cpp Contact.cpp Phonebook.cpp -o $(NAME)
	@clear
	@echo "program created."

clean:
	@rm -rf $(NAME)
	@echo "program cleaned."

fclean: clean

re: clean all