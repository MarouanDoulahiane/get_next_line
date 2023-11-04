SRC = get_next_line.c get_next_line_utils.c
OBJF = $(SRC:.c=.o)

SRCB = get_next_line_bonus.c get_next_line_utils_bonus.c
OBJFB = $(SRCB:.c=.o)

CFLAGS = -g

NAME = get_next_line

all:$(OBJF)
	@ar -rc $(NAME) $(OBJF)
	@cc $(CFLAGS) main.c get_next_line -o main

bonus:$(OBJFB)
	@ar -rc $(NAME)  $(OBJFB)
	# @cc $(CFLAGS) main.c get_next_line -o main

%.o:%.c get_next_line.h
	@cc -g   -c -o $@ $<
	

clean:
	@rm -fr $(OBJF)

fclean:clean
	@rm -fr $(NAME)

re:fclean all

.PHONY:all bonus clean fclean re