/*
** EPITECH PROJECT, 2019
** my_strncmp
** File description:
** compares 1 str to another for n characters (same returns as strcmp)
*/

int my_strncmp(char *s1, char *s2, int n)
{
    int x = 0;
    int y = 0;

    for (int j = 0; j < n; j++) {
        if (s1[x] == s2[y]) {
            x++;
            y++;
        }
    }
    return (x == n ? 0 : 1);
}
