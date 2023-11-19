# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dakataso <dakataso@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/03 12:36:51 by dakataso          #+#    #+#              #
#    Updated: 2023/10/03 12:36:56 by dakataso         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol
CC	= cc
CFLAGS	= -Wextra -Wall -Werror
SRC	= main.c fract_init.c str_utils.c counting.c rendering.c hooks.c fractal_sets.c
OBJ	= $(addprefix obj/, $(SRC:.c=.o))

all:	$(NAME)

$(NAME): $(OBJ)
		$(CC) $(OBJ) $(LFLAGS) -o $(NAME) -lmlx -lXext -lX11 -lm

obj/%.o : %.c
		mkdir -p obj
		$(CC) -c $(CFLAGS) -I/usr/include -Imlx_linux -O3 $< -o $@
		
clean:
	rm -rf $(OBJ) obj

fclean: clean
	rm -rf $(NAME)

re: fclean all
