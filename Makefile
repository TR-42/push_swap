# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/12 21:27:47 by kfujita           #+#    #+#              #
#    Updated: 2023/02/19 00:01:29 by kfujita          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap
NAME_BONUS	=	checker

SRC_DIR	=	./srcs

SRCS	=\
	atoi_strict.c \
	ft_swap.c \
	main.c \
	stack_dispose.c \
	stack_init.c \
	stack_print.c \
	stack_push.c \
	stack_rev_rotate.c \
	stack_rotate.c \
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

override CFLAGS	+=	-Wall -Wextra -Werror -MMD -MP
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

debug: clean_local
	make CFLAGS=-DDEBUG

bdebug: clean_local
	make bonus CFLAGS=-DDEBUG

bonus:
	make $(NAME_BONUS)

clean_local:
	rm -f $(OBJS) $(OBJS_BONUS) $(DEPS) $(DEPS_BONUS)
	rm -d $(OBJ_DIR) 2>/dev/null || exit 0

clean: clean_local
	$(LIBFT_MAKE) clean

fclean:	clean
	$(LIBFT_MAKE) fclean
	rm -f $(NAME)

re:	fclean all

-include $(DEPS) $(DEPS_BONUS)

.PHONY:	clean_local bonus debug bdebug
