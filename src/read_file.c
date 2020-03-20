/*
** EPITECH PROJECT, 2020
** read_file.c
** File description:
** Reads the tetrimino file
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "tetris.h"
#include "libmy.h"

int check_size(char *path)
{
    struct stat file;
    int rtn = 0;

    rtn = stat(path, &file);
    if (rtn != 0)
        return (84);
    if (file.st_size == 0)
        return (84);
    return (0);
}

int check_open_n_read(char *path, tetri_t *tetrimino)
{
    FILE *file = fopen(path, "r");
    char **array = NULL;
    char *buffer = NULL;
    size_t n = 0;

    if (file == NULL || check_size(path) == 84)
        return (84);
    array = malloc(sizeof(char *));
    tetrimino->shape = malloc(sizeof(char));
    while (getline(&buffer, &n, file) != -1) {
        if (tetrimino->shape == NULL || array == NULL)
            return (84);
        array = add_line_array(array, buffer);
        tetrimino->shape = my_stradd(tetrimino->shape, buffer);
    }
    if (check_lines(array, tetrimino) == 84)
        return (84);
    return (0);
}

int check_tetrimino(void)
{
    return (0);
}