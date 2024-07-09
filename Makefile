# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: artmarti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/05 08:03:46 by artmarti          #+#    #+#              #
#    Updated: 2023/07/05 09:09:09 by artmarti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ALLFILES = client.c server.c

A_OUT = a.out

OBJECTS = $(ALLFILES:.c=.o)

CFLAGS = -Wall -Wextra -Werror

SERVER = server.a

CLIENT = client.a

all : doprintf $(CLIENT) $(SERVER)

$(CLIENT) : $(OBJECTS)
	@ar rcs $(CLIENT) client.o
	@gcc $(CFLAGS) -o client $(CLIENT)

$(SERVER) : $(OBJECTS)
	@ar rcs $(SERVER) server.o
	@gcc $(CFLAGS) server.c ft_printf/printf.a
	@mv $(A_OUT) server

clean :
	@rm -rf $(OBJECTS)
	@make clean -C ./ft_printf clean

fclean : clean
	@rm -rf $(SERVER) $(CLIENT) $(A_OUT) server client
	@make -C ./ft_printf fclean

re : fclean all

doprintf : 
	@make -C ./ft_printf all
