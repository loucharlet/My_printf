#include "my.h"

static const flags_t TYPE_LIST[] = {
    {'d', &my_put_nbr_width_va},
    {'i', &my_put_nbr_width_va},
    {'s', &my_putstr_width_va},
    {'c', &my_putchar_width_va},
    {'x', &my_puthex_va},
    {'X', &my_puthex_upper_va}, 
    {'o', &my_putoctal_va},
    {'b', &my_putbinary_va},
    {'p', &my_putpointer_va},  
    {'u', &my_putunsigned_va},
    {0, NULL}
};

int check_flags(char c, va_list *list, int width) 
{
    for (int i = 0; TYPE_LIST[i].c != 0; i++) {
        if (TYPE_LIST[i].c == c)
            return (TYPE_LIST[i].ptr(list, width)); 
    }
    my_putchar('%');
    if (width > 0) my_put_nbr(width);
    my_putchar(c);
    return (2);   
}

int my_printf(const char *format, ...)
{
    va_list list;
    int i = 0;
    int total_len = 0;

    va_start(list, format);
    while (format[i] != '\0') {
        if (format[i] == '%') {
            i++;
            if (format[i] == '%') {
                total_len += my_putchar('%');
            } else {
                int width = 0;
                while (format[i] >= '0' && format[i] <= '9') {
                    width = width * 10 + (format[i] - '0');
                    i++;
                }
                total_len += check_flags(format[i], &list, width);
            }
        } else {
            total_len += my_putchar(format[i]);
        }
        i++;
    }
    va_end(list);
    return (total_len);
}