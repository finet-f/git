#include <stdlib.h>
#include "my.h"
#include "main.h"

int	*deter_l_a(int agc, char **agv, int *k)
{
  int	i;
  int	j;
  int	*l_a;

  j = 0;
  i = 1;
  *k = agc - 1;
  l_a = malloc(sizeof(int) * (*k));
  if (agv[1][1] == 'v')
    {
      i = 2;
      *k = *k - 1;
    }
  else if (agv[agc - 1][1] == 'v')
    {
      agc = agc - 1;
      *k = *k - 1;
    }
  while (i < agc)
    {
      l_a[j] = my_getnbr(agv[i]);
      i++;
      j++;
    }
  return (l_a);
}

int	check_sort(int *l_a, int k)
{
  int	i;
  int	save;
  int	r;

  i = 1;
  r = 1;
  save = l_a[0];
  while (i < k)
    {
      if (l_a[i] < save)
	r = 0;
      save = l_a[i];
      i++;
    }
  return (r);
}

int	search_option(int ac, char **agv)
{
  int	o;

  if(agv[1][1] == 'v' || agv[ac - 1][1] == 'v')
    o = 1;
  else
    o = 0;
  return (o);
}

void	my_pushswap(int *l_a, int *l_b, int ka, int o)
{
  int	r;
  int	little;
  int	kb;
  int	tab_e_ra[3];
  int	*tab_k[2];

  r = 0;
  kb = 0;
  while (r == 0)
    {
      r = check_sort(l_a, ka);
      little = find_littlest(l_a, ka);
      tab_e_ra[0] = ka;
      tab_e_ra[1] = little;
      tab_e_ra[2] = kb;
      exec_ra(l_a, tab_e_ra, o, l_b);
      r = check_sort(l_a, ka);
      if (kb == 0 && r == 1)
	return ;
      tab_k[0] = &ka;
      tab_k[1] = &kb;
      if (r == 0)
	l_b = exec_pb(l_a, l_b, tab_k, o);
    }
  while (kb > 0)
    l_a = exec_pa(l_a, l_b, tab_k, o);
}

int	main(int ac, char **av)
{
  int	*l_a;
  int	*l_b;
  int	ka;
  int	o;

  ka = 0;
  check_error(ac, av);
  l_a = deter_l_a(ac, av, &ka);
  l_b = malloc(sizeof(int) * ka);
  o = search_option(ac, av);
  my_pushswap(l_a, l_b, ka, o);
  my_printf("\n");
  return (0);
}
