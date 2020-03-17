/*
** EPITECH PROJECT, 2020
** tetris_debug
** File description:
** tetris_debug
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "bstetris.h"
#include "libmy.h"

char *configure_key_display(char c)
{
    char *str = NULL;

    if (c == 68)
        return (my_strdup("^EOD"));
    if (c == 67)
        return (my_strdup("^EOC"));
    if (c == 65)
        return (my_strdup("^EOA"));
    if (c == 66)
        return (my_strdup("^EOB"));
    if (c == 32)
        return (my_strdup("(space)"));
    str = my_itostr(1);
    str[0] = c;
    return (str);
}

void key_display(arguments_t *arguments)
{
    my_putstr("Key Left : ");
    my_printf("%c", arguments->key_left);
    my_putstr("\nKey Right : ");
    my_printf("%c", arguments->key_right);
    my_putstr("\nKey Turn : ");
    my_printf("%c", arguments->key_turn);
    my_putstr("\nKey Drop : ");
    my_printf("%c", arguments->key_drop);
    my_putstr("\nKey Quit : ");
    my_printf("%c", arguments->key_quit);
    my_putstr("\nKey Pause : ");
    my_printf("%c", arguments->key_pause);
    my_putstr("\nNext : ");
    if (arguments->without_next)
        my_putstr("Yes");
    else
        my_putstr("No");
}

void tetriminos_display(arguments_t *arguments)
{
    (void)arguments;
}

void tetris_debug(arguments_t *arguments)
{
    char *line = NULL;

    my_putstr("*** DEBUG MODE ***\n");
    key_display(arguments);
    my_putstr("\nLevel : ");
    my_putnbr(arguments->Level);
    my_putstr("\nSize : ");
    my_putnbr(arguments->map_size_x);
    my_putstr("*");
    my_putnbr(arguments->map_size_y);
    my_putstr("\nTetriminos : ");
    //my_put_nbr(arguments->);
    my_putchar('\n');
    //tetriminos_display(arguments);
    my_putstr("Press any key to start Tetris\n");
    line = get_next_line(0);
    free(line);
}