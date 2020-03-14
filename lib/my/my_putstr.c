/*
** EPITECH PROJECT, 2018
** my_putstr
** File description:
** my_putstr
*/

#include <unistd.h>
#include "libmy.h"

int my_putstr(char *str)
{
    int len = my_strlen(str);

    if (len <= 0)
        return (84);
    write(1, str, len);
    return (0);
}