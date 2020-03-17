/*
** EPITECH PROJECT, 2019
** tests_my_printf
** File description:
** tests_my_printf_modulo
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "libmy.h"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test (my_putnbr_get, small_negative, .init = redirect_all_std)
{
    int test = -2;
    int rtn = 0;

    rtn = my_putnbr(test);
    cr_assert_eq(rtn, 0);
}

Test (my_putstr_str, error_case, .init = redirect_all_std)
{
    char *str = NULL;
    int rtn = 0;

    rtn = my_putstr(str);
    cr_assert_eq(rtn, 84);
}

Test (my_putnbr_test, small_negative, .init = redirect_all_std)
{
    int test = -2;
    int rtn = 0;

    rtn = my_putnbr(test);
    cr_assert_eq(rtn, 0);
}

Test (my_putstr_rtn, error_case, .init = redirect_all_std)
{
    char *str = NULL;
    int rtn = 0;

    rtn = my_putstr(str);
    cr_assert_eq(rtn, 84);
}