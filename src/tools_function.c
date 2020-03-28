/*
** EPITECH PROJECT, 2020
** tools_function
** File description:
** tools_function
*/

#include <stdlib.h>
#include "tetris.h"
#include "libmy.h"

void *xmalloc(int size)
{
    void *p = malloc(size);

    if (!p)
        return (NULL);
    return (p);
}