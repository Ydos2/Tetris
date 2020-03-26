/*
** EPITECH PROJECT, 2019
** help_page.c
** File description:
** navy's help_page
*/

#include <unistd.h>

int print_help(void)
{
    write(1, "Usage:\t./tetris [options]\nOptions:\n --help\t\t\tDisplay", 52);
    write(1, " this help\n -L --level={num}\tStart Tetris at level -l", 53);
    write(1, " num (def: 1)\n --key-left={K}\tMove the tetrimino LEFT", 53);
    write(1, " using the K key (def: left arrow)\n -r --key-right={K}", 53);
    write(1, "\tMove the tetrimino RIGHT using the K key (def: right", 53);
    write(1, " arrow)\n -t --key-turn={K}\tTURN the tetrimino clockwise ", 56);
    write(1, "90d using the K key (def: top arrow)\n -d --key-drop={K}\t", 56);
    write(1, "DROP the tetrimino using the K key (def: down arrow)\n", 53);
    write(1, " -q --key-quit={K}\tQUIT the game using the K key", 48);
    write(1, " (def: 'q' key)\n -p --key-pause={K}\tPAUSE/RESTART the ", 54);
    write(1, "game using the K key (def: space bar)\n", 38);
    write(1, " --map-size={row,col}\tSet the numbers of rows", 45);
    write(1, " and columns of the map (def: 20,10)\n", 37);
    write(1, " -w --without-next\tHide next tetrimino (def: false)\n", 53);
    write(1, " -D --debug\t\tDebug mode (def: false)\n", 36);
    return (0);
}