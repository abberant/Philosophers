# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/15 22:54:44 by aanouari          #+#    #+#              #
#    Updated: 2023/06/15 23:53:33 by aanouari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo_bonus

CFLAGS	=	-Wall -Wextra -Werror -fsanitize=address -g
CC		=	cc
RM		=	rm -rf

NONE	=	'\033[0m'
GREEN	=	'\033[32m'
RED		=	'\033[1;91m'
GRAY	=	'\033[2;37m'
ITALIC	=	'\033[3m'

SRCS	=	main.c utils.c parse.c \

OBJS	=	$(SRCS:.c=.o)

.c.o	:
			@$(CC) $(CFLAGS) -c $< -o $@
			@echo $(ITALIC)$(GRAY) "Preparing the philosophers..." $(NONE)

all		:	$(NAME)

$(NAME)	:	$(OBJS)
			@echo $(ITALIC)$(GRAY) "* Compiling $(NAME)... *" $(NONE)
			@$(CC) $(CFLAGS) $(OBJS) -o $@
			@echo $(GREEN)"* Compiled *"$(NONE)

clean	:
			@echo $(ITALIC)$(GRAY) "* Removing object files... *" $(NONE)
			@$(RM) $(OBJS)

fclean	:	clean
			@echo $(ITALIC)$(GRAY) "* Removing $(NAME)... *" $(NONE)
			@$(RM) $(NAME)

re		:	fclean all

.PHONY	:	all clean fclean re