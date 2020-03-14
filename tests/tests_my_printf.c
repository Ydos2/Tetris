/*
** EPITECH PROJECT, 2019
** tests_my_printf
** File description:
** my_printf tests
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "libmy.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test (my_printf, simple_string, .init = redirect_all_std)
{
    my_printf("A simple string\n");
    cr_assert_stdout_eq_str("A simple string\n");
}

Test (my_printf, bad_string, .init = redirect_all_std)
{
    char *normal = "A normal string that behaves normally, unlike criterion";
    char *empty = NULL;

    my_printf(empty);
    cr_assert_stdout_neq_str(normal);
}

Test (my_printf, simple_str, .init = redirect_all_std)
{
    char *nice = "nice";

    my_printf("%s", nice);
    cr_assert_stdout_eq_str("nice");
}

Test (my_printf, simple_char, .init = redirect_all_std)
{
    char c = 'A';

    my_printf("%c", c);
    cr_assert_stdout_eq_str("A");
}

Test (my_printf, simple_number_i, .init = redirect_all_std)
{
    int nbr = 69;

    my_printf("%i", nbr);
    cr_assert_stdout_eq_str("69");
}

Test (my_printf, simple_number_d, .init = redirect_all_std)
{
    int nbr = 69;

    my_printf("%d", nbr);
    cr_assert_stdout_eq_str("69");
}

Test (my_printf, one_percent, .init = redirect_all_std)
{
    my_printf("%");
    cr_assert_stdout_eq_str("%");
}

Test (my_printf, peculiar_case, .init = redirect_all_std)
{
    my_printf("% ");
    cr_assert_stdout_eq_str("% ");
}

Test (my_printf, multiple_percents, .init = redirect_all_std)
{
    my_printf("%%%%%%%");
    cr_assert_stdout_eq_str("%%%%");
}

Test (my_printf, mix_of_all, .init = redirect_all_std)
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

Test (my_putnbr, small_negative, .init = redirect_all_std)
{
    int test = -2;
    int rtn = 0;

    rtn = my_putnbr(test);
    cr_assert_eq(rtn, 0);
}

Test (my_putstr, error_case, .init = redirect_all_std)
{
    char *str = NULL;
    int rtn = 0;

    rtn = my_putstr(str);
    cr_assert_eq(rtn, 84);
}