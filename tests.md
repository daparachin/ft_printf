// Online C compiler to run C program online
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h> 


int count_args(const char *format)
{
    int i;
    int count;

    i = 0;
    while (format[i] != '\0')
    {
        if (format[i] == '%')
            {
              count++;  
            }
    }
    return (count);
}

void    ft_putstrn(char *str)
{
    int i;
    i = 0;
    while(str[i] != '\0')
    {
        write(1,&str[i],1);
        i++;
    }    
 }
int ft_printf(const char *format,...)
{
    
    va_list arg_list;
    int arg_count;
    int i;
    
    arg_count = count_args(format);
    va_start(arg_list, arg_count);
    
    //while (arg_list)

    i = 0;
    while (i++ < arg_count)
    {
        ft_putstrn(va_arg(arg_list,char *));
    }
    return (0);
}

int main() 
{
    char *a = "jedna";
    char *b = "dva";
    char *c = "tri";
    char *d = "ctyr";
    char *e = "pet";
    char *f = "sest";
    char *g = "sedm";
    
    // Write C code here
    ft_printf("ahoj % %",a, b);
    return 0;
}
