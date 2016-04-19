#include <stdarg.h>

int     my_put_nbr_u(unsigned int nb)
{
  if (nb > 9)
    {
      my_put_nbr(nb / 10);
      my_putchar(nb % 10 + 48);
    }
  else if (nb <= 9)
    {
      my_putchar(nb % 10 + 48);
    }
  return (0);
}

void	print_l(va_list ap)
{
  my_put_nbr_long(va_arg(ap, long));
}

void	my_print_p(int nb)
{
  if (nb == 0)
    {
      my_putstr("(nil)");
      return ;
    }
  my_putstr("0x");
  dec_to_hex(nb, 'x');
}

void	my_putstr_pf(char *str)
{
  int	i;

  i = 0;
  if (str == 0)
    return ;
  while (str[i] != '\0')
    {
      my_putchar(str[i]);
      i++;
    }
}

void            dec_to_oct_S(int nb)
{
  int           p;
  unsigned int  res;

  p = 1;
  res = 0;
  while ((nb / 8) != 0)
    {
      res = res + nb % 8 * p;
      nb = nb / 8;
      p = p * 10;
    }
  if ((nb % 8) != 0)
    res = res + nb % 8 * p;
  if ((res / 100) == 0)
    my_putchar('0');
  if ((res / 10) == 0)
    my_putchar('0');
  my_put_nbr(res);
}
