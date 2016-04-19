#include "main.h"

t_shell	add_slashes(t_shell sh)
{
  int	i;
  int	j;

  i = 0;
  j = 0;
  while (sh.path[i])
    {
      j = my_strlen(sh.path[i]) - 1;
      if (sh.path[i][j] != '/')
	{
	  sh.path[i] = my_realloc(sh.path[i], 1);
	  sh.path[i][++j] = '/';
	  sh.path[i][++j] = 0;
	}
      i++;
    }
  return (sh);
}

t_shell	deter_path(char **env, t_shell sh)
{
  int	i;
  int	j;
  int	k;
  char	*tmp;

  i = 0;
  j = 5;
  k = 0;
  while (env[i] != NULL && (env[i][0] != 'P' || env[i][1] != 'A' ||
			    env[i][2] != 'T' || env[i][3] != 'H' ||
			    env[i][4] != '='))
    i++;
  if ((sh.path = malloc(sizeof(char *) * 101)) == NULL)
    exit(2);
  sh.path[0] = NULL;
  if (env[i] == NULL)
    return (sh);
  if ((tmp = malloc(sizeof(char) * my_strlen(env[i]))) == NULL)
    exit(2);
  while (env[i][j])
    tmp[k++] = env[i][j++];
  tmp[k] = 0;
  sh.path = my_str_to_tab(tmp);
  sh = add_slashes(sh);
  return (sh);
}

t_shell	deter_user(char **env, t_shell sh)
{
  int	i;
  int	j;
  int	k;

  i = 0;
  j = 5;
  k = 0;
  while (env[i] != NULL && (env[i][0] != 'U' || env[i][1] != 'S' ||
			    env[i][2] != 'E' || env[i][3] != 'R' ||
			    env[i][4] != '='))
    i++;
  if (env[i] == NULL)
    {
      if ((sh.user = malloc(sizeof(char) * 2)) == NULL)
	exit(2);
      sh.user[0] = '$';
      sh.user[1] = 0;
      return (sh);
    }
  if ((sh.user = malloc(sizeof(char) * my_strlen(env[i]))) == NULL)
    exit(2);
  while (env[i][j])
    sh.user[k++] = env[i][j++];
  sh.user[k] = 0;
  return (sh);
}
