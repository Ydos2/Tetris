/*
** EPITECH PROJECT, 2020
** map
** File description:
** map
*/

#include <stdlib.h>
#include "libmy.h"
#include "tetris.h"

char *boarder_line(int x)
{
    char *line = NULL;

    line = malloc(sizeof(char) * (x + 3));
    if (line == NULL)
        return (NULL);
    line[0] = '+';
    for (int j = 1; j < (x + 1); j++)
        line[j] = '-';
    line[x + 1] = '+';
    line[x + 2] = '\0';
    return (line);
}

char *empty_line(int x)
{
    char *empty_line = NULL;

    empty_line = malloc(sizeof(char) * (x + 3));
    if (empty_line == NULL)
        return (NULL);
    empty_line[0] = '|';
    for (int j = 1; j < (x + 1); j++)
        empty_line[j] = ' ';
    empty_line[x + 1] = '|';
    empty_line[x + 2] = '\0';
    return (empty_line);
}

char **create_empty_map(arguments_t *arguments)
{
    int y = arguments->map_size_y;
    char **empty_map = NULL;

    empty_map = malloc(sizeof(char *) * (y + 3));
    if (empty_map == NULL)
        return (NULL);
    empty_map[0] = boarder_line(arguments->map_size_x);
    if (empty_map[0] == NULL)
        return (NULL);
    for (int i = 1; i < (y + 1); i++) {
        empty_map[i] = empty_line(arguments->map_size_x);
        if (empty_map[i] == NULL)
            return (NULL);
    }
    empty_map[y + 1] = boarder_line(arguments->map_size_x);
    if (empty_map[y + 1] == NULL)
        return (NULL);
    empty_map[y + 2] = NULL;
    return (empty_map);
}

void change_map_size(arguments_t *arguments)
{
    (void)arguments;
}