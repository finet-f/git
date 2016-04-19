#include "my.h"
#include "ra.h"

int	*ra(int *l_a, int k, int kb)
{
  int	tmp;
  int	i;
  int	j;

  tmp = l_a[0];
  i = 1;
  j = 0;
  while (i < k)
    {
      l_a[j] = l_a[i];
      i++;
      j++;
    }
  l_a[j] = tmp;
  my_printf("ra");
  if (check_sort(l_a, k) != 1 || kb != 0)
    my_putchar(' ');
  return (l_a);
}

int	*ra_v(int *l_a, int k, int *l_b, int kb)
{
  int	tmp;
  int	i;
  int	j;

  tmp = l_a[0];
  i = 1;
  j = 0;
  while (i < k)
    {
      l_a[j] = l_a[i];
      i++;
      j++;
    }
  l_a[j] = tmp;
  my_printf("ra ");
  aff_v(l_a, l_b, k, kb);
  return (l_a);
}
