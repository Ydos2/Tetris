/*
** EPITECH PROJECT, 2019
** my_put_nbr
** File description:
** my_put_nbr
*/

#include "libmy.h"

int my_putnbr(int nb)
{
    if (nb < -2147483647 || nb > 2147483647)
        return (84);
    if (nb > 9)
        my_putnbr(nb / 10);
    if (nb < 0 && nb > -10) {
        my_putchar('-');
    } else if (nb < 0) {
        my_putchar('-');
        my_putnbr(nb / -10);
    }
    if (nb >= 0)
        my_putchar(nb % 10 + '0');
    if (nb < 0)
        my_putchar(- nb % 10 + '0');
    return (0);
}