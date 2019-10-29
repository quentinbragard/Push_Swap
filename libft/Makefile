# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qbragard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/19 10:27:21 by qbragard          #+#    #+#              #
#    Updated: 2019/05/28 10:13:16 by qbragard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NAME = libft.a

LIBFT_PATH = srcs/
LIBFT_NAME = ft_atoi.c ft_bzero.c ft_factorial.c \
	ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
	ft_isprint.c ft_itoa.c ft_lstadd.c \
	ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c \
	ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
	ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_pow.c \
	ft_putchar_fd.c ft_putchar.c ft_putendl_fd.c ft_putendl.c \
	ft_putnbr_fd.c ft_putnbr.c ft_putstr.c ft_strcat.c \
	ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c \
	ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c \
	ft_strjoin.c ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c \
	ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnew.c \
	ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c \
	ft_strsub.c ft_strtrim.c ft_tolower.c ft_toupper.c \
	ft_putstr_fd.c ft_count_words.c ft_intlen.c \
	ft_lstsize.c ft_pow.c get_next_line.c ft_swap.c \
	ft_printtab.c ft_sqrt.c ft_strstrdel.c ft_tablen.c \
	ft_print_tab_int.c return_gnl.c

LIBFT_OBJS_PATH = objs/

LIBFT_OBJS_NAME = $(LIBFT_NAME:.c=.o)

LIBFT = $(addprefix $(LIBFT_PATH),$(LIBFT_NAME))
LIBFT_OBJS = $(addprefix $(LIBFT_OBJS_PATH),$(LIBFT_OBJS_NAME))

CC = gcc
CFLAGS = -Wall -Werror -Wextra
IFLAG = -I ./includes

$(LIBFT_OBJS_PATH)%.o: $(LIBFT_PATH)%.c includes/libft.h
	@mkdir $(LIBFT_OBJS_PATH) 2> /dev/null || true
	@$(CC) $(CFLAGS) $(IFLAG) -o $@ -c $<
	@echo "Compiling $<\r\c"

all: $(NAME)

$(NAME): $(LIBFT_OBJS)
	@ar rc $(NAME) $(LIBFT_OBJS)
	@ranlib $(NAME)
	@echo "\033[2K\c"
	@echo "\033[1;34mlibft\t\033[1;33mCompilation\t\033[0;32m[OK]\033[0m"


clean:
	@rm -rf $(FT_PRINTF_OBJS_PATH) $(LIBFT_OBJS_PATH)
	@echo "\033[1;34mlibft\t\033[1;33mCleaning obj\t\033[0;32m[OK]\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[1;34mlibft\t\033[1;33mCleaning lib\t\033[0;32m[OK]\033[0m"

re: fclean all

.PHONY: all clean fclean re
