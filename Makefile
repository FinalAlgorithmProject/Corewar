#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpoltave <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/16 12:41:59 by vpoltave          #+#    #+#              #
#    Updated: 2017/09/01 10:03:06 by vpoltave         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = corewar
CC = gcc

LIBFT = ./libft/libft.a
OBJ = 	./vp_virtual_machine/vp_virtual_main.o \
		./vp_virtual_machine/vp_err_u.o	\
		./vp_virtual_machine/vp_basic.o	\
		./vp_virtual_machine/vp_commands.o	\
		./vp_virtual_machine/vp_instructions.o	\

.PHONY: libft

all: $(NAME)

$(NAME): $(OBJ) libft
	$(CC) -o $(NAME) $(OBJ) $(LIBFT)

libft:
	make -C ./libft

%.o : %.c
	$(CC) -o $@ -c $<

clean:
	rm -rf $(OBJ)
	make clean -C ./libft
fclean: clean
	rm -rf $(NAME)
	make fclean -C ./libft
