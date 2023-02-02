# ==============================================================================
# PATH
# ==============================================================================

UTILS	:= utils


# ==============================================================================
# VARIABLES
# ==============================================================================

NAME	:=	philosophers
CC		:=	cc
CFLAGS	:=	-g3 -Wall -Werror -Wextra
HEADERS	:=	philo/includes
SRCS	:=	philo/philosophers.c \
			$(UTILS)/ft_atoi.c
OBJS	:=	$(SRCS:.c=.o)

# ==============================================================================
# COLORS
# ==============================================================================

GREEN		:=	\033[1;32m
RED			:=	\033[1;31m
WHT			:=	\033[1;37m
EOC			:=	\033[1;0m

# ==============================================================================
# RECIPES
# ==============================================================================

all:		$(NAME)

%.o:		%.c
			@$(CC) $(CFLAGS) -I $(HEADERS) -c $< -o $@

$(NAME):	$(OBJS) 
			@echo "$(WHT)Compiling Philosophers...$(EOC)"
			@$(CC) $(OBJS) -pthread  -o $@
			@echo "$(GREEN)Philosophers build completed.$(EOC)"


clean:
			@echo "$(WHT)Removing .o files...$(EOC)"
			@rm -f $(OBJS)
			@echo "$(GREEN)Clean done.$(EOC)"

fclean:		clean
			@echo "$(WHT)Removing object- and binary -files...$(EOC)"
			@rm -f $(NAME)
			@echo "$(GREEN)Fclean done.$(EOC)"

re:			fclean all

valgrind:
			@valgrind -s --leak-check=full --show-leak-kinds=all \
			--track-origins=yes --trace-children=yes --log-fd=9 ./$(NAME) 9>memcheck.log

.PHONY:		all clean fclean re