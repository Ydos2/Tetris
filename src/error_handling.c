/*
** EPITECH PROJECT, 2020
** error_handling.c
** File description:
** Handles error cases
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "tetris.h"
#include "libmy.h"

int check_name(char *name)
{
    int len = my_strlen(name);
    int i = len - 1;

    for (; name[i] != '.' && i >= 0; i--);
    if (i == 0)
        return (84);
    return (0);
}

int check_first_line(char *first_str, tetri_t *tetrimino)
{
    int *props;
    char **first_line = NULL;
    int i = 0;

    if (my_is_str_nbr(first_str, ' ') == 0)
        return (84);
    props = malloc(sizeof(int) * 3);
    if (props == NULL)
        return (84);
    first_line = my_str_to_array(first_str, ' ');
    for (; first_line[i] != NULL; i++);
    if (i != 3)
        return (84);
    for (int j = 0; j < 3; j++)
        props[j] = my_getnbr(first_line[j]);
    tetrimino->width = props[0];
    tetrimino->lenght = props[1];
    tetrimino->color = props[2];
    return (0);
}

int check_lines(char **array, tetri_t *tetrimino)
{
    if (check_first_line(array[0], tetrimino) == 84)
        return (84);
    return (0);
}

tetri_t rtn_error(tetri_t tetrimino)
{
    tetrimino.error = 84;
    return (tetrimino);
}

tetri_t check_errors(int ac, char **av, tetri_t tetrimino)
{
    if (ac != 2)
        return (rtn_error(tetrimino));
    if (check_name(av[1]) != 0)
        return (rtn_error(tetrimino));
    if (check_open_n_read(av[1], &tetrimino) != 0)
        return (rtn_error(tetrimino));
    return (tetrimino);
}