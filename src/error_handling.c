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
    char *file_type = NULL;
    int j = 0;

    if (my_strcmp(name, "..") == 0 || my_strcmp(name, ".") == 0)
        return (-84);
    for (; name[i] != '.' && i >= 0; i--);
    file_type = malloc(sizeof(char) * len - i);
    if (file_type == NULL)
        return (-84);
    for (int k = len - 1; name[k] != '.' && k >= 0; k--, j++)
        file_type[j] = name[k];
    file_type[j] = '\0';
    if (my_strcmp(file_type, "onimirtet") != 0)
        return (-84);
    return (i);
}

int check_first_line(tetri_t *tetrimino)
{
    int *props;
    char **first_line = NULL;
    int i = 0;

    if (my_is_str_nbr(tetrimino->shape[0], ' ') == 0)
        return (84);
    props = malloc(sizeof(int) * 3);
    if (props == NULL)
        return (84);
    first_line = my_str_to_array(tetrimino->shape[0], ' ');
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

tetri_t rtn_error(tetri_t tetrimino)
{
    tetrimino.error = 84;
    return (tetrimino);
}

tetri_t check_errors(char *path, tetri_t tetrimino, arguments_t *arguments)
{
    if (check_open_n_read(path, &tetrimino) != 0)
        return (rtn_error(tetrimino));
    check_tetri_properties(&tetrimino, arguments);
    return (tetrimino);
}