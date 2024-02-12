/*
** EPITECH PROJECT, 2023
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
    #define MY_H_

    #include <stdarg.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <sys/sysmacros.h>
    #include <fcntl.h>
    #include <unistd.h>
    #include <dirent.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <ncurses.h>
    #include "shell.h"

typedef struct Element element_t;
struct Element {
    int id;
    char *type;
    char *name;
    element_t *next;
};

typedef struct liste {
    void *Element;
    int id;
}liste_t;

int print_maja(va_list list3, int);
int my_strcmp(char *s1, char *s2);
int print_a(va_list list3, int);
int print_gg(va_list lit3, int);
int print_sci_maje(va_list list3, int);
int print_sci_e(va_list list3, int);
int print_pointer(va_list list3, int);
int print_uns_int(va_list list3, int);
int print_float(va_list list3, int);
int print_octal(va_list list3, int);
int print_hexa(va_list list3, int);
int print_percent(va_list list3, int);
int print_dec(va_list list3, int);
int print_int(va_list list3, int);
int print_string(va_list list3, int);
int print_char(va_list list3, int);
void my_putchar(char);
int conv_float_hexa(float);
int my_put_nbr(int);
int my_put_float(float);
int my_put_hexa(int);
int my_putstr(char const *);
int my_strlen(char *);
char *my_revstr(char *);
char *my_strdup(char *);
int my_put_unsnbr(int);
char *my_strncpy(char *, char const *, int);
int my_printf(char *s, ...);
int flag(va_list lits3, char);
char *my_strcpy(char *, char const *);
int my_getnbr(char const *);
int my_atoi(char *);
int length_list(element_t *);
void *mergesort_id(element_t **head);
void *mergesort_name(element_t **head);
void *mergesort_id_r(element_t **head);
void *mergesort_name_r(element_t **head);
void *mergesort_type_r(element_t **head);

#endif /* MY_H_ */
