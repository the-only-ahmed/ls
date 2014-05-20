# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ael-kadh <ael-kadh@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/27 22:05:06 by ael-kadh          #+#    #+#              #
#    Updated: 2013/12/14 12:52:15 by ael-kadh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls
SRC = main.c listing.c match.c flags.c sort.c bond.c new.c
HEADER = main.h
OBJ = main.o listing.o match.o flags.o sort.o bond.o new.o
FLAGS = -Wall -Wextra -Werror

all : $(NAME)

makeother :
	@cd ./libft; make re; cd ..

$(NAME) : makeother
	@gcc $(FLAGS) -c $(SRC)
	@gcc -o $(NAME) *.o -L ./libft -lft

clean :
	@rm -f $(OBJ) main.h.gch

fclean : clean
	@rm -f $(NAME)

re : fclean all
