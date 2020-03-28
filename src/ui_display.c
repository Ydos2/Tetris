/*
** EPITECH PROJECT, 2020
** ui_display
** File description:
** ui_display
*/

#include <ncurses.h>
#include "libmy.h"
#include "tetris.h"

void Display_title3(void)
{
    attron(COLOR_PAIR(5));
    mvprintw(5, 48, "  ");
    mvprintw(6, 48, "  ");
    mvprintw(7, 48, "  ");
    mvprintw(8, 48, "  ");
    mvprintw(9, 48, "  ");
    attron(COLOR_PAIR(6));
    mvprintw(5, 52, "        ");
    mvprintw(6, 52, "  ");
    mvprintw(7, 52, "        ");
    mvprintw(8, 58, "  ");
    mvprintw(9, 52, "        ");
}

void Display_title2(void)
{
    attron(COLOR_PAIR(3));
    mvprintw(5, 28, "        ");
    mvprintw(6, 31, "  ");
    mvprintw(7, 31, "  ");
    mvprintw(8, 31, "  ");
    mvprintw(9, 31, "  ");
    attron(COLOR_PAIR(4));
    mvprintw(5, 38, "        ");
    mvprintw(6, 38, "  ");
    mvprintw(6, 44, "  ");
    mvprintw(7, 38, "        ");
    mvprintw(8, 38, "  ");
    mvprintw(8, 42, "  ");
    mvprintw(9, 38, "  ");
    mvprintw(9, 44, "  ");
}

void Display_title(void)
{
    attron(COLOR_PAIR(1));
    mvprintw(5, 10, "        ");
    mvprintw(6, 13, "  ");
    mvprintw(7, 13, "  ");
    mvprintw(8, 13, "  ");
    mvprintw(9, 13, "  ");
    attron(COLOR_PAIR(2));
    mvprintw(5, 20, "      ");
    mvprintw(6, 20, "  ");
    mvprintw(7, 20, "    ");
    mvprintw(8, 20, "  ");
    mvprintw(9, 20, "      ");
    Display_title2();
    Display_title3();
}

void Display_stats(arguments_t *arguments, int level)
{
    mvprintw(14, 18, "Score :\t%07d", arguments->score);
    mvprintw(16, 18, "High score :\t%07d", arguments->high_score);
    mvprintw(20, 18, "Level :\t     %02d", level);
}