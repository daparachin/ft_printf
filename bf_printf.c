
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

char *int_to_hex(int num, char *hex)
{
  char  *hex_num = (char *) malloc(sizeof(char) * 8);
  int i = 126, j;
  hex_num[i] = '\0';
    
  while (num != 0 && i > 0)
  {
    i--;
    hex_num[i] = hex[num % 16];
    num /= 16;
  }
  if (i == 0)
    hex_num[i] = '0';
  else
  {
      int j = 0;
      while (j <= i)
      {
        hex_num[j] = hex_num[i + j];
        j++;
      }
      hex_num[j - 1] = '\0';
  }
  return (hex_num);
}

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


void    find_correct_output(va_list arg_list, char sign)
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
    return (0);
}
//PO %s musí být vždy mezera
int main()
{
    char  v = 'v';
    int   num = -42;
    float dec = 1.234;
    char *a = "byl";
    char *b = "Praze";
    char *c = "tri";
    char *d = "jsem";
    char *e = "dneska";
    char *f = "sest";
    char *g = "sedm";
    
    ft_printf("%s%s", "hello", "world");
    return 0;
}
