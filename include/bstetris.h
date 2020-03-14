/*
** EPITECH PROJECT, 2020
** tetris.h
** File description:
** Header file for Tetris' bootstrap
*/

#ifndef bs_tet
#define bs_tet

typedef struct tetri_s
{
    char *shape;
    char *name;
    int width;
    int lenght;
    int color;
    int error;
} tetri_t;


// error_handling.c
tetri_t check_errors(int ac, char **av, tetri_t tetrimino);
int check_first_line(char *first_str, tetri_t *tetrimino);
int check_lines(char **array, tetri_t *tetrimino);

// read_file.c
int check_open_n_read(char *path, tetri_t *tetrimino);

#endif /* !bs_tet */
