/*
** EPITECH PROJECT, 2020
** libmy.h
** File description:
** All lib functions
*/

#ifndef _LIBMY_H_
#define _LIBMY_H_
#include <stdbool.h>

#ifndef READ_SIZE
#define READ_SIZE (3)
#endif /* READ_SIZE */

typedef struct val {
    char *buff_inter;
    int turn;
    int carac;
} val_t;

// get_next_line.c
char *get_next_line(int fd);

void my_free_array(char **array);
void my_putarray(char **tab, char separation);

int my_putchar(char c);
int my_putstr(char *str);
int my_strlen(char *str);
int my_putnbr(int nb);
int my_printf(char *format, ...);
int my_strcmp(char *s1, char *s2);
int my_strncmp(char *s1, char *s2, int n);
int my_is_nbr(char c, char exception);
int my_is_str_nbr(char *str, char exception);
int my_getnbr(char *str);
int my_freegetnbr(char *str);
int my_is_alphap(char c, char exception);
int my_is_stralphap(char *str, char c);
int get_array_len(char **src);
int find_nbr_lines(char *str, char c, int len);

char *my_strcat(char *dest, char const *src);
char *my_strcatt(char *dest, char *src);
char *my_strcpy(char *dest, char *src);
char *my_strdup(char *src);
char *my_stradd(char *src, char *add);
char *my_calloc(int size);

char **my_str_to_array(char *str, char c);
char **my_arraydup(char **src);
char **add_line_array(char **src, char *line);
char **rm_line_array(char **src, int line);

bool my_strequbool(char *str1, char *str2);
char *my_itostr(unsigned int size);

void my_memset(char *str, int n, char c);

#endif