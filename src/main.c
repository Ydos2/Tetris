/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** Main file for Tetris' bootstrap
*/

#include <stdlib.h>
#include "libmy.h"
#include "bstetris.h"

int main(int ac, char **av)
{
    tetri_t tetrimino;

    tetrimino = check_errors(ac, av, tetrimino);
    if (tetrimino.error == 84)
        return (84);
    return (0);
}