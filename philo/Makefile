# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aanouari <aanouari@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/27 01:04:53 by aanouari          #+#    #+#              #
#    Updated: 2023/06/16 01:23:49 by aanouari         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

CFLAGS	=	-Wall -Wextra -Werror -pthread -flto 
CC		=	cc
RM		=	rm -rf

NONE	=	'\033[0m'
GREEN	=	'\033[32m'
RED		=	'\033[1;91m'
GRAY	=	'\033[2;37m'
ITALIC	=	'\033[3m'

SRCS	=	main.c philo.c utils.c parsing.c actions.c \
			monitor.c

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
