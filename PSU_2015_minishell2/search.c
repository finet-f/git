#include "main.h"

int	count_l(char **com, int i)
{
  int	n;

  while (com[i] && com[i][0] != '|')
    {
      i++;
      n++;
    }
  return (n);
}

t_pip	search_pipe(char **com)
{
  int	i;
  t_pip	pip;

  i = 0;
  pip.nb = 0;
  pip.nbcom = 0;
  while (com[i])
    {
      if (com[i][0] == '|')
	pip.nb++;
      else if (i == 0 || com[i - 1][0] == '|')
	pip.nbcom++;
      i++;
    }
  if (pip.nb > 0)
    if (pip.nbcom != 2 || pip.nb != 1)
      exit(0);
  return (pip);
}

t_cd	search_home(char **env, t_cd cd)
{
  int	i;

  i = 0;
  while (env[i] && (env[i][0] != 'H' || env[i][1] != 'O' || env[i][2] != 'M'
		    || env[i][3] != 'E' || env[i][4] != '='))
    i++;
  if (!env[i])
    {
      cd.home = NULL;
      return (cd);
    }
  cd.home = my_newstrcpy(env[i], 5, 0);
  cd.h = i;
  return (cd);
}

t_cd	searchenv(char **env, t_cd cd)
{
  int	i;

  i = 0;
  while (env[i] && (env[i][0] != 'O' || env[i][1] != 'L' || env[i][2] != 'D'
		    || env[i][3] != 'P' || env[i][4] != 'W' || env[i][5] != 'D'
		    || env[i][6] != '='))
    i++;
  if (!env[i])
    cd.opwd = NULL;
  else
    cd.opwd = my_newstrcpy(env[i], 7, 0);
  cd.o = i;
  i = 0;
  while (env[i] && (env[i][0] != 'P' || env[i][1] != 'W' || env[i][2] != 'D'
		    || env[i][3] != '='))
    i++;
  if (!env[i])
    cd.pwd = NULL;
  else
    cd.pwd = my_newstrcpy(env[i], 4, 0);
  cd.p = i;
  return (cd);
}
