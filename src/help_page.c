/*
** EPITECH PROJECT, 2019
** help_page.c
** File description:
** navy's help_page
*/

#include <unistd.h>

void draw_help(void)
{
    write(1, "Usage:\t./tetris [options]\n", 26);
    write(1, "Options:\n", 9);
    write(1, " --help\t\t\tDisplay this help\n", 27);
    write(1, " -L --level={num}\tStart Tetris at level num (def: 1)\n", 53);
    write(1, " -l --key-left={K}\tMove the tetrimino ", 38);
    write(1, "LEFT using the K key (def: left arrow)\n", 39);
    write(1, " -r --key-right={K}\tMove the tetrimino ", 39);
    write(1, "RIGHT using the K key (def: right arrow)\n", 41);
    write(1, " -t --key-turn={K}\tTURN the tetrimino ", 38);
    write(1, "clockwise 90d using the K key (def: top arrow)\n", 47);
    write(1, " -d --key-drop={K}\tDROP the tetrimino ", 38);
    write(1, "using the K key (def: down arrow)\n", 34);
    write(1, " -q --key-quit={K}\tQUIT the game using ", 39);
    write(1, "the K key (def: 'q' key)\n", 25);
    write(1, " -p --key-pause={K}\tPAUSE/RESTART the ", 38);
    write(1, "game using the K key (def: space bar)\n", 38);
    write(1, " --map-size={row,col}\tSet the numbers of rows", 45);
    write(1, " and columns of the map (def: 20,10)\n", 37);
    write(1, " -w --without-next\tHide next tetrimino (def: false)\n", 53);
    write(1, " -D --debug\t\tDebug mode (def: false)\n", 36);
}