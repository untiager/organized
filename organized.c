/*
** EPITECH PROJECT, 2023
** organized.c
** File description:
** organized.c
*/

#include "include/my.h"
#include "include/shell.h"

static void add2(liste_t *liste, char *name, char *type)
{
    element_t *new = (element_t *)malloc(sizeof(element_t));

    new->id = liste->id;
    liste->id += 1;
    new->name = my_strdup(name);
    new->type = my_strdup(type);
    new->next = liste->Element;
    liste->Element = new;
    my_printf("%s n°%d - \"%s\" added.\n", type, new->id, new->name);
    return;
}

int add(void *data, char **args)
{
    liste_t *liste = data;
    element_t *element = liste->Element;
    char *name = NULL;
    char *type = NULL;

    if (args[0] == NULL || args[1] == NULL || data == NULL)
        return 84;
    for (int i = 0; args[i] != NULL; i += 2) {
        if (my_strcmp(args[i], "ACTUATOR") != 0
        && my_strcmp(args[i], "WIRE") != 0 && my_strcmp(args[i], "SENSOR") != 0
        && my_strcmp(args[i], "DEVICE") != 0
        && my_strcmp(args[i], "PROCESSOR") != 0)
            return 84;
        type = args[i];
        name = args[i + 1];
        add2(liste, name, type);
    }
    return 0;
}

static void del2(element_t *element, element_t *previous, liste_t *liste)
{
    if (previous == NULL){
        liste->Element = element->next;
    } else {
        my_printf("%s n°%d", element->type, element->id);
        my_printf(" - \"%s\" deleted.\n", element->name);
        previous->next = element->next;
    }
    free(element->type);
    free(element->name);
    free(element);
}

static void del_head(liste_t *liste, element_t *element, element_t *previous)
{
    if (element->id == liste->id - 1){
        my_printf("%s n°%d", element->type, element->id);
        my_printf(" - \"%s\" deleted.\n", element->name);
        liste->Element = element->next;
        free(element->type);
        free(element->name);
        free(element);
        return;
    }
    del2(element, previous, liste);
}

int del(void *data, char **args)
{
    liste_t *liste = data;
    element_t *previous = liste->Element;
    int i = 0;

    if (args[0] == NULL)
        return 84;
    for (element_t *element = liste->Element;
    element != NULL; element = element->next){
        if (element->id == my_atoi(args[0])){
            del_head(liste, element, previous);
            return 0;
        }
        previous = element;
    }
    return 0;
}

int disp(void *data, char **args)
{
    liste_t *liste = (liste_t *) data;

    for (element_t *element = liste->Element;
    element != NULL; element = element->next) {
        my_printf("%s ", element->type);
        my_printf("n°%d - ", element->id);
        my_printf("\"%s\"\n", element->name);
    }
    return 0;
}

void flag_h(int ac, char **av)
{
    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        my_printf("To use the program, you need to type ./organized\n");
        my_printf("When in the workshop_shell, you can use the following :\n");
        my_printf("ADD to add an element to the workshop, you need to specif");
        my_printf("y the type and the name of the element\nyou can use the ");
        my_printf("following types : ACTUATOR, WIRE, SENSOR, DEVICE, PROCESS");
        my_printf("OR\nDEL to delete an element from the workshop(only ONE ");
        my_printf("at a time)\nDISP to display the workshop\nSORT to sort th");
        my_printf("e workshop, you can sort by TYPE, NAME or ID and you can ");
        my_printf("sort in reverse by using the -r flag\nThe program will ex");
        my_printf("it when you type 'exit'\nYou can use the -h flag to displ");
        my_printf("lay this message\nThe program will automatically launch a");
        my_printf("t the end of this message\n");
        return;
    }
}

int main(int ac, char **av)
{
    liste_t head = {
        NULL,
        0
    };

    flag_h(ac, av);
    workshop_shell(&head);
    free(head.Element);
    return 0;
}
