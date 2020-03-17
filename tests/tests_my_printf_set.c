/*
** EPITECH PROJECT, 2019
** tests_my_printf
** File description:
** tests_my_printf_set
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "libmy.h"

static void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test (my_printf_69, simple_number_i, .init = redirect_all_std)
{
    int nbr = 69;

    my_printf("%i", nbr);
    cr_assert_stdout_eq_str("69");
}

Test (my_printf_69_int, simple_number_d, .init = redirect_all_std)
{
    int nbr = 69;

    my_printf("%d", nbr);
    cr_assert_stdout_eq_str("69");
}

Test (my_printf_solo_modulo, one_percent, .init = redirect_all_std)
{
    my_printf("%");
    cr_assert_stdout_eq_str("%");
}

Test (my_printf_space_modulo, peculiar_case, .init = redirect_all_std)
{
    my_printf("% ");
    cr_assert_stdout_eq_str("% ");
}