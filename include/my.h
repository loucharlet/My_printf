#ifndef MY_H_
    #define MY_H_

    #include <stdarg.h>
    #include <unistd.h>

//pointeur sur fontions
typedef struct flags_s {
    char c;                  
    int (*ptr)(va_list *, int);    
} flags_t;

//fonctions
int my_printf(const char *format, ...);
int check_flags(char c, va_list *list, int width);

//outils de base
int my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_putnbr_base(unsigned long nbr, char const *base);
char *my_itoa(long nb);

// va handlers
int my_putchar_va(va_list *list, int width);
int my_putstr_va(va_list *list, int width);
int my_put_nbr_va(va_list *list, int width);
int my_putchar_width_va(va_list *list, int width);
int my_putstr_width_va(va_list *list, int width);
int my_put_nbr_width_va(va_list *list, int width);
int my_puthex_va(va_list *list, int width);
int my_puthex_upper_va(va_list *list, int width);
int my_putoctal_va(va_list *list, int width);
int my_putbinary_va(va_list *list, int width);
int my_putpointer_va(va_list *list, int width);
int my_putunsigned_va(va_list *list, int width);

#endif /* !MY_H_ */