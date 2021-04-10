NAME        =       rush

SRCS        =       srcs/utilities.c \
					srcs/parsing.c \
					srcs/main.c \
					srcs/print.c
					
OBJS        =       ${SRCS:.c=.o}

CFLAGS		=		-Wall -Wextra -Werror -g3

CC			=		gcc

INCS		=		includes

srcs/%.o: srcs/%.c ${INCS}/the_cake_is_a_lie.h
	${CC} ${CFLAGS} -c $< -o $@ -I ${INCS}

all :       $(NAME)

clean :
	$(RM) $(OBJS)

fclean :    clean
	$(RM) $(NAME)

re :
	$(MAKE) fclean
	$(MAKE) all

$(NAME) :   $(OBJS)
	$(CC) $(CFLAGS) -I${INCS} -o $(NAME) $(OBJS) 

.PHONY :    all fclean clean re