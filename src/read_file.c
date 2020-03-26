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
    if (file.st_size < 8)
        return (84);
    return (0);
}

int check_open_n_read(char *path, tetri_t *tetrimino)
{
    FILE *file = fopen(path, "r");
    char *buffer = NULL;
    size_t n = 0;
    int lines = 0;

    if (file == NULL || check_size(path) == 84)
        return (84);
    tetrimino->shape = malloc(sizeof(char *));
    while (getline(&buffer, &n, file) != -1) {
        if (tetrimino->shape == NULL)
            return (84);
        tetrimino->shape = add_line_array(tetrimino->shape, buffer);
        lines++;
    }
    if (check_lines(tetrimino, lines) == 84)
        return (84);
    return (0);
}

void check_tetri_properties(tetri_t *tetrimino, arguments_t *arguments)
{
    if (tetrimino->color < 1 || tetrimino->color > 8) {
        tetrimino->error = 84;
        return;
    }
    if (tetrimino->lenght < 1 || tetrimino->lenght > arguments->map_size_y) {
        tetrimino->error = 84;
        return;
    }
    if (tetrimino->width < 1 || tetrimino->width > arguments->map_size_x) {
        tetrimino->error = 84;
        return;
    }
}