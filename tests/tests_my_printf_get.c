/*
** EPITECH PROJECT, 2019
** tests_my_printf
** File description:
** tests_my_printf_get
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "libmy.h"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test (my_printf_modulo, multiple_percents, .init = redirect_all_std)
{
    my_printf("%%%%%%%");
    cr_assert_stdout_eq_str("%%%%");
}

Test (my_printf_carater, mix_of_all, .init = redirect_all_std)
{
    int i = 777;
    int k = -42;
    char *str = "My name Jeff";
    char c = '\n';
    char *smile = "This is the way";
    char z = 'L';

    my_printf("%s %i %s %% loool%c%%%c  %i", smile, i, str, c, z, k);
    cr_assert_stdout_eq_str("This is the way 777 My name Jeff %loool\n%L  -42");
}

Test (my_putchar, error_case, .init = redirect_all_std)
{
    char c = '\0';
    int rtn = 0;

    rtn = my_putchar(c);
    cr_assert_eq(rtn, 84);
}

Test (my_putnbr, out_of_bounds, .init = redirect_all_std)
{
    int test = -2147483648;
    int rtn = 0;

    rtn = my_putnbr(test);
    cr_assert_eq(rtn, 84);
}