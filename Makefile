# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gloms <rbrendle@student.42mulhouse.fr>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/19 13:18:52 by gloms             #+#    #+#              #
#    Updated: 2023/08/20 21:10:24 by gloms            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
#                                     CONFIG                                   #
################################################################################

NAME		:= push_swap
NAME_BONUS  := checker
CC			:= gcc
FLAGS		:= -Wall -Wextra -Werror -g3 -g -fsanitize=address
################################################################################
#                                 PROGRAM'S SRCS                               #
################################################################################

SRCS        :=            utils_split.c \
                          moves3.c \
                          moves.c \
                          cost_calculation.c \
                          sorting_utils2.c \
                          moves2.c \
                          utils.c \
                          push_swap.c \
                          sorting_utils.c \
                          lilsort.c \
                          bigsort.c \
                          parser.c \
						  parser_int_inputs.c \

SRCS_BONUS	:=          gnl/get_next_line_utils.c \
                        gnl/get_next_line.c \
                        parser_int_inputs.c \
						bonus_checker.c \
						moves_bonus.c \
						moves2_bonus.c \
						moves3_bonus.c \
						utils_bonus.c \
						utils.c \
						parser.c \
						utils_split.c \

OBJS        := $(SRCS:.c=.o)
OBJS_BONUS	:=	$(SRCS_BONUS:.c=.o)

.c.o:
	${CC} ${FLAGS} -c $< -o ${<:.c=.o}

################################################################################
#                                  Makefile  objs                              #
################################################################################


CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m
RM		    := rm -f

${NAME}:	${OBJS}
			@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CLR_RMV}..."
			${CC} ${FLAGS} -o ${NAME} ${OBJS}
			@echo "$(GREEN)$(NAME) created[0m ✔️"

$(NAME_BONUS):	$(OBJS_BONUS)
				@ echo "$(GREEN)Compilation $(CLR_RMV)of $(YELLOW)$(NAME_BONUS) $(CLR_RMV)..."
				@ $(CC) $(FLAGS) -o $(NAME_BONUS) $(OBJS_BONUS)
				@ echo "$(GREEN)$(NAME_BONUS) created[0m ✔️"

all:		${NAME}

bonus:		$(NAME_BONUS)

clean:
			@ ${RM} *.o */*.o */*/*.o
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)objs ✔️"

fclean:		clean
			@ ${RM} ${NAME}
			@ echo "$(RED)Deleting $(CYAN)$(NAME) $(CLR_RMV)binary ✔️"

re:			fclean all

.PHONY:		all clean fclean re bonus
