#include <unistd.h>
#include <stdlib.h>
#include "rsize.h"
#include "tab.h"
#include "my.h"

int	my_analysis(char buff[R_SIZE])
{
  int	i;

  i = 0;
  while (buff[i] != 0 && buff[i] != '\n')
    {
      if (buff[i] < '0' || buff[i] > '9')
	{
	  my_printf("Error: invalid input (positive number expected)\n");
	  return (1);
	}
      i++;
    }
  return (0);
}

int	my_analysis_line2(t_tab size, char buff[R_SIZE])
{
  int	nb;

  nb = my_getnbr(buff);
  if (buff[0] == '\0' || buff[0] == '\n')
    {
      my_printf("Error: invalid input (positive number expected)\n");
      return (1);
    }
  if (my_analysis(buff) == 1)
    return (1);
  if (nb < 0)
    {
      my_printf("Error: invalid input (positive number expected)\n");
      return (1);
    }
  if (nb == 0 || nb > height - 2)
    {
      my_printf("Error: this line is out of range\n");
      return (1);
    }
  return (0);
}

int	my_analysis_line(t_tab size, char buff[R_SIZE], char **map)
{
  int	nb;
  int	nbm;
  int	i;

  nbm = 0;
  i = 0;
  if (my_analysis_line2(size, buff) == 1)
    return (1);
  nb = my_getnbr(buff);
  while (map[nb][i])
    {
      if (map[nb][i] == '|')
	nbm++;
      i++;
    }
  if (nbm == 0)
    {
      my_printf("Error: this line is empty\n");
      return (1);
    }
  return (0);
}

int	my_analysis_match2(int nb, char buff[R_SIZE])
{
  if (buff[0] == '\0' || buff[0] == '\n')
    {
      my_printf("Error: invalid input (positive number expected)\n");
      return (1);
    }
  if (nb < 0)
    {
      my_printf("Error: invalid input (positive number expected)\n");
      return (1);
    }
  if (nb == 0)
    {
      my_printf("Error: you have to remove at least one match\n");
      return (1);
    }
  return (0);
}

int	my_analysis_match(char buff[R_SIZE], int line, char **map)
{
  int	nb;
  int	nbm;
  int	i;

  i = 0;
  nbm = 0;
  nb = my_getnbr(buff);
  if (my_analysis(buff) == 1)
    return (1);
  if (my_analysis_match2(nb, buff) == 1)
    return (1);
  while (map[line][i])
    {
      if (map[line][i] == '|')
	nbm++;
      i++;
    }
  if (nb > nbm)
    {
      my_printf("Error: not enough matches on this line\n");
      return (1);
    }
  return (0);
}
