# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lgrossi <lgrossi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/20 12:59:57 by mcenci            #+#    #+#              #
#    Updated: 2023/10/04 16:31:16 by lgrossi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT_PATH		=	./libft
LIBFT			=	$(LIBFT_PATH)/libft.a
PRINTF_PATH		=   ./ft_printf
PRINTF			=   $(PRINTF_PATH)/libftprintf.a

SRC				=	 ./main.c ./move_set_00.c ./move_set_01.c ./move_set_02.c ./sorting_00.c ./sorting_01.c ./sorting_02.c ./values_to_stacks.c ./Helper_00.c ./Helper_01.c ./check_values.c ./check.c ./values_to_stacks_01.c

HEADER			=	./push_swap.h

OBJECTS			= 	$(SRC:%.c=%.o)

NAME			=	"push_swap"

CC				=	gcc

RM				=	rm -f

CFLAGS			=	-Wall -Wextra -Werror

MAKEFLAGS 		+= -s

all:			$(NAME)

$(NAME):	$(OBJECTS) $(LIBFT)	$(PRINTF)
				$(CC) ${CFLAGS} -c $(SRC)
				$(CC) $(OBJECTS) $(LIBFT) $(PRINTF) -o $(NAME)

$(LIBFT):
				make -s -C $(LIBFT_PATH)

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