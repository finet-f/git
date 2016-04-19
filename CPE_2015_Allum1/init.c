#include "my.h"
#include "tab.h"
#include <unistd.h>
#include <stdlib.h>

void	init_map3(t_tab size, char **map, int i, int j)
{
  while (j < width - 1)
    {
      map[i][j] = ' ';
      j++;
    }
}

void	init_map2(t_tab size, char **map)
{
  int	i;
  int	j;
  int	nb;

  i = height - 2;
  nb = 0;
  while (i >= 1)
    {
      j = 1;
      while (j < 1 + nb)
	{
	  map[i][j] = ' ';
	  j++;
	}
      while (j < width - nb - 1)
	{
	  map[i][j] = '|';
	  j++;
	}
      init_map3(size, map, i, j);
      nb++;
      i--;
    }
}

char	**init_map(t_tab size)
{
  char	**map;
  int	i;
  int	j;

  i = 0;
  if ((map = malloc(sizeof(char *) * height)) == NULL)
    return (NULL);
  while (i < height)
    {
      j = 1;
      if ((map[i] = malloc(sizeof(char) * (width + 1))) == NULL)
	return (NULL);
      map[i][0] = '*';
      map[i][width - 1] = '*';
      map[i][width] = 0;
      if (i == 0 || i == (height - 1))
	while (j < width - 1)
	  {
	    map[i][j] = '*';
	    j++;
	  }
      i++;
    }
  init_map2(size, map);
  return (map);
}
