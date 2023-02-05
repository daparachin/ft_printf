#include "libftprintf.h"

void    print_pointer_hex(void *pointer)
{
    unsigned long    p;
    char            buffer[15];
    int                i;

    p = (unsigned long)pointer;
    buffer[0] = '0';
    buffer[1] = 'x';
    i = 13;
    while (i >= 2)
    {
        unsigned long hex = p & 0xF;
        if (hex >= 10)
            buffer[i] = hex + 'a' - 10;
        else
            buffer[i] = hex + '0';
        p >>= 4;
        --i;
    }
    ft_putstr_fd(buffer, 1);
}
