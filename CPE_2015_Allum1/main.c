#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "rsize.h"
#include "tab.h"
#include "main.h"
#include "my.h"

int	my_line(char **map, t_tab size)
{
  int	r;
  int	nb;
  char	buff[R_SIZE];

  my_printf("Line: ");
  while ((r = read(0, buff, R_SIZE - 1)) == 0);
  buff[r] = 0;
  if (my_analysis_line(size, buff, map) == 1)
    {
      nb = my_line(map, size);
      return (nb);
    }
  nb = my_getnbr(buff);
  return (nb);
}

int	my_match(char **map, int line)
{
  int	r;
  int	match;
  char	buff[R_SIZE];

  my_printf("Matches: ");
  while ((r = read(0, buff, R_SIZE - 1)) == 0);
  buff[r] = 0;
  if (my_analysis_match(buff, line, map) == 1)
    return (-1);
  match = my_getnbr(buff);
  return (match);
}

void	user_turn(char **map, t_tab size)
{
  int	line;
  int	match;
  int	m;

  m = 0;
  my_printf("\nYour turn:\n");
  while (m == 0)
    {
      line = my_line(map, size);
      if ((match = my_match(map, line)) != -1)
	m = 1;
    }
  replace_map(map, line, match, size);
  my_printf("Player removed %d match(es) from line %d\n", line, match);
}

int	main()
{
  char	**map;
  t_tab	size;
  int	turn;

  srand(time(NULL));
  height = 6;
  width = 9;
  if ((map = init_map(size)) == NULL)
    return (1);
  turn = 0;
  while (1)
    {
      my_putstrtab(map, height);
      if (check_is_end(map) == 1)
	{
	  end_game(turn, map);
	  return (0);
	}
      choose_turn(map, size, &turn);
    }
  return (0);
}
