/*
** EPITECH PROJECT, 2020
** my_arraydup.c
** File description:
** Dups an array
*/

#include <stdlib.h>
#include "libmy.h"

char **my_arraydup(char **src)
{
    int len = 0;
    char **array = NULL;

    if (src == NULL)
        return (NULL);
    while (src[len] != NULL)
        len++;
    array = malloc(sizeof(char *) * (len + 1));
    if (array == NULL)
        return (NULL);
    array[len] = NULL;
    for (int i = 0; i < len; i++) {
        array[i] = my_strdup(src[i]);
        if (array[i] == NULL)
            return (NULL);
    }
    return (array);
}