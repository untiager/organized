/*
** EPITECH PROJECT, 2023
** organized.c
** File description:
** organized.c
*/

int my_atoi(char *str)
{
    int i = 0;

    for (int a = 0; str[a] != '\0'; a++)
        i = i * 10 + str[a] - 48;
    return i;
}
