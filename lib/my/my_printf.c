/*
** EPITECH PROJECT, 2019
** my_printf
** File description:
** A copy of printf's capabilities
*/

#include <stdarg.h>
#include <stdio.h>
#include "libmy.h"

int check_percent(char *str, int pos, int len)
{
    static int pos_last_2 = -2;

    if (pos_last_2 == pos)
        return (0);
    if (str[pos] == '%' && pos >= len - 1)
        return (0);
    if ((str[pos] == '%' && str[pos + 1] == '%')) {
        pos_last_2 = pos + 1;
        return (1);
    }
    if (str[pos] == '%' && str[pos + 1] == ' ')
        return (0);
    if (str[pos] == '%')
        return (1);
    return (0);
}

int count_args(char *str)
{
    int len = my_strlen(str);
    int nbr = 0;

    if (len == 0)
        return (-1);
    for (int i = 0; str[i] != '\0'; i++) {
        if (check_percent(str, i, len) == 1)
            nbr++;
    }
    return (nbr);
}

int printing(char *str, int pos, va_list list)
{
    switch (str[pos]) {
        case 'c':
            my_putchar(va_arg(list, int));
            break;
        case 's':
            my_putstr(va_arg(list, char *));
            break;
        case 'i':
            my_putnbr(va_arg(list, int));
            break;
        case 'd':
            my_putnbr(va_arg(list, int));
            break;
        default :
            break;
    }
    return (pos);
}

int end_list(va_list list)
{
    va_end(list);
    return (0);
}

int my_printf(char *format, ...)
{
    int nbr = count_args(format);
    va_list list;

    if (nbr < 0)
        return (0);
    if (nbr == 0)
        return (my_putstr(format));
    va_start(list, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] != '%' && format[i - 1] != '%')
            my_putchar(format[i]);
        else if (format[i] == '%' && format[i + 1] == '%') {
            i++;
            my_putchar('%');
        }
        else
            printing(format, i + 1, list);
    }
    return (end_list(list));
}