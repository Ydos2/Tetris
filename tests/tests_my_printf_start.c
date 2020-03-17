/*
** EPITECH PROJECT, 2019
** tests_my_printf
** File description:
** tests_my_printf_start
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "libmy.h"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test (my_printf_simple_str, simple_string, .init = redirect_all_std)
{
    my_printf("A simple string\n");
    cr_assert_stdout_eq_str("A simple string\n");
}

Test (my_printf_normal_str, bad_string, .init = redirect_all_std)
{
    char *normal = "A normal string that behaves normally, unlike criterion";
    char *empty = NULL;

    my_printf(empty);
    cr_assert_stdout_neq_str(normal);
}

Test (my_printf_nice, simple_str, .init = redirect_all_std)
{
    char *nice = "nice";

    my_printf("%s", nice);
    cr_assert_stdout_eq_str("nice");
}

Test (my_printf_a, simple_char, .init = redirect_all_std)
{
    char c = 'A';

    my_printf("%c", c);
    cr_assert_stdout_eq_str("A");
}