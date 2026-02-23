#include "my.h"
#include <stdlib.h>
#include <unistd.h>

char *my_itoa(long nb)
{
    int len = 0;
    char *str;

    if (nb <= 0) len++; 
    for (long n = (nb < 0 ? -nb : nb); n > 0; n /= 10) len++;
    
    str = malloc(sizeof(char) * (len + 1));
    if (!str) return (NULL);
    str[len] = '\0';
    if (nb == 0) str[0] = '0';
    if (nb < 0) {
        str[0] = '-';
        nb = -nb;
    }
    while (nb > 0) {
        str[--len] = (nb % 10) + '0';
        nb /= 10;
    }
    return (str);
}

int my_putchar(char c)
{
    write(1, &c, 1);
    return (1);
}

int my_putstr(char const *str)
{
    int i = 0;
    if (!str) {
        write(1, "(null)", 6);
        return (6);
    }
    while (str[i]) {
        my_putchar(str[i]);
        i++;
    }
    return (i);
}

int my_put_nbr(int nb)
{
    int count = 0;
    long n = nb;

    if (n < 0) {
        count += my_putchar('-');
        n = -n;
    }
    if (n >= 10) {
        count += my_put_nbr(n / 10);
    }
    count += my_putchar((n % 10) + '0');
    return (count);
}

int my_putnbr_base(unsigned long nbr, char const *base)
{
    int len = 0;
    unsigned long base_len = 0;
    while (base[base_len]) base_len++;
    if (nbr >= base_len)
        len += my_putnbr_base(nbr / base_len, base);
    len += my_putchar(base[nbr % base_len]);
    return (len);
}

//variadic argement handlers

int my_putchar_va(va_list *list, format_t *spec)
{
    char c = (char)va_arg(*list, int);
    int count = 0;

    if (!spec->left_align) {
        while (count < (spec->width - 1)) {
            write(1, " ", 1);
            count++;
        }
    }
    count += my_putchar(c);
    if (spec->left_align) {
        while (count < spec->width) {
            write(1, " ", 1);
            count++;
        }
    }
    return (count);
}

int my_putstr_va(va_list *list, format_t *spec)
{
    char *str = va_arg(*list, char *);
    int count = 0;
    int len = 0;

    if (!str) str = "(null)";
    while (str[len]) len++;

    // TRONQUAGE:si la précision est définie (>= 0),len réduit
    if (spec->precision >= 0 && spec->precision < len)
        len = spec->precision;

    // padding before
    if (!spec->left_align) {
        while (count < (spec->width - len)) {
            write(1, " ", 1);
            count++;
        }
    }

    for (int i = 0; i < len; i++)
        my_putchar(str[i]);
    count += len;

    // padding left
    if (spec->left_align) {
        while (count < spec->width) {
            write(1, " ", 1);
            count++;
        }
    }
    return (count);
}

int my_put_nbr_va(va_list *list, format_t *spec)
{
    long nb;

    if (spec->length == 2)
        nb = va_arg(*list, long);
    else if (spec->length == 1)
        nb = (short)va_arg(*list, int);
    else
        nb = va_arg(*list, int);

    char *str = my_itoa(nb < 0 ? -nb : nb); 
    int len = 0;

    while (str[len]) len++;
    int prec_zeros = (spec->precision > len) ? spec->precision - len : 0;
    int total_len = len + prec_zeros + (nb < 0 || spec->plus || spec->space ? 1 : 0);
    int count = 0;

    //padding before
    if (!spec->left_align) {
        while (count < (spec->width - total_len)) 
            count += my_putchar(spec->pad_char);
    }

    // affichage signe
    if (nb < 0) 
        count += my_putchar('-');
    else if (spec->plus) 
        count += my_putchar('+');
    else if (spec->space) 
        count += my_putchar(' ');

    //affichage zero de précision
    while (prec_zeros-- > 0) count += my_putchar('0');

    count += my_putstr(str);

    // padding left
    if (spec->left_align) {
        while (count < spec->width) count += my_putchar(' ');
    }
    free(str);
    return count;
}

int my_putbase_width_va(unsigned long n, char *base, format_t *spec)
{
    int count = 0;
    int len = 0;
    unsigned long base_len = 0;
    while (base[base_len]) base_len++;

    //len du nb
    unsigned long t = n;
    if (t == 0) len = 1;
    while (t > 0) { t /= base_len; len++; }

    //flag # -> on ajoute 2 a len pour ("0x")
    int prefix_len = (spec->hash && n != 0 && (base[10] == 'a' || base[10] == 'A')) ? 2 : 0;
    
    // Padding before
    if (!spec->left_align) {
        while (count < (spec->width - (len + prefix_len)))
            count += my_putchar(spec->pad_char);
    }

    //affichage de 0x
    if (prefix_len) count += my_putstr(base[10] == 'A' ? "0X" : "0x");

    count += my_putnbr_base(n, base);

    //Padding left
    if (spec->left_align) {
        while (count < spec->width)
            count += my_putchar(' ');
    }
    return (count);
}

int my_puthex_va(va_list *list, format_t *spec)
{
    unsigned long n;
    if (spec->length == 2) n = va_arg(*list, unsigned long);
    else if (spec->length == 1) n = (unsigned short)va_arg(*list, unsigned int);
    else n = va_arg(*list, unsigned int);
    return (my_putbase_width_va(n, "0123456789abcdef", spec));
}

int my_puthex_upper_va(va_list *list, format_t *spec)
{
    unsigned long n;
    if (spec->length == 2) n = va_arg(*list, unsigned long);
    else if (spec->length == 1) n = (unsigned short)va_arg(*list, unsigned int);
    else n = va_arg(*list, unsigned int);
    return (my_putbase_width_va(n, "0123456789ABCDEF", spec));
}

int my_putoctal_va(va_list *list, format_t *spec)
{
    unsigned long n;
    if (spec->length == 2) n = va_arg(*list, unsigned long);
    else if (spec->length == 1) n = (unsigned short)va_arg(*list, unsigned int);
    else n = va_arg(*list, unsigned int);
    return (my_putbase_width_va(n, "01234567", spec));
}

int my_putbinary_va(va_list *list, format_t *spec)
{
    unsigned long n;
    if (spec->length == 2) n = va_arg(*list, unsigned long);
    else if (spec->length == 1) n = (unsigned short)va_arg(*list, unsigned int);
    else n = va_arg(*list, unsigned int);
    return (my_putbase_width_va(n, "01", spec));
}

int my_putpointer_va(va_list *list, format_t *spec)
{
    void *ptr = va_arg(*list, void *);
    unsigned long addr = (unsigned long)ptr;
    int len = 2; //gestion pointeur "0x"
    unsigned long tmp = addr;
    int count = 0;

    if (!ptr) return (my_putstr("(nil)"));
    while (tmp > 0) {
        tmp /= 16;
        len++;
    }
    if (!spec->left_align) {
        while (count < (spec->width - len)) {
            write(1, " ", 1);
            count++;
        }
    }
    count += my_putstr("0x");
    count += my_putnbr_base(addr, "0123456789abcdef");
    if (spec->left_align) {
        while (count < spec->width) {
            write(1, " ", 1);
            count++;
        }
    }
    return (count);
}

int my_putunsigned_va(va_list *list, format_t *spec)
{
    unsigned long n;
    if (spec->length == 2) n = va_arg(*list, unsigned long);
    else if (spec->length == 1) n = (unsigned short)va_arg(*list, unsigned int);
    else n = va_arg(*list, unsigned int);
    return (my_putbase_width_va(n, "0123456789", spec));
}