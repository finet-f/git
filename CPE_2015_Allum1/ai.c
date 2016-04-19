#include <stdlib.h>
#include "tab.h"
#include "ai.h"
#include "my.h"

int	select_line(char **map, int r)
{
  int	i;
  int	j;
  int	m;
  int	k;

  i = 1;
  k = 0;
  while (map[i + 1] != NULL && map[i][1] != '*')
    {
      j = 1;
      m = 0;
      while (map[i][j + 1])
	{
	  if (map[i][j] == '|')
	    m = 1;
	  j++;
	}
      if (m == 1)
	k++;
      if (k == r)
	return (i);
      i++;
    }
  return (i);
}

int	count_match_on_line(char **map, int line)
{
  int	i;
  int	l;

  i = 1;
  l = 0;
  while (map[line][i + 1])
    {
      if (map[line][i] == '|')
	l++;
      i++;
    }
  return (l);
}

void	just_one_line(int line, char **map, t_tab size, int *match)
{
  *match = count_match_on_line(map, line);
  if (*match > 1)
    *match -= 1;
  replace_map(map, line, *match, size);
}

int	ai_turn2(t_tab size, int *nbm, char **map, int *match)
{
  int	r;
  int	line;

  if (nbm[1] != 1)
    while ((r = rand() % nbm[1]) == 0);
  else
    r = 1;
  line = select_line(map, r);
  if (r == 1)
    {
      just_one_line(line, map, size, &*match);
      return (line);
    }
  r = rand() % 2;
  *match = count_match_on_line(map, line);
  if (r == 0)
    replace_map(map, line, *match, size);
  else
    {
      if (*match != 1)
	while ((*match = rand() % *match) == 0);
      replace_map(map, line, *match, size);
    }
  return (line);
}

void	ai_turn(char **map, t_tab size)
{
  int	*nbm;
  int	line;
  int	match;

  match = 1;
  my_printf("\nAI's turn...\n");
  nbm = my_count_match(map);
  if (nbm[0] <= 2)
    {
      line = search_match(map);
      replace_map(map, line, 1, size);
    }
  else
    line = ai_turn2(size, nbm, map, &match);
  free(nbm);
  my_printf("AI removed %d match(es) from line %d\n", match, line);
}
