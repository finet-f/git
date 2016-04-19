#include "my.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "size.h"
#include "check_error.h"

void	check_error4(char buff[SIZE], int i, int c)
{
  int	t;

  t = 0;
  while (buff[i] != '\0')
    {
      while (buff[i] != '\n')
	{
	  t++;
	  i++;
	}
      if (t != c)
	my_putstr_error("Error : invalid file\n", 1);
      t = 0;
      i++;
    }
}

void	check_error3(char buff[SIZE])
{
  int	i;
  int	c;
  int	j;

  i = 0;
  c = 0;
  deter_nb_lines(buff, &i);
  j = i;
  while (buff[i] != '\n')
    {
      c++;
      i++;
    }
  i++;
  check_error4(buff, i, c);
  while (buff[j] != '\0')
    {
      if (buff[j] != '\n' && buff[j] != '.' && buff[j] != 'o')
	my_putstr_error("Error : invalid file\n", 1);
      j++;
    }
}

void	check_error2(char buff[SIZE])
{
  int	l;
  int	i;
  int	n;

  n = 0;
  i = 0;
  l = deter_nb_lines(buff, &i);
  while (buff[i] != '\0')
    {
      if (buff[i] == '\n')
	n++;
      i++;
    }
  if (l != n)
    my_putstr_error("Error : invalid file\n", 1);
}

void	check_error(int ac, char **av)
{
  int	fd;
  int	r;
  char	buff[SIZE];

  if (ac < 2)
    my_putstr_error("Usage : ./bsq file_name\n", 1);
  fd = open(av[1], O_RDONLY);
  if (fd == -1)
    my_putstr_error("Error : file does not exist\n", 1);
  r = read(fd, buff, SIZE);
  buff[r] = '\0';
  if (r == SIZE || r < 3)
    my_putstr_error("Error : invalid file\n", 1);
  check_error2(buff);
  check_error3(buff);
  close(fd);
}
