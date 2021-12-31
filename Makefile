# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: itomescu <itomescu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/25 16:34:04 by itomescu          #+#    #+#              #
#    Updated: 2021/12/29 15:08:43 by itomescu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SERVER	= server
NAME_CLIENT	= client
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

OBJ_SRV		= server.o
OBJ_CL		= client.o

all:	$(NAME_SERVER) $(NAME_CLIENT)

$(NAME_SERVER): $(OBJ_SRV)
		$(MAKE)	-C ./printf
		$(CC)	-o $(NAME_SERVER) $(OBJ_SRV) -Lprintf -lftprintf

$(NAME_CLIENT): $(OBJ_CL)
		$(CC)	-o $(NAME_CLIENT) $(OBJ_CL) -Lprintf -lftprintf

%.o: %.c
		$(CC)	-c $(CFLAGS) -o $@ $<
clean:
		rm -f $(OBJ_CL) $(OBJ_SRV)
		$(MAKE)	-C ./printf clean

fclean: clean
		rm -f $(NAME_SERVER) $(NAME_CLIENT)
		$(MAKE)	-C ./printf fclean

re: fclean all

.PHONY: all clean fclean re