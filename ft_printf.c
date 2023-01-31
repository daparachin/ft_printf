#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>


void    ft_putchar_fd(char c, int fd)
{
    write(fd, &c, 1);
}

void    ft_putstr_fd(char *s, int fd)
{
    int    i;

    i = 0;
    while (s[i])
    {
        write(fd, &s[i], 1);
        i++;
    }
}

void    ft_putnbr_fd(int n, int fd)
{
    if (n == -2147483648)
    {
        write(fd, "-2147483648", 11);
    }
    else if (n < 0)
    {
        ft_putchar_fd('-', fd);
        n = -n;
        ft_putnbr_fd(n, fd);
    }
    else if (n > 9)
    {
        ft_putnbr_fd(n / 10, fd);
        ft_putnbr_fd(n % 10, fd);
    }
    else
        ft_putchar_fd(n + 48, fd);
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
            char sign = format[i+1];
            
            if (sign == 'c')
                ft_putchar_fd(va_arg(arg_list, int), 1);
            if (sign == 's')
                ft_putstr_fd(va_arg(arg_list,char *), 1);
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
            i++;
        }
        i++;
    }
    va_end(arg_list);
    return (0);
}




int main()
{
    char  v = 'v';
    int   num = 12987783;
    char *a = "byl";
    char *b = "Praze";
    char *c = "tri";
    char *d = "jsem";
    char *e = "dneska";
    char *f = "sest";
    char *g = "sedm";
    
    ft_printf("Já %s %s dnes %c %s %d %%",d,a,v,b,num);
    return 0;
}
