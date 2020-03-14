/*
** EPITECH PROJECT, 2018
** my_putchar
** File description:
** my_putchar
*/

#include <unistd.h>

int my_putchar(char c)
{
    if (c == '\0')
        return (84);
    write(1, &c, 1);
    return (0);
}