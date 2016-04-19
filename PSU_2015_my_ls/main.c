#include <dirent.h>
#include <stdlib.h>
#include "my.h"
#include "main.h"
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

void	my_ls(int ac, char **av, int *tab, int i)
{
  if (ac == 1)
    my_ls1(".", tab);
  else if (ac == 2)
    my_ls1(av[i], tab);
  else if (ac > 2)
    my_ls3(ac, av, i, tab);
}

void	search_o2(char a, int *tab)
{
  if (a == 'l')
    tab[0] = 1;
  else if (a == 'R')
    tab[1] = 1;
  else if (a == 'd')
    tab[2] = 1;
  else if (a == 'r')
    tab[3] = 1;
  else
    tab[4] = 1;
}

void	search_option(int ac, char **av, int *tab)
{
  int	i;
  int	j;

  i = 1;
  j = 1;
  while (i < ac)
    {
      if (av[i][0] == '-')
	{
	  while (av[i][j] != '\0')
	    {
	      search_o2(av[i][j], tab);
	      j++;
	    }
	  j = 1;
	}
      i++;
    }
}

int	main(int ac, char **av)
{
  int	i;
  int	*tab;

  i = 0;
  tab = malloc(sizeof(int) * 5);
  while (i < 5)
    {
      tab[i] = 0;
      i++;
    }
  check_error(ac, av);
  search_option(ac, av, tab);
  i = deter_start(&ac, av);
  my_ls(ac, av, tab, i);
  return (0);
}
