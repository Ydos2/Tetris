/*
** EPITECH PROJECT, 2020
** my_is_stralphap.c
** File description:
** Function checks if str is alphanumeric with an added exception
*/

#include "libmy.h"

int my_is_stralphap(char *str, char exception)
{
    int len = my_strlen(str);
    int i = 0;

    if (str[i] == '-')
        i++;
    for (; i < len - 1; i++)
        if (my_is_alphap(str[i], exception) == 0)
            return (0);
    return (1);
}