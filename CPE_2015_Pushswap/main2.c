#include "main2.h"

int	find_littlest(int *l_a, int k)
{
  int	i;
  int	save;

  i = 1;
  save = 0;
  while (i < k)
    {
      if (l_a[i] < l_a[save])
	save = i;
      i++;
    }
  return (save);
}

void	exec_ra(int *l_a, int tab[3], int o, int *l_b)
{
  int	i;

  i = 0;
  while (i < tab[1])
    {
      if (o == 0)
	ra(l_a, tab[0], tab[2]);
      else if (o == 1)
	ra_v(l_a, tab[0], l_b, tab[2]);
      i++;
    }
}

int	*exec_pb(int *l_a, int *l_b, int *tab_k[2], int o)
{
  if (o == 0)
    l_b = pb(l_a, l_b, tab_k[0], tab_k[1]);
  else if (o == 1)
    l_b = pb_v(l_a, l_b, tab_k[0], tab_k[1]);
  return (l_b);
}

int	*exec_pa(int *l_a, int *l_b, int *tab_k[2], int o)
{
  if (o == 0)
    l_a = pa(l_a, l_b, tab_k[0], tab_k[1]);
  else if (o == 1)
    l_a = pa_v(l_a, l_b, tab_k[0], tab_k[1]);
  return (l_a);
}
