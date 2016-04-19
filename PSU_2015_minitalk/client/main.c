#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include "my.h"

void	check_error(int ac, char **av)
{
  int	i;

  i = 0;
  if (ac != 3)
    my_putstr_error("Usage : ./client [pid] [message]\n", 1);
  while (av[1][i])
    {
      if (av[1][i] < '0' || av[1][i] > '9')
	my_putstr_error("Err : pid invalid\n", 1);
      i++;
    }
  if (my_getnbr(av[1]) < 1)
    my_putstr_error("Err : pid invalid\n", 1);
}

void	transfer_msg(char *msg, int pid)
{
  int	i;

  i = 0;
  while (msg[i])
    {
      if (msg[i] == '0')
	{
	  if (kill(pid, SIGUSR1) == -1)
	    my_putstr_error("[ERROR] No process found\n", 1);
	}
      else if (msg[i] == '1')
	{
	  if (kill(pid, SIGUSR2) == -1)
	    my_putstr_error("[ERROR] No process found\n", 1);
	}
      else
	my_putstr_error("[ERROR] : msg contains not only 0 or 1\n", 1);
      i++;
      usleep(500);
    }
}

char	*convert_char(int nb)
{
  char	*res;
  int	i;

  if (nb > 255 || nb < 0)
    exit(1);
  res = malloc(sizeof(char) * 9);
  res[8] = 0;
  i = 7;
  while ((nb / 2) > 0)
    {
      res[i] = nb % 2 + 48;
      nb /= 2;
      i--;
    }
  res[i] = nb % 2 + 48;
  i--;
  while (i >= 0)
    {
      res[i] = '0';
      i--;
    }
  return (res);
}

void	convert_msg_bin(char *msg, int pid)
{
  char	*c_enc;
  int	i;

  i = 0;
  while (msg[i])
    {
      c_enc = convert_char((int)msg[i]);
      transfer_msg(c_enc, pid);
      usleep(1000);
      free(c_enc);
      i++;
    }
}

void	func()
{
  return ;
}

int	main(int ac, char **av)
{
  int	pid;

  signal(SIGUSR1, func);
  check_error(ac, av);
  pid = my_getnbr(av[1]);
  convert_msg_bin(av[2], pid);
  return (0);
}
