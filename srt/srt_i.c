/*
** EPITECH PROJECT, 2023
** organized.c
** File description:
** organized.c
*/

#include "../include/my.h"

element_t *merge_i(element_t *left, element_t *right)
{
    element_t *tmp = NULL;

    if (left == NULL)
        return right;
    if (right == NULL)
        return left;
    if (left->id < right->id) {
        tmp = left;
        tmp->next = merge_i(left->next, right);
    } else {
        tmp = right;
        tmp->next = merge_i(left, right->next);
    }
    return tmp;
}

void *mergesort_id(element_t **head)
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
    mergesort_id(&left);
    mergesort_id(&right);
    *head = merge_i(left, right);
}
