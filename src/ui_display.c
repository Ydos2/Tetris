/*
** EPITECH PROJECT, 2020
** ui_display
** File description:
** ui_display
*/

#include <ncurses.h>
#include "libmy.h"
#include "tetris.h"

void display_cbt(void)
{
    attron(COLOR_PAIR(3));
    mvprintw(5, 85, "        ");
    mvprintw(6, 85, "  ");
    mvprintw(7, 85, "  ");
    mvprintw(8, 85, "  ");
    mvprintw(9, 85, "        ");
    attron(COLOR_PAIR(5));
    mvprintw(5, 96, "    ");
    mvprintw(6, 96, "  ");
    mvprintw(6, 100, "  ");
    mvprintw(7, 96, "    ");
    mvprintw(8, 96, "  ");
    mvprintw(8, 100, "  ");
    mvprintw(9, 96, "    ");
    attron(COLOR_PAIR(4));
    mvprintw(5, 105, "        ");
    mvprintw(6, 108, "  ");
    mvprintw(7, 108, "  ");
    mvprintw(8, 108, "  ");
    mvprintw(9, 108, "  ");
}

void display_title3(void)
{
    attron(COLOR_PAIR(1));
    mvprintw(5, 48, "  ");
    mvprintw(6, 48, "  ");
    mvprintw(7, 48, "  ");
    mvprintw(8, 48, "  ");
    mvprintw(9, 48, "  ");
    attron(COLOR_PAIR(2));
    mvprintw(5, 52, "        ");
    mvprintw(6, 52, "  ");
    mvprintw(7, 52, "        ");
    mvprintw(8, 58, "  ");
    mvprintw(9, 52, "        ");
    attron(COLOR_PAIR(3));
    mvprintw(5, 62, "        ");
    mvprintw(6, 62, "  ");
    mvprintw(7, 62, "        ");
    mvprintw(8, 68, "  ");
    mvprintw(9, 62, "        ");
}

void display_title2(void)
{
    attron(COLOR_PAIR(5));
    mvprintw(5, 28, "        ");
    mvprintw(6, 31, "  ");
    mvprintw(7, 31, "  ");
    mvprintw(8, 31, "  ");
    mvprintw(9, 31, "  ");
    attron(COLOR_PAIR(6));
    mvprintw(5, 38, "        ");
    mvprintw(6, 38, "  ");
    mvprintw(6, 44, "  ");
    mvprintw(7, 38, "        ");
    mvprintw(8, 38, "  ");
    mvprintw(8, 42, "  ");
    mvprintw(9, 38, "  ");
    mvprintw(9, 44, "  ");
}

void display_title(void)
{
    attron(COLOR_PAIR(3));
    mvprintw(5, 10, "        ");
    mvprintw(6, 13, "  ");
    mvprintw(7, 13, "  ");
    mvprintw(8, 13, "  ");
    mvprintw(9, 13, "  ");
    attron(COLOR_PAIR(4));
    mvprintw(5, 20, "      ");
    mvprintw(6, 20, "  ");
    mvprintw(7, 20, "    ");
    mvprintw(8, 20, "  ");
    mvprintw(9, 20, "      ");
    display_title2();
    display_title3();
    attron(COLOR_PAIR(4));
    display_cbt();
}

void display_stats(arguments_t *arguments, int level)
{
    mvprintw(14, 14, "Score :\t\t%06d", arguments->score);
    mvprintw(16, 14, "High score :\t%06d", arguments->high_score);
    mvprintw(18, 14, "Level :\t\t    %02d", level);
}