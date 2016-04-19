#include "main.h"

char	**realloc_env2(char **env, int l)
{
  int	i;
  char	**new;

  i = 0;
  if ((new = malloc(sizeof(char *) * l)) == NULL)
    exit(2);
  while (i < l - 1)
    {
      if ((new[i] = malloc(sizeof(char) * (my_strlen(env[i]) + 1))) == NULL)
	exit(2);
      if (i != l - 2)
	new[i] = my_strcpy(new[i], env[i]);
      i++;
    }
  return (new);
}

char	**realloc_env(char **env, int l)
{
  int	i;
  char	**new;

  i = 0;
  if ((new = malloc(sizeof(char *) * l)) == NULL)
    exit(2);
  while (i < l - 1)
    {
      if ((new[i] = malloc(sizeof(char) * (my_strlen(env[i]) + 1))) == NULL)
	exit(2);
      new[i] = my_strcpy(new[i], env[i]);
      i++;
    }
  return (new);
}
