# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ygolshan <ygolshan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/11 15:05:49 by ygolshan          #+#    #+#              #
#    Updated: 2024/02/11 16:12:16 by ygolshan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ex03

CXX = c++
CPPFLAGS = -std=c++98 -Wall -Wextra -Werror -g3 

SRC =	AForm.cpp\
		Bureaucrat.cpp\
		Intern.cpp\
		main.cpp\
		PresidentialPardonForm.cpp\
		RobotomyRequestForm.cpp\
		ShrubberyCreationForm.cpp\

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CPPFLAGS) -o $(NAME) $(OBJ)
	
clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)
