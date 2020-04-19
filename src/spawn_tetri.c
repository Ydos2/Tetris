/*
** EPITECH PROJECT, 2020
** spawn_tetri
** File description:
** Spawns tetriminos
*/

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "tetris.h"

void change_map(arguments_t *arguments, char **tetrimino)
{
    int middle = 0;

    middle = (arguments->map_size_x / 2);
    for (int i = 0; tetrimino[i + 1] != NULL; i++)
        for (int j = 0; tetrimino[i][j] != '\n' && tetrimino[i][j] != '\0'; j++)
            arguments->map[i + 1][middle + j] = tetrimino[i][j];
}

void spawn_tetri(arguments_t *arguments, tetri_t *tetrimino)
{
    int random = 0;

    srand(clock());
    random = rand() % (arguments->nbr_tets);
    if (tetrimino[random].error == 0)
        change_map(arguments, tetrimino[random].shape);
}