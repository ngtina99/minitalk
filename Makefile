# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thuy-ngu <thuy-ngu@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/27 11:54:50 by thuy-ngu          #+#    #+#              #
#    Updated: 2024/02/22 16:52:34 by thuy-ngu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT = client

NAME_SERVER = server

SRC_CLIENT = client.c client_utils.c

OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

SRC_SERVER = server.c

OBJ_SERVER = $(SRC_SERVER:.c=.o)

LIBFT = ./libft/libft.a

INCLUDE_LIBFT = -I./libft/libft.h

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

RM = rm -f

all:	$(NAME_CLIENT) $(NAME_SERVER)

$(LIBFT):
	$(MAKE) -C ./libft

$(NAME_CLIENT): $(LIBFT) $(OBJ_CLIENT)
	$(CC) $(CFLAGS) $(INCLUDE_LIBFT) $(OBJ_CLIENT) $(LIBFT) -o $(NAME_CLIENT)

$(NAME_SERVER): $(LIBFT) $(OBJ_SERVER)
	$(CC) $(CFLAGS) $(INCLUDE_LIBFT) $(OBJ_SERVER) $(LIBFT) -o $(NAME_SERVER)

clean:
	$(MAKE) -C ./libft clean
	$(RM) $(OBJ_CLIENT) $(OBJ_SERVER)

fclean:	clean
	$(RM) $(NAME_CLIENT) $(NAME_SERVER)
	$(MAKE) -C ./libft fclean

re:	fclean all

.PHONY: all clean fclean re