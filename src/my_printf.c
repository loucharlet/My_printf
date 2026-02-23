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
    if (spec->width > 0) len += my_put_nbr(spec->width);
    len += my_putchar(c);
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
            if (format[i] == '%') {
                total_len += my_putchar('%');
            } else {
                spec = (format_t){0, 0, ' '}; //reset si trouve %
                
                //gestion des flags '-' et '0'
                while (format[i] == '-' || format[i] == '0') {
                    if (format[i] == '-') spec.left_align = 1;
                    if (format[i] == '0') spec.pad_char = '0';
                    i++;
                }
                
                while (format[i] >= '0' && format[i] <= '9') {
                    spec.width = spec.width * 10 + (format[i] - '0');
                    i++;
                }
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