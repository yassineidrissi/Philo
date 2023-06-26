SRCS = philo.c srcs/ft_parsing.c srcs/errors.c srcs/lib_src.c srcs/utils.c

OBJS			= $(SRCS:.c=.o)
CC				= cc
RM				= rm -f
CFLAGS			= -g -Wall -Wextra -Werror -I.
NAME			= philo

%.o : %.c
		@$(CC) $(CFLAGS) -c $< -o $@

all:		1337_logo	$(NAME) 

$(NAME):	1337_logo	$(OBJS)
			@cc $(OBJS) -o $(NAME)
			# @echo "\033[92m✅SO_LONG GENERATED YOU CAN STARTED✅\033[0m"
			# @echo "🎮 USE ./SO_LONG <MAP FILE NAME> 🎮"
clean:
				@$(RM) $(OBJS) 
				@echo "\033[31m Delete object files🗑\033[31m"
			
fclean:			clean
				@$(RM) $(NAME)
				@echo "\033[31m Delete exucted file🗑\033[31m"

re:				fclean $(NAME)

1337_logo:

	@echo "\033[92m░░███╗░░██████╗░██████╗░███████╗\033[0m███╗░░░███╗███████╗██████╗░"
	@echo "\033[92m░████║░░╚════██╗╚════██╗╚════██║\033[0m████╗░████║██╔════╝██╔══██╗"
	@echo "\033[92m██╔██║░░░█████╔╝░█████╔╝░░░░██╔╝\033[0m██╔████╔██║█████╗░░██║░░██║"
	@echo "\033[92m╚═╝██║░░░╚═══██╗░╚═══██╗░░░██╔╝░\033[0m██║╚██╔╝██║██╔══╝░░██║░░██║"
	@echo "\033[92m███████╗██████╔╝██████╔╝░░██╔╝░░\033[0m██║░╚═╝░██║███████╗██████╔╝"
	@echo "\033[92m╚══════╝╚═════╝░╚═════╝░░░╚═╝░░░\033[0m╚═╝░░░░░╚═╝╚══════╝╚═════╝░"
	@echo "\033[92mCREATING .O FILES AND exuctubel of philo ⌛\033[0m"

.PHONY: all fclean clean re 1337_logo