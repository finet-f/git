#include "coord.h"

t_square	init_square(t_square square)
{
  square.i = 0;
  square.j = 0;
  square.size = 0;
  return (square);
}

t_coord	init_coord(t_coord coord)
{
  coord.i = 0;
  coord.j = 0;
  coord.size = 1;
  return (coord);
}

void	init_one(int **tab, int nb_lines, int l)
{
  int	i;

  i = 0;
  while (i < (nb_lines - 1))
    {
      tab[i][l - 1] = 1;
      i++;
    }
  i = 0;
  while (i < l)
    {
      tab[nb_lines - 1][i] = 1;
      i++;
    }
}

void	init_zero(char **map, int **tab)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (map[i][0] != '\0')
    {
      while (map[i][j] != '\0')
	{
	  if (map[i][j] == 'o')
	    tab[i][j] = 0;
	  j++;
	}
      j = 0;
      i++;
    }
}
