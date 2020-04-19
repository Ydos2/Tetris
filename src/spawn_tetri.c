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

void change_map_tetri(arguments_t *arguments, char **tetrimino)
{
    int middle = 0;

    middle = (arguments->map_size_x / 2);
    arguments->map = create_empty_map(arguments);
    for (int i = 0; tetrimino[i + 1] != NULL; i++)
        for (int j = 0; tetrimino[i][j] != '\n' && tetrimino[i][j] != '\0'; j++)
            arguments->map[i + 1 + arguments->pos_actu_y]
            [middle + j + arguments->pos_actu_x] = tetrimino[i][j];
}

void spawn_tetri(arguments_t *arguments, tetri_t *tetrimino)
{
    int random = 0;

    srand(clock());
    random = rand() % (arguments->nbr_tets);
    if (tetrimino[random].error == 0)
        change_map_tetri(arguments, tetrimino[random].shape);
    arguments->nbr_rand_tetri = random;
}