/*
** EPITECH PROJECT, 2020
** add_line_array.c
** File description:
** Removes a str from an array
*/

#include <stdlib.h>
#include "libmy.h"

int get_array_len(char **src)
{
    int len = 0;

    if (src == NULL)
        return (0);
    while (src[len] != NULL)
        len++;
    return (len);
}

char **copy_but_skip_line(char **array, char **src, int line, int len)
{
    for (int i = 0; i < line; i++) {
        array[i] = my_strdup(src[i]);
        if (array[i] == NULL)
            return (NULL);
    }
    for (int i = line; i < len - 1; i++){
        array[i] = my_strdup(src[i + 1]);
        if (array[i] == NULL)
            return (NULL);
    }
    return (array);
}

char **rm_line_array(char **src, int line)
{
    int len = get_array_len(src);
    char **array = NULL;

    if (src == NULL)
        return (NULL);
    array = malloc(sizeof(char *) * (len + 1));
    if (array == NULL)
        return (NULL);
    array = copy_but_skip_line(array, src, line, len);
    if (array == NULL)
        return (NULL);
    array[len - 1] = NULL;
    my_free_array(src);
    return (array);
}