NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = /bin/rm -f
LDFLAGS = -L.
LDLIBS = -lft
HDDIRS = -I.
SRC = ./functions2.c ./printf_test_file2.c

OBJ = $(subst .c,.o,$(SRC))

HEAD = test_header.h

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o: %.c
	$(CC) $< -c -o $@ -I.$(HEAD) 

clean:
	$(RM) -f $(OBJ)

fclean: clean
	$(RM) -f $(NAME)

re: fclean all
