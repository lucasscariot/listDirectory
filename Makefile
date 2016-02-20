# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lscariot <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/01/22 09:44:59 by lscariot          #+#    #+#              #
#    Updated: 2016/02/20 12:57:43 by lscariot         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ft_ls

CC		= clang

S_DIR	=

O_DIR	=

I_DIR	=

FLAGS	= -Wall -Wextra -Werror $(I_DIR) $(LIBS_DIR)

FILES	= ft_check_args.c		ft_infofile.c		ft_readdir.c		main.c \
		  ft_show_files.c		ft_lists.c			ft_tri.c			\
		  ft_swap_list.c		ft_free.c			ft_print_time.c		\
		  ft_isdir.c			ft_time.c			ft_get_time.c		\
		  ft_maxlen.c			ft_error.c

LIBS_F	= ft

SRC		= $(addprefix $(S_DIR),$(FILES))

OBJS	= $(addprefix $(O_DIR),$(FILES:.c=.o))

LIBS	= $(addprefix -L. -l,$(LIBS_F))

RM		= rm -f

all: 		$(NAME)

$(NAME): 	$(OBJS)
	@echo ""
	@make -C libft
	@$(CC) $(FLAGS) $(LIBS) $^ -o $@
	@echo "\033[32m$(NAME) created.\033[0m"

$(O_DIR)%.o:		$(S_DIR)%.c
	@$(CC) $(FLAGS) -c $< -o $@
	@echo "\033[33m.\033[0m\c"

clean:
	@$(RM) $(OBJS)
	@make -C libft clean

fclean: 	clean
	@$(RM) $(NAME)
	@make -C libft fclean
	@echo "\033[31m$(NAME) cleaned.\033[0m"

re:			fclean all
	@make clean

.PHONY: re clean fclean all
