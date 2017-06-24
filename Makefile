# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfrankev <mfrankev@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/29 13:51:48 by mfrankev          #+#    #+#              #
#    Updated: 2017/03/15 12:06:39 by mfrankev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

LIBFT = libft/libft.a

SRC = main.c \
		read_args.c \
		help_functions.c \
		proceed_files.c \
		proceed_folders.c \
		sorting_list.c \
		long_output.c \
		help_functions2.c \
		help_functions3.c

OBJ = $(SRC:.c=.o)

HEADER = ls.h

CC = gcc

CFLAGS = -c -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
		@cd libft && $(MAKE)
		@gcc -o $(NAME) $(OBJ) $(LIBFT)
		@echo "Executive $(NAME) has been compiled (all rule)."

%.o: %.c $(HEADER)
		@$(CC) $(CFLAGS) -o $@ $<

clean:
		@rm -f $(OBJ)
		@echo "Object files of $(NAME) has been deleted (clean rule)."
		@cd libft && $(MAKE) clean

fclean: clean
		@rm -f $(NAME)
		@echo "Executive $(NAME) has been deleted (fclean rule)."
		@cd libft && $(MAKE) fclean

re: fclean all
