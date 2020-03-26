/*
** EPITECH PROJECT, 2020
** arguments_tetris
** File description:
** arguments_tetris
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "tetris.h"
#include "libmy.h"

char check_multitouch(void)
{
    if (my_strequbool(optarg, "rightk"))
        return (67);
    if (my_strequbool(optarg, "leftk"))
        return (68);
    if (my_strequbool(optarg, "topk"))
        return (65);
    if (my_strequbool(optarg, "downk"))
        return (66);
    return (0);
}

void change_key(int res, arguments_t *arguments)
{
    char multi = check_multitouch();

    multi = ((multi == 0) ? *optarg : multi);
    switch (res) {
        case 'l': arguments->key_left = multi;
            break;
        case 'r': arguments->key_right = multi;
            break;
        case 't': arguments->key_turn = multi;
            break;
        case 'd': arguments->key_drop = multi;
            break;
        case 'q': arguments->key_quit = multi;
            break;
        case 'p': arguments->key_pause = multi;
            default:
        break;
    }
}

void flag_action(int res, arguments_t *arguments)
{
    switch (res) {
        case 'D': arguments->debug = 1;
            break;
        case 'L': manage_level_flag(arguments);
            break;
        case 8: change_map_size(arguments);
            break;
        case '?':
            free_all(arguments);
            exit(84);
            break;
        default:
            if (res >= 0 && res <= 127 && optarg != NULL)
                change_key(res, arguments);
        break;
    }
}

arguments_t *arguments_tetris(int ac, char **av, arguments_t *arguments)
{
    int res = 0;
    char *shortopt = "+L:l:r:t:d:q:p:Dh";

    arguments = malloc(sizeof(arguments_t));
    initialise_arguments(arguments);
    opt_t opt[] = {
        { "without-next", no_argument, &arguments->without_next, 0 },
        { "level", required_argument, NULL, 'L' },
        { "key-left", required_argument, NULL, 'l' },
        { "key-right", required_argument, NULL, 'r' },
        { "key-turn", required_argument, NULL, 't' },
        { "key-drop", required_argument, NULL, 'd' },
        { "key-quit", required_argument, NULL, 'q' },
        { "key-pause", required_argument, NULL, 'p' },
        { "debug", no_argument, &arguments->debug, 1 },
        { "help", no_argument, NULL, 'h' },
        { "map-size", required_argument, NULL, 8 }
    };
    while (res >= 0) {
        res = getopt_long(ac, av, shortopt, opt, NULL);
        flag_action(res, arguments);
    }
    return (arguments);
}