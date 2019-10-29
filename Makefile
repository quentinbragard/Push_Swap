# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qbragard <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/21 14:39:47 by qbragard          #+#    #+#              #
#    Updated: 2019/07/17 10:00:52 by qbragard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re, lib, $(NAME), $(NAME2), $(NAME3)

# **************************************************************************** #
#                                SOURCE FILES                                  #
# **************************************************************************** #
# ****************************     PUSH_SwAP    ****************************** #

NAME       = push_swap
SRCS_PATH  = srcs/push_swap/
OBJS_PATH  = objs/push_swap/
SRC_NAME   = main.c operations1.c operations2.c operations3.c \
			 trio_sorting.c push_swap.c parser.c stack_a_to_b.c \
			 stack_b_to_a.c small_sorting.c optimisation.c
OBJ_NAME   = $(SRC_NAME:.c=.o)
SRCS       = $(addprefix $(SRCS_PATH),$(SRC_NAME))
OBJS       = $(addprefix $(OBJS_PATH),$(OBJ_NAME))

# ******************************    CHECKER    ******************************* #

NAME2      = checker
SRCS2_PATH = srcs/checker/
OBJS2_PATH = objs/checker/
SRC2_NAME  = main.c checker.c parser.c operations1.c operations2.c \
			 operations3.c
OBJ2_NAME  = $(SRC2_NAME:.c=.o)
SRCS2      = $(addprefix $(SRCS2_PATH),$(SRC2_NAME))
OBJS2      = $(addprefix $(OBJS2_PATH),$(OBJ2_NAME))

# ******************************    VIEWER     ******************************* #

NAME3       = viewer
SRCS3_PATH  = srcs/viewer/
OBJS3_PATH  = objs/viewer/
SRC3_NAME   = main.c parser.c operations1.c operations2.c \
			  operations3.c viewer.c maths.c sdl_operations.c sdl_operations1.c
OBJ3_NAME   = $(SRC3_NAME:.c=.o)
SRCS3       = $(addprefix $(SRCS3_PATH),$(SRC3_NAME))
OBJS3       = $(addprefix $(OBJS3_PATH),$(OBJ3_NAME))

# **************************************************************************** #
#                                COMPILATION                                   #
# **************************************************************************** #

CC     	 	= gcc
CFLAGS  	= -Wall -Wextra -Werror -Iincludes
VFLAGS		= -F /Library/Frameworks/ -framework SDL2
LIB_DEP 	= $(shell find libft/srcs/*.c)

all : $(NAME) $(NAME2) $(NAME3)

libft/libft.a : $(LIB_DEP) libft/includes/libft.h
	@make -sC libft

lib : libft/libft.a

# ****************************     PUSH_SwAP    ****************************** #

$(OBJS_PATH)%.o : $(SRCS_PATH)%.c libft/libft.a includes/push_swap.h
	@mkdir -p $(OBJS_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "                                                               \\r"
	@printf "$(NAME) -- $<\\r"

$(NAME) : $(OBJS)
	@printf "                                                               \\r"
	@$(CC) $(CFLAGS) $^ -o $(NAME) -L libft -lft
	@printf "\033[32;1m$(NAME)        [ OK! ]\033[0m\\n"


# ******************************    CHECKER    ******************************* #

$(OBJS2_PATH)%.o : $(SRCS2_PATH)%.c libft/libft.a includes/checker.h
	@mkdir -p $(OBJS2_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "                                                               \\r"
	@printf "[$(NAME2)] -- $<\\r"

$(NAME2) : $(OBJS2)
	@printf "                                                               \\r"
	@$(CC) $(CFLAGS) $^ -o $(NAME2) -L libft -lft
	@printf "\033[32;1m$(NAME2)          [ OK! ]\033[0m\\n"

# ******************************    VIEWER     ******************************* #

$(OBJS3_PATH)%.o : $(SRCS3_PATH)%.c libft/libft.a includes/viewer.h
	@mkdir -p $(OBJS3_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@
	@printf "                                                               \\r"
	@printf "$(NAME2) -- $<\\r"

$(NAME3) : $(OBJS3)
	@printf "                                                               \\r"
	@$(CC) $(CFLAGS) $(VFLAGS)  $^ -o $(NAME3) -L libft -lft
	@printf "\033[32;1m$(NAME3)          [ OK! ]\033[0m\\n"


# **************************************************************************** #
#                                  COMMANDS                                    #
# **************************************************************************** #

clean :
	@rm -rf objs
	@make clean -sC libft
	@printf "make: cleaning objs\\n"

fclean : clean
	@rm -rf $(NAME) $(NAME2) $(NAME3)
	@make fclean -sC libft
	@printf "make: cleaning programs\\n"

re : fclean all
