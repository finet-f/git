#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include <sys/types.h>
#include <signal.h>

char	*bin;

char	convert_bin_char(char *str)
{
  int	res;
  int	i;

  i = 0;
  while (str[i])
    {
      str[i] -= 48;
      i++;
    }
  res = (int)str[7] + (int)str[6] * 2 + (int)str[5] * 4 + (int)str[4] * 8;
  res = res + (int)str[3] * 16 + (int)str[2] * 32 + (int)str[1] * 64;
  res = res + (int)str[0] * 128;
  return ((char)res);
}

void	catch_sigusr1()
{
  int	i;

  i = 0;
  if (bin == NULL)
    {
      if ((bin = malloc(sizeof(char) * 9)) == NULL)
	exit(2);
      bin[0] = 0;
    }
  while (bin[i])
    i++;
  bin[i] = '0';
  bin[i + 1] = 0;
  if (i == 7)
    {
      my_putchar(convert_bin_char(bin));
      free(bin);
      bin = NULL;
    }
}

void	catch_sigusr2()
{
  int	i;

  i = 0;
  if (bin == NULL)
    {
      if ((bin = malloc(sizeof(char) * 9)) == NULL)
	exit(2);
      bin[0] = 0;
    }
  while (bin[i])
    i++;
  bin[i] = '1';
  bin[i + 1] = 0;
  if (i == 7)
    {
      my_putchar(convert_bin_char(bin));
      free(bin);
      bin = NULL;
    }
}

int	main()
{
  signal(SIGUSR1, catch_sigusr1);
  signal(SIGUSR2, catch_sigusr2);
  my_printf("%d\n", getpid());
  while (1);
  return (0);
}
