#include <stdlib.h>
#include "my.h"
#include "pa.h"

int	*my_copy_int(int *dest, int *src, int *k)
{
  int	i;
  int	j;

  i = 1;
  j = 0;
  while (j < *k)
    {
      dest[i] = src[j];
      i++;
      j++;
    }
  *k = *k + 1;
  return (dest);
}

int	*pa(int *l_a, int *l_b, int *ka, int *kb)
{
  int	*tmp;
  int	i;
  int	j;

  i = 1;
  j = 0;
  tmp = malloc(sizeof(int) * (*ka + 1));
  tmp = my_copy_int(tmp, l_a, &*ka);
  free(l_a);
  tmp[0] = l_b[0];
  while (i < *kb)
    {
      l_b[j] = l_b[i];
      i++;
      j++;
    }
  *kb = *kb - 1;
  my_printf("pa");
  if (*kb != 0)
    my_putchar(' ');
  return (tmp);
}

int	*pa_v(int *l_a, int *l_b, int *ka, int *kb)
{
  int	*tmp;
  int	i;
  int	j;

  i = 1;
  j = 0;
  tmp = malloc(sizeof(int) * (*ka + 1));
  tmp = my_copy_int(tmp, l_a, &*ka);
  free(l_a);
  tmp[0] = l_b[0];
  while (i < *kb)
    {
      l_b[j] = l_b[i];
      i++;
      j++;
    }
  *kb = *kb - 1;
  my_printf("pa ");
  aff_v(tmp, l_b, *ka, *kb);
  return (tmp);
}
