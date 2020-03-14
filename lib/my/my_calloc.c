/*
** EPITECH PROJECT, 2020
** my_calloc.c
** File description:
** A bad short version of calloc
*/

#include <stdlib.h>

char *my_calloc(int size)
{
    char *new_str = NULL;

    new_str = malloc(sizeof(char) * size);
    return (new_str);
}