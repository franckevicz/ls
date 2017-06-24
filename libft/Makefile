# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfrankev <mfrankev@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/29 13:51:48 by mfrankev          #+#    #+#              #
#    Updated: 2017/02/18 19:12:50 by mfrankev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC =	ft_atoi.c \
		ft_bzero.c \
		ft_itoa.c \
		ft_swap.c \
		ft_memalloc.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memdel.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar.c \
		ft_putwchar.c \
		ft_putchar_fd.c \
		ft_putendl.c \
		ft_putendl_fd.c \
		ft_putnbr.c \
		ft_putnbr_fd.c \
		ft_putstr.c \
		ft_putstr_fd.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strclr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strndup.c \
		ft_strequ.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlen.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strncat.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strnequ.c \
		ft_strnew.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strsplit.c \
		ft_strstr.c \
		ft_strsub.c \
		ft_strtrim.c \
		ft_strfreejoin.c \
		ft_tolower.c \
		ft_toupper.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_lstnew.c \
		ft_lstdelone.c \
		ft_lstdel.c \
		ft_lstadd.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_lstpushback.c \
		ft_lstprint.c \
		ft_realloc.c \
		ft_free_bzero.c \
		ft_stack_new.c \
		ft_stack_dispose.c \
		ft_stack_pop.c \
		ft_stack_push.c \
		ft_stack_push_back.c \
		ft_stack_pop_back.c \
		double_link_list.c \
		double_link_list_2.c \
		get_next_line/get_next_line.c \
		printf/head.c \
		printf/help_functions.c \
		printf/help_functions_2.c \
		printf/print_d.c \
		printf/print_1.c \
        printf/print_chars.c

OBJ = $(SRC:.c=.o)

HEADER = libft.h get_next_line/get_next_line.h printf/printf.h

CC = gcc

CFLAGS = -c

all: $(NAME)

$(NAME): $(OBJ)
		@ar rc $(NAME) $(OBJ)
		@ranlib $(NAME)
		@echo "Library $(NAME) has been compiled (all rule)."

%.o: %.c $(HEADER)
		@$(CC) $(CFLAGS) -o $@ $<

clean:
		@rm -f $(OBJ)
		@echo "Object files of library has been deleted (clean rule)."

fclean: clean
		@rm -f $(NAME)
		@echo "Library has been deleted (fclean rule)."

re: fclean all
