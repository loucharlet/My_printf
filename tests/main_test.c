#include "my.h"
#include <stdio.h>

#define PINK "\033[35m"
#define RESET "\033[0m"

int main(void)
{
    int age = 19;
    int len_my, len_real;

    my_printf("\n\n");
    my_printf("       ⡾⠲⠶⣤⣀⣠⣤⣤");
    my_printf(PINK "⣤⡿⠛⠿" RESET);
    my_printf("⡴⠾⠛⢻⡆\n");
    my_printf("      ⣼⠁⠀⠀⠀⠉⠁⠀");
    my_printf(PINK "⢀⣿⠐⡿⣿⠿⣶⣤⣤⣷⡀\n" RESET);
    my_printf("      ⢹⡶⠀⠀⠀⠀⠀⠀");
    my_printf(PINK "⠈⢯⣡⣿⣿⣀⣸⣿⣦⢓⡟\n" RESET);
    my_printf("     ⢀⡿⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀");
    my_printf(PINK "⠈⠉⠹⣍⣭⣾⠁\n" RESET);
    my_printf("    ⣀⣸⣇⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣸⣷⣤⡀\n");
    my_printf("  ⠈⠉⠹⣏⡁⠀ ⢸⣿⠀⠀   ⠀⠀⠀⣿⠆⠀⢀⣸⣇⣀\n");
    my_printf("   ⠐⠋⢻⣅⣄⢀⣀⣀⡀⠀ ");
    my_printf(PINK "⠯⠽" RESET);
    my_printf("  ⢀⣀⣀⡀⠀⣤⣿⠀⠉\n");
    my_printf("    ⠴⠛⠙⣳⠋⠉⠉⠙⣆⠀⠀ ⢰⡟⠉⠈⠙⢷⠟⠉⠙⠂\n");
    my_printf("        ⢻⣄⣠⣤⣴⠟⠛⠛⠛⢧⣤⣤⣀⡾⠁\n");

    my_printf(PINK "  ｡ﾟﾟ･｡･ﾟﾟ｡\n" RESET);
    my_printf(PINK "  ﾟ。 " RESET);
    my_printf("MY PRINTF LIBRARY\n");
    my_printf(PINK "  　ﾟ･｡･ﾟ\n\n" RESET);

    my_printf(PINK "⊹₊˚‧︵‿₊୨ᰔ୧₊‿︵‧˚₊⊹\n" RESET);

    // test width str
    my_printf("⋆.ೃ࿔ Nom (normal) : %s\n", "Zizou");
    my_printf("⋆.ೃ࿔ Nom (width)  : [%15s]\n", "Zizou");

    // test width nb int et double
    my_printf("⋆.ೃ࿔ Age (normal) : %d\n", age);
    my_printf("⋆.ೃ࿔ Age (width)  : [%10d]\n", age);
    my_printf("⋆.ೃ࿔ Temp(width)  : [%10i]\n", -5);

    // autres flags
    my_printf("⋆.ೃ࿔ Unsigned     : %u\n", 4294967295U);
    my_printf("⋆.ೃ࿔ Hexa Maj     : %X\n", 255);
    my_printf("⋆.ೃ࿔ Pointeur     : %p\n", &age);
    my_printf("⋆.ೃ࿔ Succès       : 100%% !\n");
    my_printf("⋆.ೃ࿔ Gauche (-)   : [%-10d] <-\n", 42);
    my_printf("⋆.ೃ࿔ Zero (0)     : [%010x]\n", 255);
    my_printf("⋆.ೃ࿔ Précision NB  : [%.5d]\n", 42);
    my_printf("⋆.ೃ࿔ Signe Plus    : [%+d]\n", 42);
    my_printf("⋆.ೃ࿔ Space         : [% d]\n", 42);
    my_printf("⋆.ೃ࿔ Hashtag Hexa  : [%#x]\n", 255);
    my_printf("⋆.ೃ࿔ Tronquage Str : [%.3s]\n", "Epitech");
    my_printf("⋆.ೃ࿔ Long int     : [%ld]\n", 2147483648L);
    my_printf("⋆.ೃ࿔ Short int    : [%hd]\n", 32767);

    my_printf(PINK "⊹₊˚‧︵‿₊୨ᰔ୧₊‿︵‧˚₊⊹\n\n" RESET);

    // test comptage
    my_printf(PINK "--- COMPARISON TEST ---\n" RESET);
    len_my = my_printf("test my_printf : [%10s] and [%5d]", "Epitech", 42);
    my_printf("\nMy return: %d\n", len_my);

    // comparaison printf

    len_real = printf("test og printf : [%10s] and [%5d]", "Epitech", 42);
    printf("\nReal return: %d\n", len_real);

    if (len_my == len_real)
        my_printf(PINK "\n  ⋆.ೃ࿔ ݁ MATCH ! ˖*༄\n" RESET);
    else
        my_printf("\n Difference!\n");

    return (0);
}