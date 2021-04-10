NAME        =       rush

SRCS        =       utilities.c \
					parsing.c \
					main.c
					
OBJS        =       ${SRCS:.c=.o}

CFLAGS		=		-Wall -Wextra -Werror

CC			=		gcc

all :       $(NAME)

clean :
	$(RM) $(OBJS)

fclean :    clean
	$(RM) $(NAME)

re :
	$(MAKE) fclean
	$(MAKE) all

$(NAME) :   $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

.PHONY :    all fclean clean re