# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asoptere <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/15 19:28:07 by asoptere          #+#    #+#              #
#    Updated: 2018/02/15 19:39:54 by asoptere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ft_ls

SRC		=	main.c print_manager.c lists.c sort.c file_manager.c print_manager2.c data.c time.c

OBJ		= $(SRC:.c=.o)

CFLAGS	= -Wall -Wextra -Werror

$(NAME): $(OBJ)
	@make -C libft/ fclean
	@make -C libft/
	@gcc $(OBJ) -o $(NAME)  -L libft/ -lft

all: $(NAME)

clean:
	@make -C libft/ clean
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME) $(OBJ)

re: fclean $(NAME)
