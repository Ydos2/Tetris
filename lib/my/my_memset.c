/*
** EPITECH PROJECT, 2020
** my_memset
** File description:
** my_memset
*/

#include "libmy.h"

void my_memset(char *str, int n, char c)
{
    for (int index = 0; index < n; index++)
        str[index] = c;
    str[n - 1] = '\0';
}