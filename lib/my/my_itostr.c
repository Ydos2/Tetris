/*
** EPITECH PROJECT, 2020
** my_itostr
** File description:
** my_itostr
*/

#include <stdlib.h>
#include "libmy.h"

char *my_itostr(unsigned int size)
{
    char *ptr;
    unsigned int i = 0;

    if (!size)
        return (NULL);

    ptr = malloc(sizeof(char) * (size + 1));

    if (ptr == NULL)
        return (NULL);

    while (i < size + 1)
        *(ptr + i++) = 0;

    return (ptr);
}