#include <stdarg.h>
#include <stdlib.h>
#include "include/my_printf.h"

void	my_printf_S(char *str)
{
  int	i;
  int	r;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] >= 32 && str[i] < 127)
	my_putchar(str[i]);
      else
	{
	  my_putchar(92);
	  r = (int)str[i];
	  dec_to_oct_S(r);
	}
      i = i + 1;
    }
}

void		my_printf_u(unsigned int nb)
{
  my_put_nbr_u(nb);
}

int	get_fl(char a,
	       void (*ptr[MY_SIZE])(va_list ap),
	       va_list ap)
{
  int	i;
  char	*flags;

  i = 0;
  flags = "dicsbSxXoupl";
  ptr[0] = &print_d_i;
  ptr[1] = &print_d_i;
  ptr[2] = &print_c;
  ptr[3] = &print_s;
  ptr[4] = &print_b;
  ptr[5] = &print_S;
  ptr[6] = &print_x;
  ptr[7] = &print_X;
  ptr[8] = &print_o;
  ptr[9] = &print_u;
  ptr[10] = &print_p;
  ptr[11] = &print_l;
  while (flags[i] != a && i < MY_SIZE)
    i = i + 1;
  if (i == MY_SIZE)
    return (-1);
  ptr[i](ap);
  return (0);
}

int	my_print(char *str, 
		 int *i, 
		 void (*ptr[MY_SIZE])(va_list ap), 
		 va_list ap)
{
  int	r;

  if (str[*i] != '%')
    my_putchar(str[*i]);
  else if (str[*i] == '%' && str[*i + 1] == '%')
    {
      my_putchar(str[*i]);
      *i = *i + 1;
    }
  else
    {
      *i = *i + 1;
      r = get_fl(str[*i], ptr, ap);
      if (r == -1 && str[*i - 1] != '%')
	return (-1);
      else if (r == -1 && str[*i - 1] == '%')
	{
	  my_putchar('%');
	  *i = *i - 1;
	}
      if (str[*i] == 'l' && str[*i + 1] == 'd')
	*i = *i + 1;
    }
  return (0);
}

void		my_printf(char *str, ...)
{
  int		i;
  va_list	ap;
  void		(*ptr[MY_SIZE])(va_list ap);
  int		r;

  i = 0;
  va_start(ap, str);
  while (str[i] != '\0')
    {
      r = my_print(str, &i, ptr, ap);
      if (r == -1)
	return ;
      i = i + 1;
    }
  va_end(ap);
}
