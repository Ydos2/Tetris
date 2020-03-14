/*
** EPITECH PROJECT, 2020
** my_stradd.c
** File description:
** Remallocs a str (src) and adds another str to the end of src
*/

#include <stdlib.h>
#include "libmy.h"

char *my_stradd(char *src, char *add)
{
    char *rtn = NULL;
    int len = my_strlen(src) + my_strlen(add);
    int i = 0;
    int j = 0;

    rtn = malloc(sizeof(char) * (len + 1));
    if (src == NULL || rtn == NULL)
        return (NULL);
    for (; src[i] != '\0'; i++)
        rtn[i] = src[i];
    for (; add[j] != '\0'; j++)
        rtn[i + j] = add[j];
    rtn[i + j] = '\0';
    free(src);
    return  (rtn);
}