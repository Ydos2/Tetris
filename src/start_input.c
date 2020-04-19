/*
** EPITECH PROJECT, 2020
** start_input
** File description:
** start_input
*/

#include <unistd.h>
#include <stdlib.h>
#include <ncurses.h>
#include "tetris.h"
#include "libmy.h"

int handle_sys(char input, arguments_t *arguments, int size[2])
{
    if (input == arguments->key_quit)
        return (-1);
    if (input == arguments->key_pause) {
        if (arguments->pause == 0)
            arguments->pause = 1;
        else if (arguments->pause == 1)
            arguments->pause = 0;
    }
    return (0);
}

int handle_input(arguments_t *arguments, int size[2])
{
    char input = get_input(arguments);

    if (input == arguments->key_left)
        arguments->pos_actu_x -= 1;
    if (input == arguments->key_right)
        arguments->pos_actu_x += 1;
    if (input == arguments->key_turn) {
    }
    return (handle_sys(input, arguments, size));
}

int actual_input(arguments_t *arguments, int size[2])
{
    int ret = handle_input(arguments, size);

    if (ret)
        return (ret);
    return (0);
}

int handle_actual(arguments_t *arguments, int size[2], int level)
{
    return (actual_input(arguments, size));
}