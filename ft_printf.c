#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include "libft.h"

void print_arg(va_list arg_list, char sign)
{
    if (sign == 'c')
        ft_putchar_fd(va_arg(arg_list, char *), 1);
    if (sign == 's')
        ft_putstrn_fd(va_arg(arg_list,char *), 1);
    if (sign == 'p')
        ft_putchar_fd('p', 1); //pointer
    if (sign == 'd')
        ft_putnbr_fd(va_arg(arg_list,int), 1);
    if (sign == 'i')
        ft_putnbr_fd(va_arg(arg_list,int), 1);
    if (sign == 'u')
        ft_putchar_fd('u', 1); //unsigned decimal
    if (sign == 'x')
        ft_putchar_fd('x', 1); //number in hexadecimal lowercase
    if (sign == 'X')
        ft_putchar_fd('X', 1); //number in hexadecimal uppercase
    if (sign == '%')
        ft_putchar_fd('%', 1);
}

int ft_printf(const char *format,...)
{
    
    va_list arg_list;
    int arg_count;
    int i;
    
    arg_count = 0;
    i = 0;
    while(format[i] != '\0')
    {
        if (format[i] == '%' && (format[i+1] != '%' && format[i-1] != '%'))
            arg_count++;
        i++;
    }
    
    va_start(arg_list, arg_count);
    i = 0;
    while(format[i] != '\0')
    {
        if (format[i] != '%')
            write(1,&format[i],1);
        else
        {
         print_arg(arg_list, format[i+1]);
         i++;
        }
        i++;
    }
    return (0);
}

int main()
{
    char  v = 'd';
    int   num = 123;
    char *a = "jedna";
    char *b = "dva";
    char *c = "tri";
    char *d = "ctyri";
    char *e = "pet";
    char *f = "sest";
    char *g = "sedm";
    
    ft_printf("testujeme %c %s %s %s %d %% testujeme blabla", v, b, c ,d, num);
    return 0;
}
