# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aridolfi <aridolfi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/07 22:47:07 by aridolfi          #+#    #+#              #
#    Updated: 2018/02/26 12:16:38 by aridolfi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Executable
NAME	= libft.a

# Compilation
CC		= cc
CFLAGS	= -Wall -Wextra -Werror

# Directories
OBJDIR	= 	objs
PRINTF	=	printf

# Files && Objs
FILES 	=	free_swap			\
			ft_atoi				\
			ft_bzero			\
			ft_digitcount		\
			ft_insertstr		\
			ft_int_tab_bubble	\
 			ft_isalnum 			\
			ft_isalpha			\
			ft_isascii			\
			ft_isdigit			\
			ft_isprint			\
			ft_iswhitespace		\
			ft_itoa_base		\
			ft_itoa				\
			ft_lstadd			\
			ft_lstback			\
			ft_lstdel			\
			ft_lstdelone		\
			ft_lstiter			\
			ft_lstmap			\
			ft_lstnew			\
			ft_memalloc			\
			ft_memcat			\
			ft_memccpy			\
			ft_memchr			\
			ft_memcmp			\
			ft_memcpy			\
			ft_memdel			\
			ft_memmove			\
			ft_memset			\
			ft_memswap			\
			ft_putchar_fd		\
			ft_putchar			\
			ft_putendl_fd		\
			ft_putendl			\
			ft_putnbr_fd		\
			ft_putnbr			\
			ft_putstr_fd		\
			ft_putstr			\
			ft_putwchar_fd		\
			ft_putwchar			\
			ft_strcat			\
			ft_strchr			\
			ft_strclr			\
			ft_strcmp			\
			ft_strcpy			\
			ft_strdel			\
			ft_strdup			\
			ft_strendcpy		\
			ft_strequ			\
			ft_strfind			\
			ft_striter			\
			ft_striteri			\
			ft_strjoin			\
			ft_strlcat			\
			ft_strlen			\
			ft_strmap			\
			ft_strmapi			\
			ft_strncat			\
			ft_strncmp			\
			ft_strncpy			\
			ft_strnequ			\
			ft_strnew			\
			ft_strnstr			\
			ft_strsplit			\
			ft_strrchr			\
			ft_strstr			\
			ft_strsub			\
			ft_strtrim			\
			ft_strupper			\
			ft_tolower			\
			ft_toupper			\
			get_next_line		\
			palloc				\
			\
			$(PRINTF)/check		\
			$(PRINTF)/conv_l		\
			$(PRINTF)/conv_n		\
			$(PRINTF)/conv_b		\
			$(PRINTF)/format		\
			$(PRINTF)/ft_printf	\
			$(PRINTF)/init			\
			$(PRINTF)/opt			\

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

.PHONY:		clean fclean

# **************************************************************************** #

# RULES

# Main rules
all				: 	$(OBJDIR) $(NAME)

re				: 	fclean all

# Compilation rules
$(OBJDIR)		:
					@mkdir -p $@ 2>&-
					@cd $@ && mkdir -p $(PRINTF) 2>&-

$(NAME)			:	$(OBJP)
					@ar rc $@ $^
					@ranlib $@
					@echo "--$(LOG_CLEAR)$(LOG_RED)$(NAME)$(LOG_NOCOLOR) ........................ $(LOG_RED)Cake Done$(LOG_NOCOLOR)$(LOG_UP)"

$(OBJDIR)/%.o	:	%.c
					@echo "--$(LOG_CLEAR)$(LOG_RED)$(NAME)$(LOG_NOCOLOR) ........................ $(LOG_RED)$<$(LOG_NOCOLOR)$(LOG_UP)"
					@$(CC) $(CFLAGS) $(ADDFLAGS) -c -o $@ $^ -I ./$(PRINTF) -I .

# Clean rules
clean			:
					@rm -rf $(OBJDIR)

fclean			: 	clean
					@rm -f $(NAME)
