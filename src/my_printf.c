#include "my.h"

static const flags_t TYPE_LIST[] = {
    {'d', &my_put_nbr_va},
    {'i', &my_put_nbr_va},
    {'s', &my_putstr_va},
    {'c', &my_putchar_va},
    {'x', &my_puthex_va},
    {'X', &my_puthex_upper_va}, 
    {'o', &my_putoctal_va},
    {'b', &my_putbinary_va},
    {'p', &my_putpointer_va},  
    {'u', &my_putunsigned_va},
    {0, NULL}
};

int check_flags(char c, va_list *list, format_t *spec) 
{
    for (int i = 0; TYPE_LIST[i].c != 0; i++) {
        if (TYPE_LIST[i].c == c)
            return (TYPE_LIST[i].ptr(list, spec)); 
    }
    //si flag non reconnu
    int len = my_putchar('%');
    return (len);   
}

int my_printf(const char *format, ...)
{
    va_list list;
    int i = 0;
    int total_len = 0;
    format_t spec;

    va_start(list, format);
    while (format[i] != '\0') {
        if (format[i] == '%') {
            i++;
            // cas du %%
            if (format[i] == '%') {
                total_len += my_putchar('%');
            } else {
                // initialisation: précision à -1 
                spec = (format_t){0, -1, 0, 0, 0, 0, ' '}; 
                
                // 1. gestion des flags -,0, #, +, ' '
                while (format[i] == '-' || format[i] == '0' || 
                       format[i] == '#' || format[i] == '+' || format[i] == ' ') {
                    if (format[i] == '-') spec.left_align = 1;
                    if (format[i] == '0') spec.pad_char = '0';
                    if (format[i] == '#') spec.hash = 1;
                    if (format[i] == '+') spec.plus = 1;
                    if (format[i] == ' ') spec.space = 1;
                    i++;
                }
                
                // 2. lire width
                while (format[i] >= '0' && format[i] <= '9') {
                    spec.width = spec.width * 10 + (format[i] - '0');
                    i++;
                }

                // 3. lire précision
                if (format[i] == '.') {
                    i++;
                    spec.precision = 0;
                    while (format[i] >= '0' && format[i] <= '9') {
                        spec.precision = spec.precision * 10 + (format[i] - '0');
                        i++;
                    }
                }

                // lire la longueur (h ou l)
                if (format[i] == 'h') {
                    spec.length = 1; // short
                    i++;
                } else if (format[i] == 'l') {
                    spec.length = 2; // long
                    i++;
                }
                
                // appel du handler avec structure complète
                total_len += check_flags(format[i], &list, &spec);
            }
        } else {
            total_len += my_putchar(format[i]);
        }
        i++;
    }
    va_end(list);
    return (total_len);
}