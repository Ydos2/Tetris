/*
** EPITECH PROJECT, 2019
** my_free_array.c
** File description:
** Frees an array
*/

#include <stdlib.h>
#include "libmy.h"

void my_free_array(char **array)
{
    if (array == NULL)
        return;
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
}