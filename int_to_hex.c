#include "libftprintf.h"

char *int_to_hex(int num, char *hex)
{
  char  *hex_num = (char *) malloc(sizeof(char) * 8);
    int i = 126;
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
