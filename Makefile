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
	put_long_dbl.c put_p.c put_ee.c put_Le.c put_f1.c \
	check_inf_nan.c
	
OBJ = $(subst .c,.o,$(SRC))
#OBJ = $(SRC:.c=.o)

HEAD = test_header.h

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
#	@ar rc $(NAME) $(OBJ)
	@ar rc $@ $^
	@ranlib $(NAME)

%.o: %.c
	@$(CC) $< -c -o $@ -I.$(HEAD)
#	@gcc -I $(HEAD) -o $@ -c $<

test: all
	clear
	@gcc main_o2.c $(NAME)
	@./a.out

clean:
	@$(RM) -f $(OBJ)

fclean: clean
	@$(RM) -f $(NAME)

re: fclean all
