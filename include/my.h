#ifndef MY_H_
#define MY_H_

#include <stdarg.h>
#include <unistd.h>

// pointeur sur fonctions format+flag
typedef struct format_s {
    int width;
    int left_align; // flag '-'
    char pad_char;  // ' ' ou '0'
} format_t;

typedef struct flags_s {
    char c;
    int (*ptr)(va_list *, format_t *); 
} flags_t;

// fonctions
int my_printf(const char *format, ...);
// Correction ici : check_flags doit prendre format_t *
int check_flags(char c, va_list *list, format_t *spec);

// outils de base
int my_putchar(char c);
int my_put_nbr(int nb);
int my_putstr(char const *str);
int my_putnbr_base(unsigned long nbr, char const *base);
char *my_itoa(long nb);

// va handlers 
// Tous les handlers doivent maintenant prendre format_t *spec
int my_putchar_va(va_list *list, format_t *spec);
int my_putstr_va(va_list *list, format_t *spec);
int my_put_nbr_va(va_list *list, format_t *spec);
int my_puthex_va(va_list *list, format_t *spec);
int my_puthex_upper_va(va_list *list, format_t *spec);
int my_putoctal_va(va_list *list, format_t *spec);
int my_putbinary_va(va_list *list, format_t *spec);
int my_putpointer_va(va_list *list, format_t *spec);
int my_putunsigned_va(va_list *list, format_t *spec);

#endif /* !MY_H_ */