#include "my.h"
#include "aff.h"

void	aff_v(int *l_a, int *l_b, int ka, int kb)
{
  int	i;

  i = 0;
  my_printf("(l_a : ");
  while (i < ka)
    {
      my_printf("%i ", l_a[i]);
      i++;
    }
  my_printf("; l_b : ");
  i = 0;
  while (i < kb)
    {
      my_printf("%i ", l_b[i]);
      i++;
    }
  my_printf(")");
  if (check_sort(l_a, ka) != 1 || kb != 0)
    my_printf(" ");
}
