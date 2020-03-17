/*
** EPITECH PROJECT, 2020
** tetris.h
** File description:
** Header file for Tetris' bootstrap
*/

#ifndef bs_tet
#define bs_tet
#include <stdbool.h>

typedef struct option opt_t;

typedef struct arguments
{
    int Level;
    char key_left;
    char key_right;
    char key_turn;
    char key_drop;
    char key_quit;
    char key_pause;
    int map_size_x;
    int map_size_y;
    int without_next;
    int debug;
} arguments_t;

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

// help_page.c
void draw_help(void);

// arguments_tetris.c
arguments_t *arguments_tetris(int ac, char **av, arguments_t *arguments);

// tetris_debug.c
void tetris_debug(arguments_t *arguments);

// tetris_game.c
void tetris_start(arguments_t *arguments);

// set_free.c
void free_all(arguments_t *arguments);

// manage_level.c
void manage_level_flag(arguments_t *arguments);

// map.c
void change_map_size(arguments_t *arguments);

// initialise.c
void initialise_arguments(arguments_t *arguments);

#endif /* !bs_tet */
