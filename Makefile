# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcarter <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/12 13:33:41 by mcarter           #+#    #+#              #
#    Updated: 2019/09/25 13:09:55 by mcarter          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GCCFLAGS = -Wall -Wextra -Werror
NAME = minishell
SRC = src/builtins/builtin_cd.c src/builtins/builtin_clear.c \
		src/builtins/builtin_echo.c src/builtins/builtin_env.c \
		src/builtins/builtin_exit.c src/builtins/builtin_pwd.c \
		src/builtins/builtin_setenv.c src/builtins/builtin_unsetenv.c \
		src/func/get_envvar.c src/func/get_input.c \
		src/func/get_path_from_envp.c src/func/get_path.c \
		src/func/parse_input.c src/func/run_function.c src/func/run_program.c \
		src/func/show_prompt.c src/func/wait_for_pid.c src/main/main.c
OFILES = bin/builtin_cd.o bin/builtin_clear.o bin/builtin_echo.o \
		bin/builtin_env.o bin/builtin_exit.o bin/builtin_pwd.o \
		bin/builtin_setenv.o bin/builtin_unsetenv.o bin/get_envvar.o \
		bin/get_input.o bin/get_path_from_envp.o bin/get_path.o \
		bin/parse_input.o bin/run_function.o bin/run_program.o \
		bin/show_prompt.o bin/wait_for_pid.o bin/main.o
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

#  builtins/
bin/builtin_cd.o: $(HFILE) src/builtins/builtin_cd.c
	@mkdir -p bin
	gcc $(GCCFLAGS) -c src/builtins/builtin_cd.c -o bin/builtin_cd.o

bin/builtin_clear.o: $(HFILE) src/builtins/builtin_clear.c
	@mkdir -p bin
	gcc $(GCCFLAGS) -c src/builtins/builtin_clear.c -o bin/builtin_clear.o

bin/builtin_echo.o: $(HFILE) src/builtins/builtin_echo.c
	@mkdir -p bin
	gcc $(GCCFLAGS) -c src/builtins/builtin_echo.c -o bin/builtin_echo.o

bin/builtin_env.o: $(HFILE) src/builtins/builtin_env.c
	@mkdir -p bin
	gcc $(GCCFLAGS) -c src/builtins/builtin_env.c -o bin/builtin_env.o

bin/builtin_exit.o: $(HFILE) src/builtins/builtin_exit.c
	@mkdir -p bin
	gcc $(GCCFLAGS) -c src/builtins/builtin_exit.c -o bin/builtin_exit.o

bin/builtin_pwd.o: $(HFILE) src/builtins/builtin_pwd.c
	@mkdir -p bin
	gcc $(GCCFLAGS) -c src/builtins/builtin_pwd.c -o bin/builtin_pwd.o

bin/builtin_setenv.o: $(HFILE) src/builtins/builtin_setenv.c
	@mkdir -p bin
	gcc $(GCCFLAGS) -c src/builtins/builtin_setenv.c -o bin/builtin_setenv.o

bin/builtin_unsetenv.o: $(HFILE) src/builtins/builtin_unsetenv.c
	@mkdir -p bin
	gcc $(GCCFLAGS) -c src/builtins/builtin_unsetenv.c -o bin/builtin_unsetenv.o

#  func/
bin/get_envvar.o: $(HFILE) src/func/get_envvar.c
	@mkdir -p bin
	gcc $(GCCFLAGS) -c src/func/get_envvar.c -o bin/get_envvar.o

bin/get_input.o: $(HFILE) src/func/get_input.c
	@mkdir -p bin
	gcc $(GCCFLAGS) -c src/func/get_input.c -o bin/get_input.o

bin/get_path_from_envp.o: $(HFILE) src/func/get_path_from_envp.c
	@mkdir -p bin
	gcc $(GCCFLAGS) -c src/func/get_path_from_envp.c -o bin/get_path_from_envp.o

bin/get_path.o: $(HFILE) src/func/get_path.c
	@mkdir -p bin
	gcc $(GCCFLAGS) -c src/func/get_path.c -o bin/get_path.o

bin/parse_input.o: $(HFILE) src/func/parse_input.c
	@mkdir -p bin
	gcc $(GCCFLAGS) -c src/func/parse_input.c -o bin/parse_input.o

bin/run_function.o: $(HFILE) src/func/run_function.c
	@mkdir -p bin
	gcc $(GCCFLAGS) -c src/func/run_function.c -o bin/run_function.o

bin/run_program.o: $(HFILE) src/func/run_program.c
	@mkdir -p bin
	gcc $(GCCFLAGS) -c src/func/run_program.c -o bin/run_program.o

bin/show_prompt.o: $(HFILE) src/func/show_prompt.c
	@mkdir -p bin
	gcc $(GCCFLAGS) -c src/func/show_prompt.c -o bin/show_prompt.o

bin/wait_for_pid.o: $(HFILE) src/func/wait_for_pid.c
	@mkdir -p bin
	gcc $(GCCFLAGS) -c src/func/wait_for_pid.c -o bin/wait_for_pid.o

#  main/
bin/main.o: $(HFILE) src/main/main.c
	@mkdir -p bin
	gcc $(GCCFLAGS) -c src/main/main.c -o bin/main.o
