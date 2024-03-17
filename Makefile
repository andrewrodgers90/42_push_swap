# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arodgers <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/04 13:08:28 by arodgers          #+#    #+#              #
#    Updated: 2023/12/19 17:45:57 by arodgers         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Werror -Wextra

HDR = push_swap.h
NAME = push_swap
SRCS = push_swap.c move.c push_commands.c rotate_commands.c reverse_rotate_commands.c swap_commands.c stack_utils.c get_utils.c set_utils.c handle_utils.c error_utils.c libft_utils.c libft_utils_extra.c str_utils.c is_utils.c free_utils.c

OBJS = $(SRCS:.c=.o)

RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS) $(HDR)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
