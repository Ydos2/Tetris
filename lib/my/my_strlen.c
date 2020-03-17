/*
** EPITECH PROJECT, 2018
** my_strlen
** File description:
** my_strlen
*/

int my_strlen(char *str)
{
    int nbr =  0;

    if (!str)
        return (0);
    for (; str[nbr] != '\0'; nbr++);
    return (nbr);
}