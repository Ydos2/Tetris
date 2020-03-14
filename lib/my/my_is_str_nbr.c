/*
** EPITECH PROJECT, 2020
** my_is_str_nbr.c
** File description:
** Function checks if str is a number
*/

#include "libmy.h"

int my_is_str_nbr(char *str, char exception)
{
    int len = my_strlen(str);
    int i = 0;

    if (str[i] == '-')
        i++;
    for (; i < len - 1; i++)
        if (my_is_nbr(str[i], exception) == 0)
            return (0);
    return (1);
}