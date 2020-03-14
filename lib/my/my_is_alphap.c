/*
** EPITECH PROJECT, 2020
** my_is_alphap.c
** File description:
** Function checks if char is alphanumeric with an added exception
*/

int my_is_alphap(char c, char exception)
{
    if (c == exception)
        return (1);
    if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || \
        (c >= 'a' && c <= 'z'))
        return (1);
    else
        return (0);
}