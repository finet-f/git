#include "coord.h"
#include "my.h"
#include "main2.h"

void	disp_tab(int **tab, int nb_lines)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (i < nb_lines)
    {
      while (j < nb_lines)
	{
	  my_printf("%d ", tab[i][j]);
	  j++;
	}
      j = 0;
      i++;
      my_printf("\n");
    }
}

void	disp_map(char **map)
{
  int	i;

  i = 0;
  while (map[i][0] != '\0')
    {
      my_printf("%s\n", map[i]);
      i++;
    }
}

void	replace_by_x(char **map, t_square square)
{
  int	k;
  int	m;
  int	save;

  k = 1;
  m = 1;
  save = square.j;
  while (k <= square.size)
    {
      while (m <= square.size)
	{
	  if (map[square.i][square.j] == '.')
	    map[square.i][square.j] = 'x';
	  square.j++;
	  m++;
	}
      square.j = save;
      m = 1;
      square.i++;
      k++;
    }
}

void		my_bsq(char **map, int nb_lines, int **tab)
{
  t_square	square;
  int		i;
  int		j;
  int		l;

  i = 0;
  j = 0;
  l = my_strlen(map[0]);
  square = init_square(square);
  while (i < nb_lines)
    {
      while (j < l)
	{
	  if (tab[i][j] > square.size)
	    {
	      square.size = tab[i][j];
	      square.i = i;
	      square.j = j;
	    }
	  j++;
	}
      j = 0;
      i++;
    }
  replace_by_x(map, square);
}
