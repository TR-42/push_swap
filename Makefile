# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/12 21:27:47 by kfujita           #+#    #+#              #
#    Updated: 2023/02/15 23:21:20 by kfujita          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
NAME_BONUS	=	checker

SRC_DIR	=	./srcs

SRCS	=\
	atoi_strict.c \
	main.c \
	stack_init.c \
	stack_print.c \
	stack_swap.c \

SRCS_BONUS	=\
	main_bonus.c \

OBJ_DIR	=	./obj
OBJS	=	$(addprefix $(OBJ_DIR)/, $(SRCS:.c=.o))
OBJS_BONUS	=	$(addprefix $(OBJ_DIR)/, $(SRCS_BONUS:.c=.o))

DEPS	=	$(addprefix $(OBJ_DIR)/, $(SRCS:.c=.d))
DEPS_BONUS	=	$(addprefix $(OBJ_DIR)/, $(SRCS_BONUS:.c=.d))

LIBFT_DIR	=	./libft
LIBFT	=	$(LIBFT_DIR)/libft.a
LIBFT_MAKE	=	make -C $(LIBFT_DIR)

CFLAGS	=	-Wall -Wextra -Werror -MMD
INCLUDES	=	-I $(LIBFT_DIR) -I ./headers

CC		=	cc

all:	$(NAME)

$(NAME):	$(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^

$(NAME_BONUS):	$(LIBFT) $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $^

$(OBJ_DIR)/%.o:	$(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

$(LIBFT):
	$(LIBFT_MAKE)

bonus:
	make $(NAME_BONUS)

clean:
	$(LIBFT_MAKE) clean
	rm -f $(OBJS) $(OBJS_BONUS) $(DEPS) $(DEPS_BONUS)
	rm -d $(OBJ_DIR) 2>/dev/null || exit 0

fclean:	clean
	$(LIBFT_MAKE) fclean
	rm -f $(NAME)

re:	fclean all

-include $(DEPS) $(DEPS_BONUS)

.PHONY:	clean bonus
