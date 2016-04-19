#include "main.h"

char	**modif_env(char **env, int i, char *name, char *value)
{
  int	j;

  j = 0;
  if (!env[i])
    env = realloc_env2(env, i + 2);
  else
    while (env[i][j])
      env[i][j++] = 0;
  name = my_realloc(name, 1);
  j = 0;
  while (name[j])
    j++;
  name[j] = '=';
  name[++j] = 0;
  if (value)
    env[i] = my_strcat(name, value);
  else
    env[i] = name;
  return (env);
}

int	search_error2(char **com)
{
  int	i;

  i = -1;
  while (com[1][++i])
    if ((com[1][i] < '0' || (com[1][i] > '9' && com[1][i] < 'A')
	 || (com[1][i] > 'Z' && com[1][i] < 'a')
	 || com[1][i] > 'z') && com[1][i] != '_')
      {
	my_pute("setenv: Variable name must contain ");
	my_pute("alphanumeric characters.\n");
	return (1);
      }
  return (0);
}

int	search_error(char **com, char **env)
{
  int	i;

  i = 0;
  if (!com[1])
    {
      while (env[i])
	my_printf("%s\n", env[i++]);
      return (1);
    }
  if (com[1])
    if (com[2])
      if (com[3])
	{
	  my_pute("setenv: Too many arguments.\n");
	  return (1);
	}
  return (0);
}

char	**my_setenv(char **com, char **env)
{
  int	i;
  int	m;

  if (search_error(com, env) || search_error2(com))
    return (env);
  i = 0;
  m = 0;
  while (env[i] && m == 0)
    {
      if (my_strcmp(com[1], ret_name(env[i])))
	m = 1;
      i++;
    }
  if (m == 1)
    env = modif_env(env, --i, com[1], com[2]);
  else
    {
      i = 0;
      while (env[i])
	i++;
      env = modif_env(env, i, com[1], com[2]);
    }
  return (env);
}
