/*
** EPITECH PROJECT, 2023
** my_strdup.c
** File description:
** strdup
*/

#include <stdlib.h>
#include "../include/my.h"

char *my_strdup(char *src)
{
    int l = 0;
    char *str = malloc(sizeof(char) * my_strlen(src) + 1);

    while (src[l] != '\0') {
        str[l] = src[l];
        l++;
    }
    str[l] = '\0';
    return (str);
}
