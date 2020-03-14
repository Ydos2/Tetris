/*
** EPITECH PROJECT, 2020
** my_is_num.c
** File description:
** Function checks if char is a number
*/

int my_is_nbr(char c, char exception)
{
    if ((c >= '0' && c <= '9') || c == exception)
        return (1);
    else
        return (0);
}