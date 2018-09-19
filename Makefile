# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcornick <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/27 15:54:40 by jcornick          #+#    #+#              #
#    Updated: 2018/09/17 17:46:21 by jcornick         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = ./ft_addnew.c ./ft_sort.c ./ft_infomation.c ./ft_flags.c ./ft_dirhandle.c

OBJ = $(SRC:.c=.o)

HEADER = ./

$(NAME): $(OBJ)
	make all -C ./libft/
	gcc -Wall -Werror -Wextra -c $(SRC) -I $(HEADER)
	ar rc $(NAME).a *.o ./libft/*.o
	gcc -Wall -Werror -Wextra ./main.c $(NAME).a -o $(NAME)

all: $(NAME)

clean:
	rm -f *.o
	make clean -C ./libft/

fclean: clean
	rm -f $(NAME).a
	rm -f $(NAME)
	make fclean -C ./libft/

re: fclean all

.PHONY: all fclean clean
