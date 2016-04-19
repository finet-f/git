#include "my.h"
#include <stdlib.h>

void	check_error3(int ac, char **av)
{
  int	i;

  i = 1;
  while (i < ac && av[i][0] == '-')
    i++;
  while (i < ac)
    {
      if (av[i][0] == '-')
	{
	  my_printf("Usage : ls [-lRdrt] [FILE]\n");
	  exit(1);
	}
      i++;
    }
}

void	check_error2(char tmp)
{
  if (tmp != 'l' && tmp != 'r' && tmp != 'R' && tmp != 'd' && tmp != 't')
    {
      my_printf("ls: invalid option -- \'%c\'\n", tmp);
      my_printf("Try 'ls --help' for more information.\n");
      exit(1);
    }
}

void	check_error(int ac, char **av)
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
	      check_error2(av[i][j]);
	      j++;
	    }
	  j = 1;
	}
      i++;
    }
  check_error3(ac, av);
}
