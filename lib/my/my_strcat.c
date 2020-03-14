/*
** EPITECH PROJECT, 2019
** my_strcat
** File description:
** Copies one str to the end of another
*/

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int j = 0;

    while (dest[i] != '\0')
        i = i + 1;
    for (; src[j] != '\0'; j++)
        dest[i + j] = src[j];
    dest[i + j] = '\0';
    return (dest);
}