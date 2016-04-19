#include <stdlib.h>
#include "my.h"

void	check_error3(int ac, char **av)
{
  if (av[1][1] == 'v' && av[ac - 1][1] == 'v')
    {
      my_printf("Error : double option\n");
      exit(-1);
    }
  if (ac == 2 && av[1][1] == 'v')
    {
      my_printf("Error : no list\n");
      exit(-1);
    }
}
void	check_error2(int ac, char **av, char a)
{
  int	i;

  i = 1;
  if (av[ac - 1][0] == '-' && av[ac - 1][1] != 'v' && (a != 't' || a != '\0'))
    {
      if (av[ac - 1][1] < 48 || av[ac - 1][1] > 57)
	{
	  my_printf("Error : invalid option\n");
	  exit(-1);
	}
    }
  check_error3(ac, av);
  i++;
  while (i < (ac - 1))
    {
      if (av[i][0] == '-' && (av[i][1] < 48 || av[i][1] > 57))
	{
	  my_printf("Error : option inside list\n");
	  exit(-1);
	}
      i++;
    }
}

void	check_error(int ac, char **av)
{
  char	b;
  char	a;

  if (ac == 1)
    {
      my_printf("Error : no list\n");
      exit(-1);
    }
  b = av[1][2];
  a = av[ac - 1][2];
  if (av[1][0] == '-' && av[1][1] != 'v' && (b != 't' || b != '\0'))
    {
      if (av[1][1] < 48 || av[1][1] > 57)
	{
	  my_printf("Error : invalid option\n");
	  exit(-1);
	}
    }
  check_error2(ac, av, a);
}
