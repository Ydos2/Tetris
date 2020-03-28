/*
** EPITECH PROJECT, 2020
** key_entry
** File description:
** key_entry
*/

#include <unistd.h>
#include <stdlib.h>
#include <ncurses.h>
#include "tetris.h"
#include "libmy.h"

int verif_key(arguments_t *arguments, char buff[128])
{
    if (my_strncmp(&arguments->key_left, buff, my_strlen(buff)) == 0 ||
        my_strncmp(&arguments->key_right, buff, my_strlen(buff)) == 0 ||
        my_strncmp(&arguments->key_turn, buff, my_strlen(buff)) == 0 ||
        my_strncmp(&arguments->key_drop, buff, my_strlen(buff)) == 0 ||
        my_strncmp(&arguments->key_quit, buff, my_strlen(buff)) == 0 ||
        my_strncmp(&arguments->key_pause, buff, my_strlen(buff)) == 0 ||
        !my_strncmp(buff, &arguments->key_left,
        my_strlen(&arguments->key_left)) ||
        !my_strncmp(buff, &arguments->key_right,
        my_strlen(&arguments->key_right)) ||
        !my_strncmp(buff, &arguments->key_turn,
        my_strlen(&arguments->key_turn)) ||
        !my_strncmp(buff, &arguments->key_drop,
        my_strlen(&arguments->key_drop)) ||
        !my_strncmp(buff, &arguments->key_quit,
        my_strlen(&arguments->key_quit)) ||
        !my_strncmp(buff, &arguments->key_pause,
        my_strlen(&arguments->key_pause)))
        return (1);
    return (0);
}

int enter_key(char key, char buff)
{
    if (key == buff)
        return (1);
    return (0);
}

char get_input(arguments_t *arguments)
{
    char buffu = getch();

    return (enter_key(arguments->key_left, buffu) ? arguments->key_left :
        enter_key(arguments->key_right, buffu) ? arguments->key_right :
        enter_key(arguments->key_turn, buffu) ? arguments->key_turn :
        enter_key(arguments->key_drop, buffu) ? arguments->key_drop :
        enter_key(arguments->key_quit, buffu) ? arguments->key_quit :
        enter_key(arguments->key_pause, buffu) ? arguments->key_pause : 0);
}