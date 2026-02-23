#include "my.h"
#include <stdio.h>

#define PINK  "\033[35m"
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
    
   // test width
    my_printf("⋆.ೃ࿔ Nom (normal) : %s\n", "Zizou");
    my_printf("⋆.ೃ࿔ Nom (width)  : [%15s]\n", "Zizou");

    // 2. TEST WIDTH SUR NOMBRES (Alignement à 10)
    my_printf("⋆.ೃ࿔ Age (normal) : %d\n", age);
    my_printf("⋆.ೃ࿔ Age (width)  : [%10d]\n", age);
    my_printf("⋆.ೃ࿔ Temp(width)  : [%10i]\n", -5);

    // 3. AUTRES FLAGS (Vérifie qu'ils sont dans ton TYPE_LIST !)
    my_printf("⋆.ೃ࿔ Unsigned     : %u\n", 4294967295U); 
    my_printf("⋆.ೃ࿔ Hexa Maj     : %X\n", 255); 
    my_printf("⋆.ೃ࿔ Pointeur     : %p\n", &age); 
    my_printf("⋆.ೃ࿔ Succès       : 100%% !\n");
    
    my_printf(PINK "⊹₊˚‧︵‿₊୨ᰔ୧₊‿︵‧˚₊⊹\n\n" RESET);

    // 4. TEST DE COMPTAGE (LEN)
    my_printf(PINK "--- COMPARISON TEST ---\n" RESET);
    len_my = my_printf("Test: [%10s] and [%5d]", "Epitech", 42);
    my_printf("\nMy return: %d\n", len_my);
    
    // Comparaison avec le vrai printf pour être sûr
    // (Affiche sur une nouvelle ligne pour ne pas casser ton visuel)
    len_real = printf("Test: [%10s] and [%5d]", "Epitech", 42);
    printf("\nReal return: %d\n", len_real);

    if (len_my == len_real)
        my_printf(PINK "\n  ⋆.ೃ࿔ ݁ PERFECT MATCH ! ˖*༄\n" RESET);
    else
        my_printf("\n  ⚠️ Difference detected !\n");

    return (0);
}