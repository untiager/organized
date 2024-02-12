/*
** EPITECH PROJECT, 2023
** organized.c
** File description:
** organized.c
*/

#include "../include/my.h"
#include "../include/shell.h"

element_t *merge_t_r(element_t *left, element_t *right)
{
    element_t *tmp = NULL;

    if (left == NULL)
        return right;
    if (right == NULL)
        return left;
    if (my_strcmp(left->type, right->type) > 0) {
        tmp = left;
        tmp->next = merge_t_r(left->next, right);
    } else {
        tmp = right;
        tmp->next = merge_t_r(left, right->next);
    }
    return tmp;
}

void *mergesort_type_r(element_t **head)
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
    mergesort_type_r(&left);
    mergesort_type_r(&right);
    *head = merge_t_r(left, right);
}
