#include <stdlib.h>

void	dec_to_bin(int nb)
{
  int	i;
  char	res[50];

  if (nb < 0)
    nb = -nb;
  i = 0;
  while ((nb / 2) > 0)
    {
      res[i] = nb % 2;
      nb = nb / 2;
      i = i + 1;
    }
  res[i] = nb % 2;
  while (i >= 0)
    {
      my_putchar(res[i] + 48);
      i = i - 1;
    }
}

void	dec_to_oct(int nb)
{
  int	i;
  int	save;
  char	*res;

  save = nb;
  while (save / 10 != 0)
    {
      save = save / 10;
      i = i + 1;
    }
  res = malloc(i + 1);
  i = 0;
  while ((nb / 8) != 0)
    {
      res[i] = nb % 8;
      nb = nb / 8;
      i = i + 1;
    }
  if ((nb % 8) != 0)
    res[i] = nb % 8;
  res[i + 1] = '\0';
  while (i >= 0)
    {
      my_putchar(res[i] + 48);
      i = i - 1;
    }
}

void	dec_to_hex2(char c, char a)
{
  if (c > 57)
    {
      if (a == 'x')
	my_putchar(c + 39);
      else
	my_putchar(c + 7);
    }
  else
    my_putchar(c);
}

void	dec_to_hex3(int nb, char *str, int i, char a)
{
  while ((nb / 16) != 0)
    {
      str[i] = nb % 16 + 48;
      i = i + 1;
      nb = nb / 16;
    }
  if ((nb % 16) != 0)
    str[i] = nb % 16 + 48;
  else
    i = i - 1;
  while (i >= 0)
    {
      dec_to_hex2(str[i], a);
      i = i - 1;
    }
}

void	dec_to_hex(int nb, char a)
{
  int	i;
  int	save;
  char	*str;

  i = 0;
  if (nb < 0)
    nb = -nb;
  save = nb;
  if (nb == 0)
    {
      my_putchar('0');
      return ;
    }
  while ((save / 10) > 0)
    {
      save = save / 10;
      i = i + 1;
    }
  str = malloc(sizeof(char) * i + 1);
  i = 0;
  dec_to_hex3(nb, str, i, a);
}
