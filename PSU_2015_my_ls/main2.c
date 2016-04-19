#include <stdlib.h>
#include <dirent.h>
#include "my.h"
#include "main2.h"

void	my_ls31(int ac, char **av, int i)
{
  DIR	*dirp;

  while (i < ac)
    {
      dirp = opendir(av[i]);
      if (dirp == NULL)
	my_printf("ls: cannot access %s: No such file or directory\n", av[i]);
      closedir(dirp);
      i++;
    }
}

int		my_ls32(char **av, int i, int *tab)
{
  DIR		*dirp;
  t_dirent	*entry;

  dirp = opendir(av[i]);
  if (dirp == NULL)
    return (1);
  my_printf("%s:\n", av[i]);
  if (tab[3] == 1)
    option_r(av[i], tab);
  else
    {
      entry = readdir(dirp);
      while (entry != NULL)
	{
	  if (entry->d_name[0] != '.')
	    option_l(entry->d_name, tab, av[i]);
	  entry = readdir(dirp);
	}
    }
  closedir(dirp);
  return (0);
}

int	check_end(int ac, int i, char **av)
{
  DIR	*dirp;

  while (i < ac)
    {
      dirp = opendir(av[i]);
      if (dirp != NULL)
	return (1);
      closedir(dirp);
      i++;
    }
  return (0);
}

void	my_ls3(int ac, char **av, int i, int *tab)
{
  int	r;

  ac = ac + i - 1;
  my_ls31(ac, av, i);
  while (i < ac)
    {
      r = my_ls32(av, i, tab);
      if (check_end(ac, (i + 1), av) == 1 && r == 0)
	my_printf("\n");
      i++;
    }
}

int	deter_start(int *ac, char **av)
{
  int	i;
  int	save;

  save = *ac;
  i = 1;
  while (i < save && av[i][0] == '-')
    {
      i++;
      *ac = *ac - 1;
    }
  return (i);
}
