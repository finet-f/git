#include <unistd.h>
#include <stdlib.h>
#include "coord.h"
#include "make_tab.h"
#include "my.h"

int	**my_malloc(int **tab, int nb_lines, int l)
{
  int	i;

  i = 0;
  while (i < nb_lines)
    {
      tab[i] = malloc(sizeof(int) * l);
      if (tab[i] == NULL)
	exit(1);
      i++;
    }
  return (tab);
}

int	check_is_square(t_coord coord, char **map)
{
  int	k;
  int	m;
  int	save;

  k = 1;
  m = 1;
  save = coord.j;
  while (k <= coord.size)
    {
      while (m <= coord.size)
	{
	  if (map[coord.i][coord.j] == 'o')
	    return (0);
	  coord.j++;
	  m++;
	}
      coord.j = save;
      m = 1;
      coord.i++;
      k++;
    }
  return (1);
}

void		init_tab2(char **map, int **tab, int nb_lines, int i)
{
  int		r;
  int		l;
  t_coord	coord;
  int		j;

  r = 0;
  l = my_strlen(map[0]);
  coord = init_coord(coord);
  j = l - 2;
  while (j >= 0)
    {
      if ((nb_lines - i) > (l - j))
	coord.size = l - j;
      else
	coord.size = nb_lines - i;
      while (coord.size > 0 && r != 1)
	{
	  coord.i = i;
	  coord.j = j;
	  r = check_is_square(coord, map);
	  coord.size--;
	}
      tab[i][j] = coord.size + 1;
      coord.size = 1;
      r = 0;
      j--;
    }
}

int	**init_tab(char **map, int nb_lines)
{
  int	i;
  int	l;
  int	**tab;

  i = nb_lines - 2;
  l = my_strlen(map[0]);
  tab = malloc(sizeof(int *) * nb_lines);
  if (tab == NULL)
    exit(1);
  tab = my_malloc(tab, nb_lines, l);
  init_one(tab, nb_lines, l);
  init_zero(map, tab);
  while (i >= 0)
    {
      init_tab2(map, tab, nb_lines, i);
      i--;
    }
  return (tab);
}
