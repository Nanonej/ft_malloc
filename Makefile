# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/26 11:39:34 by aridolfi          #+#    #+#              #
#    Updated: 2018/04/19 11:15:22 by aridolfi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Check env
ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

# Library
NAME 	= 	libft_malloc_$(HOSTTYPE).so
LINK	=	libft_malloc.so

# Compilation
CC		= 	cc
CFLAGS	=	-Wall -Wextra -Werror

# Directories
SRCDIR	=	srcs
OBJDIR	= 	objs
INCDIR	=	./includes
LIBDIR	= 	./libft/

# Files && Objs

FILES 	=	free			\
			init_zone		\
			malloc			\
			realloc			\
			show_alloc_mem	\

OBJ	   := 	$(addsuffix .o, $(FILES))

# Paths foreach
OBJP 	=	$(addprefix $(OBJDIR)/, $(OBJ))

# **************************************************************************** #

# SPECIAL CHARS

LOG_CLEAR		= \033[2K
LOG_UP			= \033[A
LOG_NOCOLOR		= \033[0m
LOG_BOLD		= \033[1m
LOG_UNDERLINE	= \033[4m
LOG_BLINKING	= \033[5m
LOG_BLACK		= \033[1;30m
LOG_RED			= \033[1;31m
LOG_GREEN		= \033[1;32m
LOG_YELLOW		= \033[1;33m
LOG_BLUE		= \033[1;34m
LOG_VIOLET		= \033[1;35m
LOG_CYAN		= \033[1;36m
LOG_WHITE		= \033[1;37m

# Protect

.PHONY:	clean fclean

# **************************************************************************** #

# RULES

# Main rules
all				: 	$(OBJDIR) $(NAME)

re				: 	fclean all

# Compilation rules
$(OBJDIR)		:
					@mkdir -p $@ 2>&-

$(NAME)			: 	$(OBJP)
					@echo "-------------------------------------------------------------"
					@echo "|                  Debut de la compilation                  |"
					@echo "|                            42                             |"
					@echo "|                         ft_malloc                         |"
					@echo "|                     lib compilation :                     |"
					@echo "|                           libft                           |"
					@make -C $(LIBDIR)
					@rm -f $(NAME)
					@rm -f $(LINK)
					@ar rc $@ $^
					@ranlib $@
					@$(CC) $(CFLAGS) $(OPTFLAGS) -shared -o $@ $^ -L$(LIBDIR) -lft -lncurses
					@ln -s $(NAME) $(LINK)
					@echo "|                        CAKE DONE !                        |"
					@echo "-------------------------------------------------------------"
					@cat cake-v2.ascii
					@echo ""
					@echo "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"

$(OBJDIR)/%.o	:	$(SRCDIR)/%.c
					@$(CC) $(CFLAGS) $(OPTFLAGS) -c $< -o $@ -I$(LIBDIR) -I$(LIBDIR)/printf -I$(INCDIR)

# Clean rules
clean			:
					@rm -rf $(OBJDIR)
					@make clean -C $(LIBDIR)

fclean			: 	clean
					@rm -f $(NAME)
					@rm -f $(LINK)
					@make fclean -C $(LIBDIR)

# **************************************************************************** #
