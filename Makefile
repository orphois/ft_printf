NAME = libftprintf.a

SRCS =	ft_printf.c \
		ft_putchars.c \
		ft_putptr.c \
		ft_putunsigned.c \
		ft_putsigned.c \
	

CC = cc

CFLAGS = -Wall -Wextra -Werror

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
		ar rcs $(NAME) $(OBJS)

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		rm -f $(OBJS)

fclean : clean
		rm -f $(NAME)

re: fclean all