# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llebaken <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/13 08:54:49 by llebaken          #+#    #+#              #
#    Updated: 2018/08/13 08:54:51 by llebaken         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRC = main.c draw.c prepdda.c includes/get_next_line/get_next_line.c mapmem.c key.c arrays.c

LIB = includes/libft/libft.a

FLAG = -lmlx -framework opengl -framework appkit

ERROR = -Werror -Wall -Wextra

all:
	@make -C includes/libft
	@gcc -o $(NAME) $(SRC) $(FLAG) $(ERROR) $(LIB)

clean:
	$(MAKE) -C includes/libft clean
	@rm -f $(NAME)

fclean: clean
	$(MAKE) -C includes/libft fclean
	@rm -f $(LIB)

re: fclean lib all

lib:
	$(MAKE) -C includes/libft all
