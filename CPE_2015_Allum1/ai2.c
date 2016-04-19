#include <stdlib.h>

int	*my_count_match(char **map)
{
  int	i;
  int	j;
  int	*l;
  int	save;

  l = malloc(sizeof(int) * 2);
  i = 1;
  l[0] = 0;
  l[1] = 0;
  while (map[i + 1] != NULL && map[i][1] != '*')
    {
      j = 1;
      save = l[0];
      while (map[i][j + 1])
	{
	  if (map[i][j] == '|')
	    l[0]++;
	  j++;
	}
      if (l[0] != save)
	l[1]++;
      i++;
    }
  return (l);
}

int	search_match(char **map)
{
  int	i;
  int	j;

  i = 1;
  j = 1;
  while (map[i + 1] != NULL && map[i][1] != '*')
    {
      while (map[i][j + 1])
	{
	  if (map[i][j] == '|')
	    return (i);
	  j++;
	}
      i++;
      j = 1;
    }
  return (0);
}
