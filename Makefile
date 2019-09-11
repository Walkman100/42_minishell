# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcarter <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/12 13:33:41 by mcarter           #+#    #+#              #
#    Updated: 2019/09/11 13:55:18 by mcarter          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCCFLAGS = -Wall -Wextra -Werror
NAME = minishell
SRC = src/*.c
OFILES = bin/*.o
HFILE = src/minishell.h
LFT = -L libft -lft
LFTA = libft/libft.a
MAKEFLAGS += -j

all: $(NAME)
$(NAME): $(LFTA) $(OFILES) $(HFILE)
	gcc $(GCCFLAGS) $(OFILES) $(LFT) -o $(NAME)

$(HFILE): libft/libft.h
$(LFTA): libft/libft.h
	make -C libft
libft/libft.h:
	@git submodule update --init


clean:
	rm -rf bin/
fclean: clean libft/libft.h
	rm -f $(NAME)
	make -C libft fclean
re: fclean
	make all


norm:
	norminette $(HFILE) $(SRC) 2>/dev/null
update:
	git pull
	git submodule update


# Individual files

#  */
bin/*.o: $(HFILE) src/*.c
	@mkdir -p bin
	gcc $(GCCFLAGS) -c src/*.c -o bin/*.o
