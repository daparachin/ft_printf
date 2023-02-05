
#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft/libft.h"

int ft_printf(const char *format,...);
char *int_to_hex(int num, char *hex);
void    print_pointer_hex(void *pointer);

#endif
