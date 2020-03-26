/*
** EPITECH PROJECT, 2019
** delivery_re
** File description:
** my_strncmp
*/

int my_strcmp(char *s1, char *s2)
{
    int i = 0;

    for (; s1[i] != '\0' && s2[i] != '\0'; i++) {
        if (s1[i] > s2[i])
            return (1);
        if (s1[i] < s2[i])
            return (-1);
    }
    if (s1[i] > s2[i])
        return (1);
    if (s1[i] < s2[i])
        return (-1);
    return (0);
}

int my_strpmc(char *s1, char *s2)
{
    int i = 0;

    for (; s1[i] != '\0' && s2[i] != '\0'; i++) {
        if (s1[i] > s2[i])
            return (1);
        if (s1[i] < s2[i])
            return (-1);
    }
    if (s1[i] > s2[i])
        return (1);
    if (s1[i] < s2[i])
        return (-1);
    return (0);
}