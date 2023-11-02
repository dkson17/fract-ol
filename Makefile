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
SRC	= main.c fract_utils.c str_utils.c counting.c rendering.c hooks.c
OBJ	= $(addprefix obj/, $(SRC:.c=.o))

all:	$(NAME)

$(NAME): $(OBJ)
		cd minilibx-linux && $(MAKE) all
		$(CC) $(OBJ) -I include -Lminilibx-linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

obj/%.o : %.c
		mkdir -p obj
		$(CC) -c $(CFLAGS) -I/usr/include -Imlx_linux -O3 $< -o $@
		
clean:
	rm -rf $(OBJ) obj
	cd minilibx-linux && $(MAKE) clean

fclean: clean
	rm -rf $(NAME)

re: fclean all
