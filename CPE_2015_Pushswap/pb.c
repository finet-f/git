#include <stdlib.h>
#include "my.h"
#include "pb.h"

int	*pb(int *l_a, int *l_b, int *ka, int *kb)
{
  int	*tmp;
  int	i;
  int	j;

  i = 1;
  j = 0;
  tmp = malloc(sizeof(int) * (*kb + 1));
  tmp = my_copy_int(tmp, l_b, &*kb);
  free(l_b);
  tmp[0] = l_a[0];
  while (i < *ka)
    {
      l_a[j] = l_a[i];
      i++;
      j++;
    }
  *ka = *ka - 1;
  my_printf("pb ");
  return (tmp);
}

int	*pb_v(int *l_a, int *l_b, int *ka, int *kb)
{
  int	*tmp;
  int	i;
  int	j;

  i = 1;
  j = 0;
  tmp = malloc(sizeof(int) * (*kb + 1));
  tmp = my_copy_int(tmp, l_b, &*kb);
  free(l_b);
  tmp[0] = l_a[0];
  while (i < *ka)
    {
      l_a[j] = l_a[i];
      i++;
      j++;
    }
  *ka = *ka - 1;
  my_printf("pb ");
  aff_v(l_a, tmp, *ka, *kb);
  return (tmp);
}
