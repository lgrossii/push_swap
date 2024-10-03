# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgrossi <lgrossi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/20 12:59:57 by lgrossi            #+#    #+#              #
#    Updated: 2023/10/04 16:31:16 by lgrossi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN				=	\033[0;32m
BLUE				=	\033[0;34m
RED					=	\033[0;31m
RESET				=	\033[0m
D_FT_PRINTF			=	ft_printf
D_LIBFT				=	libft
GIT_REPO_LIBFT			=	https://github.com/lgrossii/libft
GIT_REPO_FT_PRINTF		=	https://github.com/lgrossii/ft_printf
LIBFT_PATH			=	./libft
LIBFT				=	$(LIBFT_PATH)/libft.a
PRINTF_PATH			=   	./ft_printf
PRINTF				=   	$(PRINTF_PATH)/libftprintf.a


SRC				=	 ./main.c ./move_set_00.c ./move_set_01.c ./move_set_02.c ./sorting_00.c ./sorting_01.c ./sorting_02.c ./values_to_stacks.c ./Helper_00.c ./Helper_01.c ./check_values.c ./check.c ./values_to_stacks_01.c

HEADER				=	./push_swap.h

OBJECTS				= 	$(SRC:%.c=%.o)

NAME				=	"push_swap"

CC					=	gcc

RM					=	rm -f

CFLAGS				=	-Wall -Wextra -Werror

MAKEFLAGS 			+= -s

all:				$(NAME) 
					@echo "$(GREEN)		Compiled $(NAME) $(RESET)"
					@echo "now for running just type ./push_swap followed by the numbers you want to sort. will be printedd on the screen the steps needed to sort the numbers"

$(NAME):	 		dependencies $(LIBFT)	$(PRINTF)	$(OBJECTS)
					$(CC) ${CFLAGS} -c $(SRC)
					$(CC) $(OBJECTS) $(LIBFT) $(PRINTF) -o $(NAME)

$(LIBFT):
					make -s -C $(LIBFT_PATH)

dependencies:
					echo "$(GREEN)- - - Checking all dependencies	- - - $(RESET)"
					@if [ ! -d $(LIBFT_PATH) ]; then \
					echo "$(RED)!!!!! LIBFT MISSING,  cloning it !!!!!$(RESET)"; \
					git clone $(GIT_REPO_LIBFT) $(LIBFT_PATH); \
					fi
					@if [ ! -d $(PRINTF_PATH) ]; then \
					echo "$(RED)!!!!! ft_printf MISSING,  cloning it   !!!!!$(RESET)"; \
					git clone $(GIT_REPO_FT_PRINTF) $(PRINTF_PATH); \
					fi
					echo "$(GREEN)- - - Dependencies checked	- - - $(RESET) "


$(PRINTF):
				make -s -C $(PRINTF_PATH)

clean:
				${RM} ${OBJECTS}
				make clean -C ${LIBFT_PATH}
				make clean -C ${PRINTF_PATH}

fclean:			clean
					rm -f $(NAME)
					rm -f $(LIBFT)
					rm -f $(PRINTF)

re:				fclean all

.PHONY:			all clean re
