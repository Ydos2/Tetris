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

typedef struct arguments_s
{
    char key_left;
    char key_right;
    char key_turn;
    char key_drop;
    char key_quit;
    char key_pause;
    int level;
    int map_size_x;
    int map_size_y;
    int without_next;
    int debug;
    int nbr_tets;
    int score;
    char **map;
    int frame;
    int start_time;
    int high_score;
} arguments_t;

typedef struct tetri_s
{
    char **shape;
    char *name;
    int width;
    int lenght;
    int color;
    int error;
} tetri_t;

// help_page.c
int print_help(void);

// error_handling.c
tetri_t check_errors(char *path, tetri_t tetrimino, arguments_t *arguments);
int check_first_line(tetri_t *tetrimino);
int check_name(char *name);

// read_file.c
int check_open_n_read(char *path, tetri_t *tetrimino);
void check_tetri_properties(tetri_t *tetrimino, arguments_t *arguments);

// check_tetriminos.c
tetri_t *check_folder(arguments_t *arguments, int nbr_tets);
char **remove_first_line(char **shape);
int check_lines(tetri_t *tetrimino, int lines);

// arguments_tetris.c
arguments_t *arguments_tetris(int ac, char **av, arguments_t *arguments);

// tetris_debug.c
void tetris_debug(arguments_t *arguments, tetri_t *tetrimino);

// tetris_game.c
void tetris_start(arguments_t *arguments, tetri_t *tetrimino);

// set_free.c
void free_all(arguments_t *arguments);

// manage_level.c
void manage_level_flag(arguments_t *arguments);

// map.c
void change_map_size(arguments_t *arguments);

// initialise.c
void initialise_arguments(arguments_t *arguments);
int share_nbr_tetris(int entry);
void initialise_ncurse(arguments_t *arguments);

// map_display.c
void display_map(arguments_t *arguments);

// ui_display.c
void display_stats(arguments_t *arguments, int level);
void display_title(void);

// tools_function.c
void *xmalloc(int size);

// key_entry.c
char get_input(arguments_t *arguments);

// start_input.c
int handle_actual(arguments_t *arguments, int size[2], int level);

// map_display.c
void display_map(arguments_t *arguments);

#endif /* !bs_tet */
