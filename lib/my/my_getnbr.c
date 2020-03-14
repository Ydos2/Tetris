/*
** EPITECH PROJECT, 2019
** my_getnbr.c
** File description:
** Gets the number "hidden" in a string and returns it
*/

int my_getnbr(char *str)
{
    int res = 0;
    int power = 1;
    int count = 0;
    int i = 0;

    if (str == ((void *)0))
        return (0);
    for (; str[i] == '-' || str[i] == '+'; i++)
        if (str[i] == '-')
            power = power * -1;
    for (int k = i; str[k] >= '0' && str[k] <= '9'; k++) {
        res = (res * 10) + (str[k] - '0');
        count++;
        if (count > 10)
            return (0);
    }
    return (res * power);
}