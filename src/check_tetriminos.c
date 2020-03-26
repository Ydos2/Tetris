/*
** EPITECH PROJECT, 2020
** Tetris
** File description:
** Check's the tetriminos in the tetriminos folder
*/

#include <sys/types.h>
#include <dirent.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "libmy.h"
#include "tetris.h"

char *clean_name(char *old_name, int last_pos)
{
    int i = 0;
    char *new_name = my_calloc(last_pos + 1);

    if (new_name == NULL)
        return (NULL);
    for (; i < last_pos; i++)
        new_name[i] = old_name[i];
    return (new_name);
}

tetri_t *add_tetrimino(tetri_t *tetrimino, int nbr_tets, char *clean_name)
{
    tetri_t *new_tetrimino = NULL;

    if (tetrimino == NULL)
        return (NULL);
    new_tetrimino = malloc(sizeof(tetri_t) * (nbr_tets));
    if (new_tetrimino == NULL)
        return (NULL);
    for (int i = 0; i < nbr_tets - 1; i++)
        new_tetrimino[i] = tetrimino[i];
    new_tetrimino[nbr_tets - 1].name = clean_name;
    return (new_tetrimino);
}

char **remove_first_line(char **shape)
{
    char **new_shape = NULL;
    int len = get_array_len(shape);

    new_shape = malloc(sizeof(char *) * len);
    for (int i = 0; i < len; i++)
        new_shape[i] = my_strdup(shape[i + 1]);
    new_shape[len] = NULL;
    return (new_shape);
}

int check_lines(tetri_t *tetrimino, int lines)
{
    int high_width = 0;
    int pos = 0;

    if (check_first_line(tetrimino) == 84)
        return (84);
    tetrimino->shape = remove_first_line(tetrimino->shape);
    for (int i = 0; tetrimino->shape[i] != NULL; i++) {
        pos = (my_strlen(tetrimino->shape[i]) - 2);
        if (tetrimino->shape[i][pos] == '*' && (pos + 1) > high_width)
            high_width = (pos + 1);
    }
    if (high_width != tetrimino->width || lines - 1 != tetrimino-> lenght)
        return (84);
    for (int i = 0; tetrimino->shape[lines - 2][i] != '\0'; i++)
        if (tetrimino->shape[lines - 2][i] == '*' && tetrimino->shape\
        [lines - 2][my_strlen(tetrimino->shape[lines - 2]) - 1] == '\n')
            return (0);
    return (84);
}

tetri_t *check_folder(arguments_t *arguments, int nbr_tets)
{
    struct dirent *dir;
    DIR *fld = opendir("tetriminos");
    tetri_t *tetrimino = malloc(sizeof(tetri_t));
    int last_pos = 0;

    if (fld == NULL)
        return (NULL);
    while ((dir = readdir(fld)) != NULL) {
        last_pos = check_name(dir->d_name);
        if (last_pos == -84)
            continue;
        nbr_tets++;
        tetrimino = add_tetrimino(tetrimino, nbr_tets, \
            clean_name(dir->d_name, last_pos));
        tetrimino[nbr_tets - 1] = check_errors(my_strcatt("tetriminos/", \
            dir->d_name), tetrimino[nbr_tets - 1], arguments);
    }
    closedir(fld);
    share_nbr_tetris(nbr_tets);
    return (tetrimino);
}