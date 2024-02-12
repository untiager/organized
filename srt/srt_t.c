/*
** EPITECH PROJECT, 2023
** organized.c
** File description:
** organized.c
*/

#include "../include/my.h"
#include "../include/shell.h"

int length_list(element_t *data)
{
    int length = 0;
    element_t *tmp = data;

    for (length; tmp != NULL; tmp = tmp->next)
        length++;
    return length;
}

element_t *merge_t(element_t *left, element_t *right)
{
    element_t *tmp = NULL;

    if (left == NULL)
        return right;
    if (right == NULL)
        return left;
    if (my_strcmp(left->type, right->type) < 0) {
        tmp = left;
        tmp->next = merge_t(left->next, right);
    } else {
        tmp = right;
        tmp->next = merge_t(left, right->next);
    }
    return tmp;
}

void *mergesort_type(element_t **head)
{
    element_t *left = NULL;
    element_t *right = NULL;
    element_t *mid = *head;
    int length = length_list(*head);

    if (length <= 1)
        return *head;
    for (int i = 0; i < (length / 2) - 1; i++)
        mid = mid->next;
    left = *head;
    right = mid->next;
    mid->next = NULL;
    mergesort_type(&left);
    mergesort_type(&right);
    *head = merge_t(left, right);
}

int find_argc(char **args)
{
    int i = 0;

    for (int a = 0; args[a] != NULL; a++)
        i++;
    return i;
}

static void sort_basics(void *data, char **args)
{
    if (args[0][0] == 'T' && args[0][1] == 'Y'
    && args[0][2] == 'P' && args[0][3] == 'E')
        mergesort_type(data);
    if (args[0][0] == 'I' && args[0][1] == 'D')
        mergesort_id(data);
    if (args[0][0] == 'N' && args[0][1] == 'A'
    && args[0][2] == 'M' && args[0][3] == 'E')
        mergesort_name(data);
}

static void sort_r(void *data, char **args)
{
    if (args[0][0] == 'N' && args[0][1] == 'A'
    && args[0][2] == 'M' && args[0][3] == 'E'
    && args[1][0] == '-' && args[1][1] == 'r')
        mergesort_name_r(data);
    if (args[0][0] == 'I' && args[0][1] == 'D'
    && args[1][0] == '-' && args[1][1] == 'r')
        mergesort_id_r(data);
    if (args[0][0] == 'T' && args[0][1] == 'Y'
    && args[0][2] == 'P' && args[0][3] == 'E'
    && args[1][0] == '-' && args[1][1] == 'r')
        mergesort_type_r(data);
}

int sort(void *data, char **args)
{
    int argc = find_argc(args);

    if (argc == 1) {
        if (args[0][0] != 'T' && args[0][0] != 'I' && args[0][0] != 'N')
            return 84;
        sort_basics(data, args);
    }
    if (argc == 2) {
        if (args[0][0] != 'T' && args[0][0] != 'I' && args[0][0] != 'N')
            return 84;
        sort_r(data, args);
    }
    if (argc > 2){
        return 84;
    }
    return 0;
}
