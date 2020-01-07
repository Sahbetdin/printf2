NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = /bin/rm -f
LDFLAGS = -L.
LDLIBS = -lft
HDDIRS = -I.
SRC = process_sp.c put_d.c \
	put_hex_oct.c put_strings.c functions2.c \
	put_double.c two.c print_double.c arithm.c \
	put_long_dbl.c put_p.c
	
OBJ = $(subst .c,.o,$(SRC))

HEAD = test_header.h

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@gcc main2.c $(NAME)
	@./a.out

%.o: %.c
	@$(CC) $< -c -o $@ -I.$(HEAD)
#	@gcc -I $(HEAD) -o $@ -c $<

clean:
	@$(RM) -f $(OBJ)

fclean: clean
	@$(RM) -f $(NAME)

re: fclean all
