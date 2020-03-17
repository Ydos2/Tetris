/*
** EPITECH PROJECT, 2020
** my_strequbool
** File description:
** my_strequbool
*/

#include <stdlib.h>
#include <stdbool.h>
#include "libmy.h"

bool my_strequbool(char *str1, char *str2)
{
    bool ret = false;

    if (str1 == NULL || str2 == NULL)
        return (false);

    if (my_strcmp(str1, str2) == 0)
        ret = true;

    return (ret);
}