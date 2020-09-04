/*
** PERSONAL PROJECT, 2020
** UWU
** File description:
** test_crit
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>

#include <cstdlib>

Test(void, void)
{
    system("./UWU");

    cr_redirect_stdout();
}

