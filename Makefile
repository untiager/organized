##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile
##

CFLAGS	=	-g3

SRC	=	sources/my_strlen.c \
		sources/my_putstr.c \
		sources/my_putchar.c \
		sources/my_put_nbr.c \
		sources/my_put_unsnbr.c \
		sources/my_revstr.c \
		sources/my_put_float.c \
		sources/my_put_hexa.c \
		sources/conv_float_hexa.c \
		sources/my_strcpy.c \
		sources/my_strncpy.c \
		sources/my_getnbr.c \
		sources/counting_col.c \
		sources/counting_line.c \
		sources/my_strdup.c \
		sources/my_atoi.c \
		sources/my_str_to_word_array.c \
		sources/my_strcmp.c \
		flags_my_printf/print_char.c \
		flags_my_printf/print_int.c \
		flags_my_printf/print_percent.c \
		flags_my_printf/print_string.c \
		flags_my_printf/print_dec.c \
		flags_my_printf/print_hexa.c \
		flags_my_printf/print_float.c \
		flags_my_printf/print_pointer.c \
		flags_my_printf/print_uns_int.c \
		flags_my_printf/print_octal.c \
		flags_my_printf/print_sci_e.c \
		flags_my_printf/print_sci_maje.c \
		flags_my_printf/print_gg.c \
		flags_my_printf/print_a.c \
		flags_my_printf/print_maja.c \
		my_printf.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all: 	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	gcc -o  organized organized.c srt/* -L. -lmy -L. -lshell $(CFLAGS)

clean:
	rm -f $(OBJ)
	rm -f *.gcno *.gcda

fclean: clean
	rm -f $(NAME)
	rm -f organized

re:	fclean all
