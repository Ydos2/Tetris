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
/*
int verif_key(t_tetris *core, char buff[128])
{
    if (my_strncmp(core->keys.left, buff, my_strlen(buff)) == 0 ||
        my_strncmp(core->keys.right, buff, my_strlen(buff)) == 0 ||
        my_strncmp(core->keys.turn, buff, my_strlen(buff)) == 0 ||
        my_strncmp(core->keys.drop, buff, my_strlen(buff)) == 0 ||
        my_strncmp(core->keys.quit, buff, my_strlen(buff)) == 0 ||
        my_strncmp(core->keys.pause, buff, my_strlen(buff)) == 0 ||
        !my_strncmp(buff, core->keys.left, my_strlen(core->keys.left)) ||
        !my_strncmp(buff, core->keys.right, my_strlen(core->keys.right)) ||
        !my_strncmp(buff, core->keys.turn, my_strlen(core->keys.turn)) ||
        !my_strncmp(buff, core->keys.drop, my_strlen(core->keys.drop)) ||
        !my_strncmp(buff, core->keys.quit, my_strlen(core->keys.quit)) ||
        !my_strncmp(buff, core->keys.pause, my_strlen(core->keys.pause)))
        return (1);
    return (0);
}

int enter_key(char *key, char buff[128])
{
    if (my_strncmp(key, buff, my_strlen(key)) == 0)
    {
        my_memset(buff, 128, 0);
        return (1);
    }
    return (0);
}

int get_input(arguments_t *arguments)
{
    static char buff[128];
    static int call = 0;
    char tmp[128];
    int n = 0;

    if (call == 0) {
        my_memset(buff, 128, 0);
        call = 1;
    }
    if ((n = read(0, tmp, 127)) < 0)
        return (84);
    tmp[n] = 0;
    my_strcat(buff, tmp);
    if (!verif_key(arguments, buff)) {
        my_memset(buff, 128, 0);
        return (0);
    }
    return (enter_key(arguments->keys_left, buff) ? KEY__LEFT :
        enter_key(arguments->keys_right, buff) ? KEY__RIGHT :
        enter_key(arguments->keys_turn, buff) ? KEY__TURN :
        enter_key(arguments->keys_drop, buff) ? KEY__DROP :
        enter_key(arguments->keys_quit, buff) ? KEY__QUIT :
        enter_key(arguments->keys_pause, buff) ? KEY__PAUSE : 0);
}*/