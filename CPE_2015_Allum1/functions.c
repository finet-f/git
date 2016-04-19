#include <unistd.h>
#include <stdlib.h>
#include "tab.h"
#include "functions.h"
#include "my.h"

void	end_game(int turn, char **map)
{
  free(map);
  if (turn == 0)
    turn = 1;
  else
    turn = 0;
  if (turn == 0)
    my_printf("You lost, too bad..\n");
  else
    my_printf("I lost.. snif.. but I'll get you next time!!\n");
}

int	check_is_end(char **map)
{
  int	i;
  int	j;

  i = 1;
  j = 1;
  while (map[i + 1] != NULL)
    {
      while (map[i][j])
	{
	  if (map[i][j] == '|')
	    return (0);
	  j++;
	}
      j = 1;
      i++;
    }
  return (1);
}

void	replace_map(char **map, int line, int match, t_tab size)
{
  int	i;
  int	j;

  i = width - 2;
  while (map[line][i] == ' ')
    i--;
  j = i - match;
  while (i > j)
    {
      map[line][i] = ' ';
      i--;
    }
}

void	my_putstrtab(char **tab, int size)
{
  int	i;

  i = 0;
  while (i < size)
    {
      my_putstr(tab[i]);
      my_putchar('\n');
      i++;
    }
}

void	choose_turn(char **map, t_tab size, int *turn)
{
  if (*turn == 0)
    {
      user_turn(map, size);
      *turn = 1;
    }
  else
    {
      ai_turn(map, size);
      *turn = 0;
    }
}
