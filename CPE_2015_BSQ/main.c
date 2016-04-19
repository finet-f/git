#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include "my.h"
#include "main.h"
#include "size.h"

void	put_error_malloc(char *str)
{
  if (str == NULL)
    {
      my_printf("Error : map too big !");
      exit(1);
    }
}

char	**init_map2(char buff[SIZE], int i, int *l, int nb_lines)
{
  int	j;
  char	**map;

  j = 0;
  map = malloc(sizeof(char *) * (nb_lines + 1));
  if (map == NULL)
    {
      my_printf("Error : map too big !");
      exit(1);
    }
  while (buff[i] != '\n')
    {
      i++;
      *l = *l + 1;
    }
  while (j < nb_lines)
    {
      map[j] = malloc(sizeof(char) * (*l));
      put_error_malloc(map[j]);
      j++;
    }
  map[j] = malloc(sizeof(char) * 1);
  map[j][0] = '\0';
  return (map);
}

char	**init_map(char **map, char file[SIZE], int nb_lines, int i)
{
  int	j;
  int	k;
  int	l;

  l = 1;
  j = 0;
  k = 0;
  map = init_map2(file, i, &l, nb_lines);
  while (j < nb_lines)
    {
      while (file[i] != '\n')
	{
	  map[j][k] = file[i];
	  i++;
	  k++;
	}
      map[j][k] = '\0';
      i++;
      k = 0;
      j++;
    }
  return (map);
}

int	deter_nb_lines(char file[SIZE], int *i)
{
  char	*str;
  int	nb;

  str = malloc(sizeof(char) * 301);
  while (file[*i] != '\n' && file[*i] != '\0')
    {
      str[*i] = file[*i];
      *i = *i + 1;
    }
  str[*i] = '\0';
  nb = my_getnbr(str);
  if (nb <= 0)
    {
      my_printf("Error : invalid number of lines\n");
      exit(1);
    }
  *i = *i + 1;
  free(str);
  return (nb);
}

int	main(int ac, char **av)
{
  int	nb_lines;
  int	i;
  int	fd;
  int	r;
  char	buff[SIZE];
  char	**map;
  int	**tab;

  map = NULL;
  i = 0;
  check_error(ac, av);
  fd = open(av[1], O_RDONLY);
  r = read(fd, buff, SIZE);
  buff[r] = '\0';
  nb_lines = deter_nb_lines(buff, &i);
  map = init_map(map, buff, nb_lines, i);
  tab = init_tab(map, nb_lines);
  my_bsq(map, nb_lines, tab);
  disp_map(map);
  free(map);
  free(tab);
  close(fd);
  return (0);
}
