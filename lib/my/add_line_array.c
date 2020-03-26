/*
** EPITECH PROJECT, 2020
** add_line_array.c
** File description:
** Adds a str to an array
*/

#include <stdlib.h>
#include "libmy.h"

char **add_line_array(char **src, char *line)
{
    int len = 0;
    char **array = NULL;

    if (src == NULL)
        return (NULL);
    for (; src[len] != NULL; len++);
    len++;
    array = malloc(sizeof(char *) * (len + 1));
    if (array == NULL)
        return (NULL);
    array[len - 1] = my_strdup(line);
    array[len] = NULL;
    for (int i = 0; i < len - 1; i++) {
        array[i] = my_strdup(src[i]);
        if (array[i] == NULL)
            return (NULL);
    }
    my_free_array(src);
    return (array);
}