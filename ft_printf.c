#include "libftprintf.h"

static void    find_correct_output(va_list arg_list, char sign)
{
            if (sign == 'c')
                ft_putchar_fd(va_arg(arg_list, int), 1);
            if (sign == 's')
                ft_putstr_fd(va_arg(arg_list,char *), 1);
            if (sign == 'p')
                print_pointer_hex(va_arg(arg_list,void *)); //pointer
            if (sign == 'd')
                ft_putnbr_fd(va_arg(arg_list,int), 1);
            if (sign == 'i')
                ft_putnbr_fd(va_arg(arg_list,int), 1);
            if (sign == 'u')
            {
                int x = va_arg(arg_list, int);
                ft_putnbr_fd((unsigned int)x, 1);
            }
            if (sign == 'x')
                ft_putstr_fd(int_to_hex(va_arg(arg_list,int),"0123456789abcdef"), 1);
            if (sign == 'X')
                ft_putstr_fd(int_to_hex(va_arg(arg_list,int),"0123456789ABCDEF"), 1);
            if (sign == '%')
                ft_putchar_fd('%', 1);
}


int ft_printf(const char *format,...)
{
    va_list arg_list;
    int i;

    va_start(arg_list, format);
    i = 0;
    while(format[i] != '\0')
    {
        if (format[i] != '%')
            write(1,&format[i],1);
        else
        {
            find_correct_output(arg_list, format[i+1]);
            i++;
        }
        i++;
    }
    va_end(arg_list);
    return (i);
}
