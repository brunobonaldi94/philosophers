# ==============================================================================
# PATH
# ==============================================================================

UTILS			:= utils
ARGS_VALIDATION := args_validation
THREADS_PHILO	:= threads_philo
FREE_PROGRAM	:= free_program
TIME_HANDLER	:= time_handler

# ==============================================================================
# VARIABLES
# ==============================================================================

NAME	:=	philo
CC		:=	cc
CFLAGS	:=	-g3 -Wall -Werror -Wextra
HEADERS	:=	includes
SRCS	:=	philosophers.c \
			$(UTILS)/ft_atoi.c $(UTILS)/ft_strdup.c \
			$(ARGS_VALIDATION)/args_validation.c \
			$(TIME_HANDLER)/time_handler.c \
			$(THREADS_PHILO)/threads_philo.c $(THREADS_PHILO)/philo_loggers.c \
			$(THREADS_PHILO)/philo_routine.c  $(THREADS_PHILO)/philo_mutex.c \
			$(THREADS_PHILO)/philo_watcher.c \
			$(FREE_PROGRAM)/free_program.c
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
			@valgrind --tool=helgrind -s --log-fd=9 ./$(NAME) \
			4 210 100 100 7  9>memcheck.log
#3 400 100 100 7  9>memcheck.log

.PHONY:		all clean fclean re
